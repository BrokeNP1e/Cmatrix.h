#ifndef MAT_TEST_H
#define MAT_TEST_H

#include <check.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#define SUCCESS 1
#define FAILURE 0

#define INCORRECT_MATRIX 1
#define CALCULATION_ERROR 2

#define OK 0
#define ERROR 1

#define INF 1.0 / 0.0
#define NaN 0.0 / 0.0

Suite *test_create_matrix(void);
Suite *test_remove_matrix(void);
Suite *test_eq_matrix(void);
Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);
Suite *test_mult_number(void);
Suite *test_mult_matrix(void);
Suite *test_transpose_matrix(void);
Suite *test_calc_complements_matrix(void);
Suite *test_determinant_matrix(void);
Suite *test_inverse_matrix(void);

#endif