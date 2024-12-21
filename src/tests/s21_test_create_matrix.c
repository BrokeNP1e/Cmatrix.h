#include "tests.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(result, ERROR);
  s21_remove_matrix(&A);
}

END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(result, OK);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(INF, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(1, INF, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(1, NaN, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(NaN, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(result, ERROR);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(0, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(result, ERROR);
}

START_TEST(s21_create_matrix_8) {
  matrix_t A = {NULL, 0, 0};
  int result = s21_create_matrix(1, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(result, ERROR);
}

Suite *test_create_matrix() {
  Suite *s = suite_create("\033[45m\tS21_CREATE_MATRIX\t\t\033[0m");
  TCase *o = tcase_create("s21_create_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_create_matrix_1);
  tcase_add_test(o, s21_create_matrix_2);
  tcase_add_test(o, s21_create_matrix_3);
  tcase_add_test(o, s21_create_matrix_4);
  tcase_add_test(o, s21_create_matrix_5);
  tcase_add_test(o, s21_create_matrix_6);
  tcase_add_test(o, s21_create_matrix_7);
  tcase_add_test(o, s21_create_matrix_8);

  return s;
}