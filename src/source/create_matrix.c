#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;
  initiate_matrix(result);
  if (rows > 0 && columns > 0) {
    int matrix_size = rows * columns;
    result->rows = rows;
    result->columns = columns;
    double **m = (double **)malloc(sizeof(double) * matrix_size +
                                   sizeof(double *) * rows);
    if (m != NULL) {
      double *ptr = (double *)(m + rows);
      for (int i = 0; i < rows; i++) {
        m[i] = ptr + columns * i;
      }
      result->matrix = m;
    } else {
      error = INCORRECT_MATRIX_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX_ERROR;
  }
  return error;
}
