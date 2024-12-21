#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = 0;
  if (A == NULL && B == NULL) {
    error = 2;
  } else if (A->rows == B->rows && A->columns == B->columns) {
    error = 1;
    for (int i = 0; i < A->rows && error == 1; i++) {
      for (int j = 0; j < A->columns && error == 1; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) < 1e-07) {
          error = 1;
        } else {
          error = 0;
        }
      }
    }
  }
  return error;
}