#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  double determinant = 0;
  if (is_matrix_correct(*A) && result != NULL) {
    if (A->rows == 1 && A->columns == 1) {
      if (A->matrix[0][0] != 0) {  // determinant = 0;
        s21_create_matrix(A->rows, A->columns, result);
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        return_value = CALCULATION_ERROR;
      }
    } else {
      s21_determinant(A, &determinant);
      if (determinant != 0 && (A->rows == A->columns)) {
        matrix_t tmp_result = {0};
        s21_calc_complements(A, &tmp_result);
        s21_transpose(&tmp_result, &tmp_result);
        s21_mult_number(&tmp_result, 1.0 / determinant, &tmp_result);
        *result = tmp_result;
      } else {
        return_value = CALCULATION_ERROR;
      }
    }
  } else {
    return_value = INCORRECT_MATRIX_ERROR;
  }
  return return_value;
}
