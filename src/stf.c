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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

#include "stf.h"

void stf_init_test_framework(stf_test_framework_t *p_framework) {
    p_framework->p_first_test = NULL;
    p_framework->p_last_test = NULL;
}

int stf_add_unit_test(stf_test_framework_t *p_framework, void (*p_func)(void *p_data)) {
    stf_unit_test_t *p_new_test;
    p_new_test = NULL;
    
    if (p_framework == NULL)
        return -1;

    p_new_test = (stf_unit_test_t *)malloc(sizeof(stf_unit_test_t));
    if (p_new_test == NULL) {
        return -2;
    }
    
    p_new_test->p_func = p_func;
    p_new_test->p_next = NULL;
    
    if ((p_framework->p_first_test == NULL) && (p_framework->p_last_test == NULL)) {
        // This is the first unit test in this framework
        p_framework->p_first_test = p_new_test;
        p_framework->p_last_test = p_new_test;
    } else {
        p_framework->p_last_test->p_next = p_new_test;
        p_framework->p_last_test = p_new_test;
    }
    
    return 0;
}

void stf_free_unit_test(stf_unit_test_t *p_test) {
    if (p_test != NULL) {
        free(p_test);
    }
}

void stf_free_test_framework(stf_test_framework_t *p_framework) {
    stf_unit_test_t *p_cur_test;
    stf_unit_test_t *p_prev_test;
    
    if (p_framework != NULL) {
        if ((p_framework->p_first_test == NULL) && (p_framework->p_last_test == NULL)) {
            p_cur_test = p_framework->p_first_test;
            while(p_cur_test != NULL) {
                p_prev_test = p_cur_test;
                p_cur_test = p_cur_test->p_next;
                stf_free_unit_test(p_prev_test);
            }
        }
    }
}

void stf_run_test_framework(stf_test_framework_t *p_framework, void *p_data) {
    stf_unit_test_t *p_cur_test;
    int success_count;
    success_count = 0;
    
    if (p_framework != NULL) {
        if ((p_framework->p_first_test != NULL) && (p_framework->p_last_test != NULL)) {
            p_cur_test = p_framework->p_first_test;
            while(p_cur_test != NULL) {
                (*(p_cur_test->p_func))(p_data);
                fprintf(stderr, ".");
                success_count += 1;
                p_cur_test = p_cur_test->p_next;
            }
            fprintf(stderr, "\n%d Tests Succeeded\n", success_count);
        }
    }
}