#include "tests.h"

START_TEST(s21_sub_matrix_1) {
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

  int res = s21_sub_matrix(&A, &B, &C);
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

START_TEST(s21_sub_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);

  int res = s21_sub_matrix(&A, &B, &C);

  R.matrix[0][0] = 0;
  R.matrix[0][1] = 0;
  R.matrix[1][0] = 0;
  R.matrix[1][1] = 0;

  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
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

  int res = s21_sub_matrix(&A, &B, &C);
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

START_TEST(s21_sub_matrix_4) {
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

  int res = s21_sub_matrix(&A, &B, &C);
  R.matrix[0][0] = -2;
  R.matrix[0][1] = -4;
  R.matrix[1][0] = -6;
  R.matrix[1][1] = -8;

  ck_assert_int_eq(OK, res);
  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
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

  int res = s21_sub_matrix(&A, &B, &C);
  R.matrix[0][0] = 1;
  R.matrix[0][1] = 12;
  R.matrix[1][0] = 7;
  R.matrix[1][1] = -16;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
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

  int res = s21_sub_matrix(&A, &B, &C);
  R.matrix[0][0] = 0.8766;
  R.matrix[0][1] = 11.7866;
  R.matrix[1][0] = 6.3211;
  R.matrix[1][1] = -16.05;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_7) {
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

  int res = s21_sub_matrix(&A, &B, &C);
  R.matrix[0][0] = 0.876589;
  R.matrix[0][1] = 11.7866;
  R.matrix[1][0] = 6.3211;
  R.matrix[1][1] = -16.05;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_8) {
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

  int res = s21_sub_matrix(&A, &B, &C);
  R.matrix[0][0] = 2.1234634;
  R.matrix[0][1] = 14.1235436;
  R.matrix[1][0] = 10.1346646;
  R.matrix[1][1] = -12.987654;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_9) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &R);
  A.matrix[0][0] = -1.1234;
  A.matrix[0][1] = -8.8532;
  A.matrix[1][0] = -9.1234;
  A.matrix[1][1] = 783415;

  B.matrix[0][0] = 2.1234;
  B.matrix[0][1] = 14.1235;
  B.matrix[1][0] = 10.1346;
  B.matrix[1][1] = 12.9876;

  int res = s21_sub_matrix(&A, &B, &C);
  R.matrix[0][0] = -3.2468;
  R.matrix[0][1] = -22.9767;
  R.matrix[1][0] = -19.2580;
  R.matrix[1][1] = 783402.0124;

  ck_assert_float_eq(SUCCESS, s21_eq_matrix(&C, &R));
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_sub_matrix_10) {
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

  int res = s21_sub_matrix(&A, &B, &C);

  ck_assert_int_eq(CALCULATION_ERROR, res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&C);
}
END_TEST

Suite *test_sub_matrix() {
  Suite *s = suite_create("\033[45m\tS21_SUB\t\t\033[0m");
  TCase *o = tcase_create("s21_sub_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_sub_matrix_1);
  tcase_add_test(o, s21_sub_matrix_2);
  tcase_add_test(o, s21_sub_matrix_3);
  tcase_add_test(o, s21_sub_matrix_4);
  tcase_add_test(o, s21_sub_matrix_5);
  tcase_add_test(o, s21_sub_matrix_6);
  tcase_add_test(o, s21_sub_matrix_7);
  tcase_add_test(o, s21_sub_matrix_8);
  tcase_add_test(o, s21_sub_matrix_9);
  tcase_add_test(o, s21_sub_matrix_10);

  return s;
}