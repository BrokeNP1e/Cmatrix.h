#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A == NULL) {
    error = 1;
  } else {
    if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      for (int i = 0; i < A->rows; i++) {
        matrix_t temp_matrix = {0};
        s21_create_matrix((A->rows - 1), (A->rows - 1), &temp_matrix);
        for (int j = 0; j < A->columns; j++) {
          double temp_det = 0;
          s21_lowering_order(*A, &temp_matrix, i, j);
          error = s21_determinant(&temp_matrix, &temp_det);
          result->matrix[i][j] = temp_det * pow(-1, i + j);
          s21_zeroing_matrix(&temp_matrix);
        }
        s21_remove_matrix(&temp_matrix);
      }
    } else {
      error = 2;
      s21_remove_matrix(result);
    }
  }
  return error;
}