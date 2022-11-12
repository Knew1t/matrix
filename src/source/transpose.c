#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_value = OK;
  if (is_matrix_correct(*A) && result != NULL) {
    matrix_t end_result = {0};
    s21_create_matrix(A->columns, A->rows, &end_result);
    double *ptr_result = (double *)(end_result.matrix + end_result.rows);
    for (int j = 0; j < A->columns; j++) {
      for (int k = 0; k < A->rows; k++) {
        *(ptr_result) = A->matrix[k][j];
        ptr_result++;
      }
    }
    if (A == result) {
      ptr_result = (double *)(end_result.matrix + end_result.rows);
      double *ptr_result_2 = (double *)(result->matrix + result->rows);
      for (int i = 0; i < A->columns * A->rows; i++) {
        *(ptr_result_2 + i) = *(ptr_result + i);
      }
      s21_remove_matrix(&end_result);
    } else {
      *result = end_result;
    }
  } else {
    result_value = INCORRECT_MATRIX_ERROR;
  }
  return result_value;
}
