#include "../core/helpers.h"
#include "../s21_matrix.h"
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = OK;
  if (result != NULL && is_matrix_correct(*A) && is_matrix_correct(*B)) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      double **C = result->matrix;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          C[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            C[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      return_value = CALCULATION_ERROR;
    }
  } else {
    return_value = INCORRECT_MATRIX_ERROR;
  }
  return return_value;
}
