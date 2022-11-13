#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;
  initiate_matrix(result);
  if (rows > 0 && columns > 0) {
    int matrix_size = rows * columns;
    result->rows = rows;
    result->columns = columns;
    double **m =
        calloc(1, sizeof(double) * matrix_size + sizeof(double *) * rows);
    /* double **m = malloc(sizeof(double) * matrix_size + sizeof(double *) *
     * rows); */
    if (m != NULL) {
      double *ptr = (double *)(m + rows);
      for (int i = 0; i < rows; i++) {
        m[i] = ptr + columns * i;
      }
      /* memset(m + rows, 0, matrix_size * (sizeof(double))); */
      result->matrix = m;
    } else {
      error = INCORRECT_MATRIX_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX_ERROR;
  }
  return error;
}
