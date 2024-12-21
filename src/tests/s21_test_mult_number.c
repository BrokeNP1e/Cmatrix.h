#include "tests.h"

START_TEST(s21_mult_number_1) {
  matrix_t A = {0};
  matrix_t RES = {0};
  matrix_t CHECK = {0};
  double multNumber = 2.5;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &CHECK);

  int return_val_mul = s21_mult_number(&A, multNumber, &RES);
  int return_value = s21_eq_matrix(&RES, &CHECK);

  ck_assert_int_eq(return_value, SUCCESS);
  ck_assert_int_eq(return_val_mul, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A = {0};
  matrix_t RES = {0};
  matrix_t CHECK = {0};
  double multNumber = 2.5;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &CHECK);

  CHECK.matrix[0][0] = 2.5;
  CHECK.matrix[0][1] = 2.5;
  CHECK.matrix[1][0] = 2.5;
  CHECK.matrix[1][1] = 2.5;

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;

  int return_val_mul = s21_mult_number(&A, multNumber, &RES);
  int return_value = s21_eq_matrix(&RES, &CHECK);

  ck_assert_int_eq(return_value, SUCCESS);
  ck_assert_int_eq(return_val_mul, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t A = {0};
  matrix_t RES = {0};

  s21_create_matrix(3, 3, &A);
  int return_val_mul = s21_mult_number(&A, NaN, &RES);

  ck_assert_int_eq(return_val_mul, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t A = {0};
  matrix_t RES = {0};
  double num = 2.0;

  s21_create_matrix(3, 3, &A);
  int return_val_mul = s21_mult_number(NULL, num, &RES);

  ck_assert_int_eq(return_val_mul, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(s21_mult_number_5) {
  matrix_t A = {0};
  matrix_t RES = {0};
  matrix_t CHECK = {0};
  double num = -25000;

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &CHECK);

  CHECK.matrix[0][0] = -25000;
  CHECK.matrix[0][1] = -25000;
  CHECK.matrix[1][0] = -25000;
  CHECK.matrix[1][1] = -25000;

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;

  int return_val_mul = s21_mult_number(&A, num, &RES);
  int return_value = s21_eq_matrix(&RES, &CHECK);

  ck_assert_int_eq(return_value, SUCCESS);
  ck_assert_int_eq(return_val_mul, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

Suite *test_mult_number() {
  Suite *s = suite_create("\033[45m\tS21_MULT_NUM\t\t\033[0m");
  TCase *o = tcase_create("s21_mult_number");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_mult_number_1);
  tcase_add_test(o, s21_mult_number_2);
  tcase_add_test(o, s21_mult_number_3);
  tcase_add_test(o, s21_mult_number_4);
  tcase_add_test(o, s21_mult_number_5);

  return s;
}