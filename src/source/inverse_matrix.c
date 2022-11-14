#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  double determinant = 0;
  if (A->rows == A->columns) {
    if (is_matrix_correct(A) && result != NULL) {
      if (A->rows == 1 && A->columns == 1) {
        if (A->matrix[0][0] != 0) {
          s21_create_matrix(A->rows, A->columns, result);
          result->matrix[0][0] = 1 / A->matrix[0][0];
        } else {
          return_value = CALCULATION_ERROR;
        }
      } else {
        s21_determinant(A, &determinant);
        if (determinant != 0) {
          matrix_t complemented;
          matrix_t transposed;

          s21_calc_complements(A, &complemented);
          s21_transpose(&complemented, &transposed);
          s21_mult_number(&transposed, 1.0 / determinant, result);

          s21_remove_matrix(&complemented);
          s21_remove_matrix(&transposed);
        } else {
          return_value = CALCULATION_ERROR;
        }
      }
    } else {
      return_value = INCORRECT_MATRIX_ERROR;
    }
  } else {
    return_value = CALCULATION_ERROR;
  }
  return return_value;
}
