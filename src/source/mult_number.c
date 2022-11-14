#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_value = OK;
  if (result != NULL && is_matrix_correct(*A)) {
    s21_create_matrix(A->rows, A->columns, result);
    if (isfinite(number) && !isnan(number)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      return_value = CALCULATION_ERROR;
    }
  } else {
    return_value = CALCULATION_ERROR;
  }

  return return_value;
}
