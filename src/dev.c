#include "./core/helpers.h"
#include "s21_matrix.h"
#define MIN_ACCURACY 1e-6l
int main(void) {
  matrix_t m;
  s21_create_matrix(3, 3, &m);
  fill_matrix(&m);
  print_matrix(m);
  s21_remove_matrix(&m);
  /* const int size = 3; */
  /* matrix_t m = {0}; */
  /* s21_create_matrix(size, size, &m); */

  /* m.matrix[0][0] = 2; */
  /* m.matrix[0][1] = 5; */
  /* m.matrix[0][2] = 7; */
  /* m.matrix[1][0] = 6; */
  /* m.matrix[1][1] = 3; */
  /* m.matrix[1][2] = 4; */
  /* m.matrix[2][0] = 5; */
  /* m.matrix[2][1] = -2; */
  /* m.matrix[2][2] = -3; */
  /* print_matrix(m); */

  /* matrix_t res = {0}; */
  /* s21_inverse_matrix(&m, &res); */

  /* matrix_t expected = {0}; */
  /* s21_create_matrix(size, size, &expected); */
  /* expected.matrix[0][0] = 1; */
  /* expected.matrix[0][1] = -1; */
  /* expected.matrix[0][2] = 1; */
  /* expected.matrix[1][0] = -38; */
  /* expected.matrix[1][1] = 41; */
  /* expected.matrix[1][2] = -34; */
  /* expected.matrix[2][0] = 27; */
  /* expected.matrix[2][1] = -29; */
  /* expected.matrix[2][2] = 24; */
  /* expected.matrix[2][2] = 24; */
  /* print_matrix(expected); */
  /* print_matrix(res); */
  /* s21_remove_matrix(&expected); */
  /* s21_remove_matrix(&res); */
  /* s21_remove_matrix(&m); */
  return 0;
}
