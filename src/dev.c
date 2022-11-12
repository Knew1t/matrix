#include "core/helpers.h"
#include "s21_matrix.h"
int main() {

  // incorrect input
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t expected = {0};
  s21_create_matrix(2, 4, &A);
  s21_create_matrix(4, 2, &expected);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  /* A.matrix[1][2] = 7; */
  /* A.matrix[1][3] = 8; */

  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 5;

  expected.matrix[1][0] = 2;
  expected.matrix[1][1] = 6;

  expected.matrix[2][0] = 3;
  expected.matrix[2][1] = 0;

  expected.matrix[3][0] = 4;
  expected.matrix[3][1] = 0;
  s21_transpose(&A, &result);
  printf("original\n");
  print_matrix(A);
  printf("correct result\n");
  print_matrix(expected);
  printf("actual result\n");
  print_matrix(result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
  return 0;
}
