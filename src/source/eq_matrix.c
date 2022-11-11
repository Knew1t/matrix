#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = 1;
  if (is_matrix_correct(*A) && is_matrix_correct(*B) && A->rows == B->rows &&
      A->columns == B->columns) {
    double *ptr_a = (double *)((A->matrix) + A->rows);
    double *ptr_b = (double *)((B->matrix) + B->rows);
    int i = 0;
    while ((i < A->rows * A->columns)) {
      double num_a = *(ptr_a + i);
      double num_b = *(ptr_b + i);
      if (fabs(num_a - num_b) < 1e-6) {
        i++;
      } else {
        result = 0;
        break;
      }
    }
  } else {
    result = 0;
  }
  return result;
}
