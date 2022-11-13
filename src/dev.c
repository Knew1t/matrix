#include "./core/helpers.h"
#include "s21_matrix.h"
#define MIN_ACCURACY 1e-6l
int main(void) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  /* printf("пустые матрицы\n"); */
  /* print_matrix(A); */
  /* print_matrix(B); */

  /* printf("заполняем 123\n"); */
  /* print_matrix(A); */
  /* print_matrix(B); */
  int res = s21_eq_matrix(&A, &B);
  printf("res = %d\n", res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  return 0;
}
