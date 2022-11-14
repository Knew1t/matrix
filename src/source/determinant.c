#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_value = OK;
  *result = 0;
  if (is_matrix_correct(*A) && (A->rows == A->columns)) {
    if (A->columns != 1) {
      for (int j = 0; j < A->columns; j++) {
        *result += pow(-1, 2 + j) * A->matrix[0][j] * calc_minor(0, j, A);
      }
    } else {
      *result = A->matrix[0][0];
    }
  } else if (A->rows != A->columns) {
    return_value = CALCULATION_ERROR;
  } else {
    return_value = INCORRECT_MATRIX_ERROR;
  }

  return return_value;
}
