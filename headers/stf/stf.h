/*
 * Copyright 2008 Andrew De Ponte.
 *
 * This file is part of lib_stf.
 *
 * lib_stf is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or any
 * later version.
 * 
 * lib_stf is distributed in the hopes that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with lib_stf; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */
 
/**
 * @file stf.h
 * @brief This is a specifications file for the STF library's API.
 *
 * The stf.h file is a specifications file for the Spartan Test Framework
 * library's API.
 */

/**
 * @example example_test.c
 * This is an example of how to use the Spartan Test Framework library.
 */

#ifndef STF_H
#define STF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stf_export.h"
#include <assert.h>

typedef struct stf_unit_test {
    void (*p_func)(void *p_data);
    struct stf_unit_test *p_next;
} stf_unit_test_t;

/**
 * @typedef stf_test_framework_t
 * @brief A type representing a test framework.
 *
 * The stf_test_framework_t type is a type which represents a test framework.
 * A test framework in this case is simply a collection of unit tests.
 */
typedef struct stf_test_framework {
    struct stf_unit_test *p_first_test;
    struct stf_unit_test *p_last_test;
} stf_test_framework_t;

/**
 * @brief Initialize a test framework.
 *
 * The stf_init_test_framework() function initializes a test framework given
 * a pointer to a variable of type stf_test_framework_t. No framework
 * instance should be used without being initialized. Hence, this function
 * is required to be called on a test framework instance before that test
 * framework is ever passed to other functions. It also requires that if
 * a test framework instance is freed using stf_free_test_framework() that
 * the instance immediately be initialized again using
 * stf_init_test_framework().
 * @param p_framework Pointer to the test framework to initialize.
 */
STF_EXPORT void stf_init_test_framework(stf_test_framework_t *p_framework);

/**
 * @brief Add a unit test to a test framework.
 *
 * The stf_add_unit_test() function adds a unit to a previously initialized
 * test framework given a pointer to the test framework and a pointer to
 * function that implements the unit test. The test framework should have
 * been initialized using the stf_init_test_framework() function.
 * @param p_framework Pointer to the test framework to add unit test to.
 * @param p_func Pointer to the function implementing the unit test.
 * @return An integer representing success (zero) or failure (non-zero).
 * @retval 0 Successfully added the unit test to the test framework.
 * @retval -1 p_framework, the pointer to the test framework was NULL.
 * @retval -2 Failed to allocate memory for unit test in test framework.
 */
STF_EXPORT int stf_add_unit_test(stf_test_framework_t *p_framework, void (*p_func)(void *p_data));

/**
 * @brief Free a test framework.
 *
 * The stf_free_test_framework() function frees all memory that was
 * dynamically allocated for the given test framework. Note: After freeing a
 * test framework one is required to re-initialize the framework using the
 * stf_init_test_framework() function.
 * @param p_framework Pointer to the test framework to free.
 */
STF_EXPORT void stf_free_test_framework(stf_test_framework_t *p_framework);

/**
 * @brief Run all tests in a test framework.
 *
 * The stf_run_test_framework() function sequentially runs each unit test in
 * the provided framework, in the sequence the unit tests were added to the
 * test framework. This function must be given the pointer to the test
 * framework to run the tests from as well as a pointer to any data that
 * should be available in each of the unit test functions. This is NULL if
 * no data needs to be available to each of unit test functions. However, if
 * shared data does need to be available to each of the unit test functions
 * it is general practice to create a struct that contains all the data that
 * needs to be shared and then create an instance of that struct and pass
 * the address of that structure as 'p_data'. Then in the unit test functions
 * you must create a pointer of your shared data structure and assign it
 * the value of p_data type casted to a pointer to your shared data struct.
 * @param p_framework Pointer to the test framework to run unit tests from.
 * @param p_data Pointer to data that should be available in each unit test.
 */
STF_EXPORT void stf_run_test_framework(const stf_test_framework_t *p_framework, void *p_data);


STF_EXPORT void _stf_free_unit_test(stf_unit_test_t *p_test);

#ifdef __cplusplus
}
#endif

#endif
