#include "helpers.h"

#include <stdio.h>
#include <time.h>

// matrix output
void print_matrix(matrix_t m) {
  for (int j = 0; j < m.rows; j++) {
    for (int i = 0; i < m.columns; i++) {
      printf("%2g ", m.matrix[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

int is_matrix_correct(matrix_t *m) {
  return m && m->rows > 0 && m->columns > 0;
}

/* calculates minor */
double calc_minor(int i, int j, matrix_t *A) {
  double result = 0;
  if (A->rows && A->columns > 1) {
    matrix_t lesser_matrix = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &lesser_matrix);
    fill_lesser_matrix(i, j, &lesser_matrix, A);
    if (lesser_matrix.rows == 2) {
      result = lesser_matrix.matrix[0][0] * lesser_matrix.matrix[1][1] -
               lesser_matrix.matrix[1][0] * lesser_matrix.matrix[0][1];
    } else {
      s21_determinant(&lesser_matrix, &result);
    }
    s21_remove_matrix(&lesser_matrix);
  } else {
    result = 1;
  }
  return result;
}

/* creates new matrix without selected lines */
void fill_lesser_matrix(int i, int j, matrix_t *lesser_matrix,
                        matrix_t *main_matrix) {
  int r_2 = 0, c_2 = 0;
  for (int r_1 = 0; r_1 < main_matrix->rows; r_1++) {
    for (int c_1 = 0; c_1 < main_matrix->columns; c_1++) {
      if (r_1 != i && c_1 != j) {
        lesser_matrix->matrix[r_2][c_2] = main_matrix->matrix[r_1][c_1];
        c_2++;
      }
    }
    if (r_1 != i) {
      r_2++;
      c_2 = 0;
    }
  }
}

/* fills matrix with numbers from 1 to matrix scale */
void fill_matrix(matrix_t *m) {
  int count = 1;
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->columns; j++) {
      m->matrix[i][j] = count++;
    }
  }
}

void fill_with_array_values(const double *m, matrix_t *A) {
  double *ptr = (double *)m;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = *(ptr++);
    }
  }
  /* for (size_t i = 0; i < array_size1; i++) { */
  /*   *(ptr + i) = m[i]; */
  /* } */
}

double get_rand(double min, double max) {
  double number = 0;
  double range = max - min;
  double div = max / range;
  number = min + (rand() / div);
  return number;
}

void initiate_matrix(matrix_t *m) {
  m->matrix = NULL;
  m->rows = 0;
  m->columns = 0;
}
