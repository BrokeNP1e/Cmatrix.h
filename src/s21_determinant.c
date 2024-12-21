#include "s21_matrix.h"

void s21_zeroing_matrix(matrix_t *result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0;
    }
  }
}

void s21_lowering_order(matrix_t A, matrix_t *result, int rows, int columns) {
  int count_rows = 0;
  for (int i = 0; i < A.rows; i++) {
    if (rows != i) {
      int count_columns = 0;
      for (int j = 0; j < A.columns; j++) {
        if (columns != j) {
          result->matrix[count_rows][count_columns] = A.matrix[i][j];
          count_columns++;
        }
      }
      count_rows++;
    }
  }
}

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (A == NULL || result == NULL) {
    error = 1;
  } else if (A->rows == A->columns && A->rows < 1) {
    error = 2;
  } else {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      *result = A->matrix[0][0] * A->matrix[1][1] -
                (A->matrix[1][0] * A->matrix[0][1]);
    } else {
      matrix_t temp_matrix = {0};
      s21_create_matrix((A->rows - 1), (A->rows - 1), &temp_matrix);
      for (int j = 0; j < A->columns; j++) {
        double temp_det = 0;
        s21_lowering_order(*A, &temp_matrix, 0, j);
        s21_determinant(&temp_matrix, &temp_det);
        *result += A->matrix[0][j] * (pow(-1, 2 + j) * temp_det);
        s21_zeroing_matrix(&temp_matrix);
      }
      s21_remove_matrix(&temp_matrix);
    }
  }
  return error;
}