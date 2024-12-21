#include "tests.h"

START_TEST(s21_determ_matrix_1) {
  matrix_t A = {0};
  double determ_value = 0;
  double original_det = -2;

  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int return_num = s21_determinant(&A, &determ_value);

  ck_assert_double_eq(determ_value, original_det);
  ck_assert_int_eq(return_num, OK);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_2) {
  matrix_t A = {0};
  double determ_value = 0;
  double original_det = 0;

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 8;

  int return_num = s21_determinant(&A, &determ_value);

  ck_assert_double_eq(determ_value, original_det);
  ck_assert_int_eq(return_num, OK);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_3) {
  matrix_t A = {0};
  double determ_value = 0;
  double original_det = 36.7429;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;

  int return_num = s21_determinant(&A, &determ_value);

  ck_assert_double_eq_tol(determ_value, original_det, 1e-07);
  ck_assert_int_eq(return_num, OK);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_4) {
  matrix_t A = {0};
  double determ_value = 0;
  double original_det = 256;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 4;
  A.matrix[0][1] = 6;
  A.matrix[0][2] = 8;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 10;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 56;

  int return_num = s21_determinant(&A, &determ_value);

  ck_assert_double_eq(determ_value, original_det);
  ck_assert_int_eq(return_num, OK);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_5) {
  matrix_t A = {0};
  double determ_value = 0;
  double original_det = -3267;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 1;

  A.matrix[1][0] = 45;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 99;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 3;

  A.matrix[3][0] = 4;
  A.matrix[3][1] = 56;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 3;

  int return_num = s21_determinant(&A, &determ_value);

  ck_assert_double_eq_tol(determ_value, original_det, 1e-07);
  ck_assert_int_eq(return_num, OK);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_6) {
  matrix_t A = {0};
  double determ_value = 0;
  double original_det = 236.706;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.1;
  A.matrix[1][0] = -1.3;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.1;
  A.matrix[2][0] = 10.1;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;

  int return_num = s21_determinant(&A, &determ_value);

  ck_assert_double_eq_tol(determ_value, original_det, 1e-07);
  ck_assert_int_eq(return_num, OK);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_7) {
  matrix_t A = {0};
  double determ_value = 0;
  double original_det = 1602;
  s21_create_matrix(4, 4, &A);

  A.matrix[0][1] = 4;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 1;

  A.matrix[1][0] = 45;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 99;

  A.matrix[2][0] = 2;
  A.matrix[2][1] = 1;
  A.matrix[2][3] = 3;

  A.matrix[3][0] = 4;
  A.matrix[3][1] = 56;
  A.matrix[3][2] = 2;

  A.matrix[0][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[2][2] = 0;
  A.matrix[3][3] = 0;

  int return_num = s21_determinant(&A, &determ_value);

  ck_assert_double_eq_tol(determ_value, original_det, 1e-07);
  ck_assert_int_eq(return_num, OK);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_8) {
  matrix_t A = {0};
  double determ_value = 0;
  int return_num = s21_determinant(NULL, &determ_value);

  ck_assert_int_eq(return_num, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}

START_TEST(s21_determ_matrix_9) {
  matrix_t A = {0};

  int return_num = s21_determinant(&A, NULL);

  ck_assert_int_eq(return_num, ERROR);

  s21_remove_matrix(&A);
}
Suite *test_determinant_matrix() {
  Suite *s = suite_create("\033[45m\tS21_DETERM_MATRIX\t\t\033[0m");
  TCase *o = tcase_create("s21_determ_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_determ_matrix_1);
  tcase_add_test(o, s21_determ_matrix_2);
  tcase_add_test(o, s21_determ_matrix_3);
  tcase_add_test(o, s21_determ_matrix_4);
  tcase_add_test(o, s21_determ_matrix_5);
  tcase_add_test(o, s21_determ_matrix_6);
  tcase_add_test(o, s21_determ_matrix_7);
  tcase_add_test(o, s21_determ_matrix_8);
  tcase_add_test(o, s21_determ_matrix_9);

  return s;
}