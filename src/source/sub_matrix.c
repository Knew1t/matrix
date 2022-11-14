#include "../core/helpers.h"
#include "../s21_matrix.h"

/*PATHETIC TWO MALLOCS*/
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = OK;
  if (is_matrix_correct(A) && is_matrix_correct(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
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

/* OLD FUNCTION WITH SINGLE MALLOC THE TRUE WAY OF GODLIKE CODERS*/
/* int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) { */
/*   int return_value = OK; */
/*   if (result != NULL && is_matrix_correct(*A) && is_matrix_correct(*B)) { */
/*     s21_create_matrix(A->rows, A->columns, result); */
/*     if (A->rows == B->rows && A->columns == B->columns) { */
/*       double *ptr_a = (double *)((A->matrix) + A->rows); */
/*       double *ptr_b = (double *)((B->matrix) + B->rows); */
/*       double *ptr_result = (double *)((result->matrix) + result->rows); */
/*       int i = 0; */
/*       while ((i < A->rows * A->columns)) { */
/*         double num_a = *(ptr_a + i); */
/*         double num_b = *(ptr_b + i); */
/*         *(ptr_result + i) = num_a - num_b; */
/*         i++; */
/*       } */
/*     } else { */
/*       return_value = CALCULATION_ERROR; */
/*       s21_remove_matrix(result); */
/*     } */
/*   } else { */
/*     return_value = INCORRECT_MATRIX_ERROR; */
/*   } */
/*   return return_value; */
/* } */
