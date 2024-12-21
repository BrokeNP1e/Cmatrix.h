#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A == NULL) {
    error = 1;
  } else {
    double det_A = 0;
    error = s21_determinant(A, &det_A);
    if (det_A != 0 && result != NULL) {
      matrix_t temp_B = {0};
      matrix_t temp_C = {0};
      error = s21_calc_complements(A, &temp_B);
      error = s21_transpose(&temp_B, &temp_C);
      error = s21_mult_number(&temp_C, (1 / det_A), result);
      s21_remove_matrix(&temp_B);
      s21_remove_matrix(&temp_C);
    } else {
      error = 2;
    }
  }
  return error;
}