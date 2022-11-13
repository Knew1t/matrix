#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_value = OK;
  matrix_t end_result = {0};
  if (result != NULL && is_matrix_correct(*A)) {
    s21_create_matrix(A->rows, A->columns, result);
    double *ptr_a = (double *)((A->matrix) + A->rows);
    double *ptr_result = (double *)((result->matrix) + result->rows);
    if (isfinite(number) && !isnan(number)) {
      for (int i = 0; i < A->rows * A->columns; i++) {
        *(ptr_result + i) = *(ptr_a + i) * number;
      }
    } else {
      return_value = CALCULATION_ERROR;
    }
  } else {
    return_value = CALCULATION_ERROR;
    s21_remove_matrix(&end_result);
  }

  return return_value;
}
