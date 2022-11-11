#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    free(A->matrix);
    A->matrix = NULL;
  }
}
