#include "tests.h"

START_TEST(s21_transpose_matrix_1) {
  matrix_t A = {0}, RES = {0}, CHECK = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  CHECK.matrix[0][0] = 1;
  CHECK.matrix[0][1] = 2;
  CHECK.matrix[0][2] = 3;
  CHECK.matrix[1][0] = 4;
  CHECK.matrix[1][1] = 5;
  CHECK.matrix[1][2] = 6;

  ck_assert_int_eq(s21_transpose(&A, &RES), 0);
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(s21_transpose_matrix_2) {
  matrix_t A = {0}, RES = {0}, CHECK = {0};
  s21_create_matrix(8, 15, &A);
  s21_create_matrix(15, 8, &CHECK);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i;
    }
  }
  for (int i = 0; i < CHECK.rows; i++) {
    for (int j = 0; j < CHECK.columns; j++) {
      CHECK.matrix[i][j] = j;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &RES), 0);
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(s21_transpose_matrix_3) {
  matrix_t A = {0}, RES = {0};

  s21_create_matrix(4, 7, &A);
  int check = s21_transpose(&A, &RES);

  ck_assert_uint_eq(check, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(s21_transpose_matrix_4) {
  matrix_t A = {0}, RES = {0};

  s21_create_matrix(4, 7, &A);
  int check = s21_transpose(&A, NULL);

  ck_assert_uint_eq(check, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *test_transpose_matrix() {
  Suite *s = suite_create("\033[45m\tS21_TRANSPONSE\t\t\033[0m");
  TCase *o = tcase_create("s21_transpose_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_transpose_matrix_1);
  tcase_add_test(o, s21_transpose_matrix_2);
  tcase_add_test(o, s21_transpose_matrix_3);
  tcase_add_test(o, s21_transpose_matrix_4);

  return s;
}