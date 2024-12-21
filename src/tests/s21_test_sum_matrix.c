#include "tests.h"

START_TEST(s21_sum_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 2;
  R.matrix[1][0] = 3;
  R.matrix[1][1] = 4;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);

  res = s21_sum_matrix(&A, &B, &C);

  R.matrix[0][0] = 0;
  R.matrix[0][1] = 0;
  R.matrix[1][0] = 0;
  R.matrix[1][1] = 0;

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = -4;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 0;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = -1;
  R.matrix[0][1] = -2;
  R.matrix[1][0] = -3;
  R.matrix[1][1] = -4;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = -4;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = 0;
  R.matrix[0][1] = 0;
  R.matrix[1][0] = 0;
  R.matrix[1][1] = 0;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = -3;
  A.matrix[1][1] = -4;

  B.matrix[0][0] = -2;
  B.matrix[0][1] = -14;
  B.matrix[1][0] = -10;
  B.matrix[1][1] = 12;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = -3;
  R.matrix[0][1] = -16;
  R.matrix[1][0] = -13;
  R.matrix[1][1] = 8;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1.1234;
  A.matrix[0][1] = -2.2134;
  A.matrix[1][0] = -3.6789;
  A.matrix[1][1] = -4.0500;

  B.matrix[0][0] = -2;
  B.matrix[0][1] = -14;
  B.matrix[1][0] = -10;
  B.matrix[1][1] = 12;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = -3.1234;
  R.matrix[0][1] = -16.2134;
  R.matrix[1][0] = -13.6789;
  R.matrix[1][1] = 7.9500;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1.123411;
  A.matrix[0][1] = -2.2134;
  A.matrix[1][0] = -3.6789;
  A.matrix[1][1] = -4.0500;

  B.matrix[0][0] = -2;
  B.matrix[0][1] = -14;
  B.matrix[1][0] = -10;
  B.matrix[1][1] = 12;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = -3.123411;
  R.matrix[0][1] = -16.2134;
  R.matrix[1][0] = -13.6789;
  R.matrix[1][1] = 7.9500;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;

  B.matrix[0][0] = -2.1234634;
  B.matrix[0][1] = -14.1235436;
  B.matrix[1][0] = -10.1346646;
  B.matrix[1][1] = 12.987654;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = -2.1234634;
  R.matrix[0][1] = -14.1235436;
  R.matrix[1][0] = -10.1346646;
  R.matrix[1][1] = 12.987654;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_9) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1.1234;
  A.matrix[0][1] = -8.8532;
  A.matrix[1][0] = -9.123426537;
  A.matrix[1][1] = 783415;

  B.matrix[0][0] = 2.1234634;
  B.matrix[0][1] = 14.1235436;
  B.matrix[1][0] = 10.1346646;
  B.matrix[1][1] = 12.987654;

  int res = s21_sum_matrix(&A, &B, &C);
  R.matrix[0][0] = 1.0000634;
  R.matrix[0][1] = 5.2703436;
  R.matrix[1][0] = 1.011238063;
  R.matrix[1][1] = 783427.987654;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sum_matrix_10) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1.1234;
  A.matrix[0][1] = -8.8532;
  A.matrix[1][0] = -9.123426537;
  A.matrix[1][1] = 783415;

  B.matrix[0][0] = 2.1234634;

  int res = s21_sum_matrix(&A, &B, &C);

  ck_assert_int_eq(CALCULATION_ERROR, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

Suite *test_sum_matrix() {
  Suite *s = suite_create("\033[45m\tS21_SUM\t\t\033[0m");
  TCase *o = tcase_create("s21_sum_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_sum_matrix_1);
  tcase_add_test(o, s21_sum_matrix_2);
  tcase_add_test(o, s21_sum_matrix_3);
  tcase_add_test(o, s21_sum_matrix_4);
  tcase_add_test(o, s21_sum_matrix_5);
  tcase_add_test(o, s21_sum_matrix_6);
  tcase_add_test(o, s21_sum_matrix_7);
  tcase_add_test(o, s21_sum_matrix_8);
  tcase_add_test(o, s21_sum_matrix_9);
  tcase_add_test(o, s21_sum_matrix_10);

  return s;
}