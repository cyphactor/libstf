/*
 * Copyright 2008 Blackbridge Software, LLC.
 *
 * This file is part of lib_stf.
 *
 * lib_stf is the intellectual property of Blackbridge Software, LLC; any
 * distribution and/or modifications and/or reproductions of any portion of
 * lib_stf MUST be approved in writing by Blackbridge Software, LLC.
 *
 * lib_stf is dirstributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef STF_H
#define STF_H

#include <assert.h>

struct stf_unit_test {
    void (*p_func)(void *p_data);
    struct stf_unit_test *p_next;
};
typedef struct stf_unit_test stf_unit_test_t;

struct stf_test_framework {
    struct stf_unit_test *p_first_test;
    struct stf_unit_test *p_last_test;
};
typedef struct stf_test_framework stf_test_framework_t;

void stf_init_test_framework(stf_test_framework_t *p_framework);
int stf_add_unit_test(stf_test_framework_t *p_framework, void (*p_func)(void *p_data));
void stf_free_unit_test(stf_unit_test_t *p_test);
void stf_free_test_framework(stf_test_framework_t *p_framework);
void stf_run_test_framework(stf_test_framework_t *p_framework, void *p_data);

#endif