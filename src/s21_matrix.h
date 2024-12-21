#ifndef C6_S21_MATRIX_1_S21_MATRIX_H
#define C6_S21_MATRIX_1_S21_MATRIX_H

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

void s21_calculation(matrix_t *A, matrix_t *B, matrix_t *result, int code,
                     double number, int i, int j);
int s21_arith_matrix(matrix_t *A, matrix_t *B, matrix_t *result, int code,
                     double number);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

void s21_zeroing_matrix(matrix_t *result);
void s21_lowering_order(matrix_t A, matrix_t *result, int rows, int columns);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // C6_S21_MATRIX_1_S21_MATRIX_H
