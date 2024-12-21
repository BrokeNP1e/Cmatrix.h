#include "s21_matrix.h"

void s21_calculation(matrix_t *A, matrix_t *B, matrix_t *result, int code,
                     double number, int i, int j) {
  if (code == 0) {
    result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  } else if (code == 1) {
    result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  } else if (code == 2) {
    result->matrix[i][j] = A->matrix[i][j] * number;
  } else if (code == 3) {
    result->matrix[i][j] = 0;
    for (int k = 0; k < A->columns; k++) {
      result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
    }
  }
}

int s21_arith_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int code,
                     double number) {
  int error = 0;
  if (A == NULL || B == NULL) {
    error = 1;
  } else if (((A->rows != B->rows || A->columns != B->columns) && code != 3) ||
             (code == 3 && (A->columns != B->rows)) ||
             (isnan(number) || isinf(number))) {
    error = 2;
  } else {
    if (s21_create_matrix(A->rows, B->columns, result) == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          s21_calculation(A, B, result, code, number, i, j);
        }
      }
    } else {
      error = 2;
      s21_remove_matrix(result);
    }
  }
  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_arith_matrix(A, B, result, 0, 0.0);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_arith_matrix(A, B, result, 1, 0.0);
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  return s21_arith_matrix(A, A, result, 2, number);
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_arith_matrix(A, B, result, 3, 0.0);
}