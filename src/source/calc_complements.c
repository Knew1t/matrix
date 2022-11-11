#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  if (is_matrix_correct(*A) && (A->rows == A->columns)) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = pow(-1, 2 + i + j) * calc_minor(i, j, A);
      }
    }
  } else {
    return_value = INCORRECT_MATRIX_ERROR;
  }
  return return_value;
}
