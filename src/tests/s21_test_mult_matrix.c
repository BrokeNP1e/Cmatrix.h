#include "tests.h"

START_TEST(s21_mult_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RES = {0};
  matrix_t CHECK = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &CHECK);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 4;
  B.matrix[0][1] = 3;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 1;

  CHECK.matrix[0][0] = 8;
  CHECK.matrix[0][1] = 5;
  CHECK.matrix[1][0] = 20;
  CHECK.matrix[1][1] = 13;

  s21_mult_matrix(&A, &B, &RES);
  int return_num = s21_eq_matrix(&RES, &CHECK);
  ck_assert_int_eq(return_num, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RES = {0};
  matrix_t CHECK = {0};
  int value = 1;

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(3, 2, &B);
  s21_create_matrix(2, 2, &CHECK);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = value;
      B.matrix[j][i] = value;
      value++;
    }
  }

  CHECK.matrix[0][0] = 14;
  CHECK.matrix[0][1] = 32;
  CHECK.matrix[1][0] = 32;
  CHECK.matrix[1][1] = 77;

  s21_mult_matrix(&A, &B, &RES);
  int return_num = s21_eq_matrix(&RES, &CHECK);
  ck_assert_int_eq(return_num, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RES = {0};
  matrix_t CHECK = {0};
  int value = 1;

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &CHECK);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = value;
      B.matrix[j][i] = value;
      value++;
    }
  }

  CHECK.matrix[0][0] = 5;
  CHECK.matrix[0][1] = 11;
  CHECK.matrix[0][2] = 17;
  CHECK.matrix[1][0] = 11;
  CHECK.matrix[1][1] = 25;
  CHECK.matrix[1][2] = 39;
  CHECK.matrix[2][0] = 17;
  CHECK.matrix[2][1] = 39;
  CHECK.matrix[2][2] = 61;

  s21_mult_matrix(&A, &B, &RES);
  int return_num = s21_eq_matrix(&RES, &CHECK);
  ck_assert_int_eq(return_num, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RES = {0};

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 0, &B);

  int return_num = s21_mult_matrix(&A, &B, &RES);
  ck_assert_int_eq(return_num, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(s21_mult_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t RES = {0};

  s21_create_matrix(4, 1, &A);
  s21_create_matrix(4, 1, &B);

  int return_num = s21_mult_matrix(&A, &B, &RES);
  ck_assert_int_eq(return_num, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *test_mult_matrix() {
  Suite *s = suite_create("\033[45m\tS21_MULT_MATRIX\t\t\033[0m");
  TCase *o = tcase_create("s21_mult_matrix");
  suite_add_tcase(s, o);

  tcase_add_test(o, s21_mult_matrix_1);
  tcase_add_test(o, s21_mult_matrix_2);
  tcase_add_test(o, s21_mult_matrix_3);
  tcase_add_test(o, s21_mult_matrix_4);
  tcase_add_test(o, s21_mult_matrix_5);

  return s;
}