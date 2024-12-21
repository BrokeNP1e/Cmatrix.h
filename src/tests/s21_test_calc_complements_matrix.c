#include "tests.h"

START_TEST(s21_calc_complements_1) {
  matrix_t A = {0}, ORIGIN_MATRIX = {0}, RES = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &ORIGIN_MATRIX);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  ORIGIN_MATRIX.matrix[0][0] = 4;
  ORIGIN_MATRIX.matrix[0][1] = -3;
  ORIGIN_MATRIX.matrix[1][0] = -2;
  ORIGIN_MATRIX.matrix[1][1] = 1;

  int return_num = s21_calc_complements(&A, &RES);
  int eq_value = s21_eq_matrix(&ORIGIN_MATRIX, &RES);

  ck_assert_int_eq(return_num, OK);
  ck_assert_int_eq(eq_value, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN_MATRIX);
  s21_remove_matrix(&RES);
}

START_TEST(s21_calc_complements_2) {
  matrix_t A = {0}, ORIGIN_MATRIX = {0}, RES = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &ORIGIN_MATRIX);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  ORIGIN_MATRIX.matrix[0][0] = 4;
  ORIGIN_MATRIX.matrix[0][1] = -3;
  ORIGIN_MATRIX.matrix[1][0] = -2;
  ORIGIN_MATRIX.matrix[1][1] = 1;

  int return_num = s21_calc_complements(&A, &RES);
  int eq_value = s21_eq_matrix(&ORIGIN_MATRIX, &RES);

  ck_assert_int_eq(return_num, OK);
  ck_assert_int_eq(eq_value, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&ORIGIN_MATRIX);
  s21_remove_matrix(&RES);
}

START_TEST(s21_calc_complements_3) {
  matrix_t RES = {0};

  int return_num = s21_calc_complements(NULL, &RES);

  ck_assert_int_eq(return_num, INCORRECT_MATRIX);
  s21_remove_matrix(&RES);
}

START_TEST(s21_calc_complements_4) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);

  int return_num = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(return_num, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
Suite *test_calc_complements_matrix() {
  Suite *s = suite_create("\033[45m\tS21_CALC_COMPLEMENTS\t\t\033[0m");
  TCase *o = tcase_create("s21_calc_complements_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_calc_complements_1);
  tcase_add_test(o, s21_calc_complements_2);
  tcase_add_test(o, s21_calc_complements_3);
  tcase_add_test(o, s21_calc_complements_4);

  return s;
}