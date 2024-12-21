#include "tests.h"

START_TEST(s21_remove_matrix_1) {
  matrix_t A = {0};
  s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  matrix_t A = {0};
  s21_create_matrix(0, 0, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

Suite *test_remove_matrix() {
  Suite *s = suite_create("\033[45m\tS21_REMOVE_MATRIX\t\t\033[0m");
  TCase *o = tcase_create("s21_remove_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_remove_matrix_1);
  tcase_add_test(o, s21_remove_matrix_2);

  return s;
}