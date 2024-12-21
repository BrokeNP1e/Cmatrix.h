#include "tests.h"

START_TEST(s21_inverse_1) {
  matrix_t A = {0}, ORIGIN_MATRIX = {0}, RES = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &ORIGIN_MATRIX);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  ORIGIN_MATRIX.matrix[0][0] = -2;
  ORIGIN_MATRIX.matrix[0][1] = 1;
  ORIGIN_MATRIX.matrix[1][0] = 1.5;
  ORIGIN_MATRIX.matrix[1][1] = -0.5;

  int return_num = s21_inverse_matrix(&A, &RES);
  int eq_value = s21_eq_matrix(&ORIGIN_MATRIX, &RES);

  ck_assert_int_eq(return_num, OK);
  ck_assert_int_eq(eq_value, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN_MATRIX);
  s21_remove_matrix(&RES);
}

START_TEST(s21_inverse_2) {
  matrix_t A = {0}, RES = {0}, ORIGINAL_MATRIX = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &ORIGINAL_MATRIX);
  ORIGINAL_MATRIX.matrix[0][0] = 44300.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[0][1] = -236300.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[0][2] = 200360.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[1][0] = 20600.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[1][1] = 56000.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[1][2] = -156483.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[2][0] = 30900.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[2][1] = 84000.0 / 367429.0;
  ORIGINAL_MATRIX.matrix[2][2] = -51010.0 / 367429.0;
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;

  int return_num = s21_inverse_matrix(&A, &RES);
  int res = s21_eq_matrix(&RES, &ORIGINAL_MATRIX);

  ck_assert_int_eq(return_num, OK);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&ORIGINAL_MATRIX);
}
END_TEST

START_TEST(s21_inverse_3) {
  matrix_t RES = {0};

  int return_num = s21_inverse_matrix(NULL, &RES);

  ck_assert_int_eq(return_num, INCORRECT_MATRIX);

  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(s21_inverse_4) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);

  int return_num = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(return_num, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *test_inverse_matrix() {
  Suite *s = suite_create("\033[45m\tS21_INVERSE\t\t\033[0m");
  TCase *o = tcase_create("s21_inverse_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_inverse_1);
  tcase_add_test(o, s21_inverse_2);
  tcase_add_test(o, s21_inverse_3);
  tcase_add_test(o, s21_inverse_4);

  return s;
}