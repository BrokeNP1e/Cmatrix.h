#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (result != NULL && rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows && error == 0; ++i) {
        result->matrix[i] = calloc(columns, sizeof(double));
      }
    } else {
      error = 1;
    }
  } else {
    error = 1;
  }

  return error;
}