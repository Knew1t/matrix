#include "./core/helpers.h"
#include "s21_matrix.h"
#define MIN_ACCURACY 1e-6l
int main(void) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 3, &B);
  A.matrix[0][0] = 1;
  printf("s21_eq_matrix(&A, &B) = %d\n", s21_eq_matrix(&A, &B));

  /* print_matrix(A); */
  /* print_matrix(A); */

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return 0;
}
