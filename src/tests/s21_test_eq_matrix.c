
#include "tests.h"

START_TEST(s21_eq_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  }

  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 1, &B);

  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(5, 2, &A);
  s21_create_matrix(2, 2, &B);
  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(3, 1, &A);
  s21_create_matrix(1, 3, &B);

  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(4, 1, &A);
  s21_create_matrix(1, 4, &B);

  int result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *test_eq_matrix() {
  Suite *s = suite_create("\033[45m\tS21_EQ_MATRIX\t\t\033[0m");
  TCase *o = tcase_create("s21_create_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_eq_matrix_1);
  tcase_add_test(o, s21_eq_matrix_2);
  tcase_add_test(o, s21_eq_matrix_3);
  tcase_add_test(o, s21_eq_matrix_4);
  tcase_add_test(o, s21_eq_matrix_5);
  tcase_add_test(o, s21_eq_matrix_6);

  return s;
}