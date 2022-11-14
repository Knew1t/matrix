#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_value = OK;
  if (is_matrix_correct(*A) && result != NULL) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int j = 0; j < A->columns; j++) {
      for (int k = 0; k < A->rows; k++) {
        result->matrix[j][k] = A->matrix[k][j];
      }
    }
  } else {
    result_value = INCORRECT_MATRIX_ERROR;
  }
  return result_value;
}

/* int s21_transpose(matrix_t *A, matrix_t *result) { */
/*   int result_value = OK; */
/*   if (is_matrix_correct(*A) && result != NULL) { */
/*     matrix_t end_result = {0}; */
/*     s21_create_matrix(A->columns, A->rows, &end_result); */
/*     double *ptr_result = (double *)(end_result.matrix + end_result.rows); */
/*     for (int j = 0; j < A->columns; j++) { */
/*       for (int k = 0; k < A->rows; k++) { */
/*         *(ptr_result) = A->matrix[k][j]; */
/*         ptr_result++; */
/*       } */
/*     } */
/*     if (A == result) { */
/*       /1* ptr_result = (double *)(end_result.matrix + end_result.rows); *1/
 */
/*       /1* double *ptr_result_2 = (double *)(result->matrix + result->rows);
 * *1/ */
/*       s21_remove_matrix(A); */
/*       *A = end_result; */
/*       /1* for (int i = 0; i < A->columns * A->rows; i++) { *1/ */
/*       /1*   *(ptr_result_2 + i) = *(ptr_result + i); *1/ */
/*       /1* } *1/ */
/*     } else { */
/*       *result = end_result; */
/*     } */
/*   } else { */
/*     result_value = INCORRECT_MATRIX_ERROR; */
/*   } */
/*   return result_value; */
/* } */
