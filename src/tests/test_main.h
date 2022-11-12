#ifndef _TEST_MAIN_H
#define _TEST_MAIN_H

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../core/helpers.h"
#include "../s21_matrix.h"

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])

Suite *determinant_suite(void);
Suite *calc_complements_suite(void);
Suite *create_matrix_suite(void);
Suite *transpose_matrix_suite(void);
Suite *eq_matrix_suite(void);
Suite *sum_matrix_suite(void);
Suite *calc_complements_suite(void);
Suite *mult_matrix_suite(void);
Suite *mult_number_suite(void);
Suite *sub_matrix_suite(void);
Suite *remove_matrix_suite(void);
Suite *inverse_matrix_suite(void);

#endif  // _TEST_MAIN_H
