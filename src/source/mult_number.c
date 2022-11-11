#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_value = OK;
  matrix_t end_result = {0};
  if (result != NULL && is_matrix_correct(*A)) {
    s21_create_matrix(A->rows, A->columns, &end_result);
    double *ptr_a = (double *)((A->matrix) + A->rows);
    double *ptr_end_result = (double *)((end_result.matrix) + end_result.rows);
    double *ptr_result = (double *)((result->matrix) + result->rows);
    if (isfinite(number) && !isnan(number)) {
      int i = 0;
      while ((i < A->rows * A->columns)) {
        *(ptr_end_result + i) = *(ptr_a + i) * number;
        if (A->matrix == result->matrix) {
          *(ptr_result + i) = *(ptr_end_result + i);
        }
        i++;
      }
      if (A->matrix == result->matrix) {
        s21_remove_matrix(&end_result);
      } else {
        *result = end_result;
      }
    } else {
      return_value = CALCULATION_ERROR;
      s21_remove_matrix(&end_result);
    }
  } else {
    return_value = INCORRECT_MATRIX_ERROR;
  }

  return return_value;
}
