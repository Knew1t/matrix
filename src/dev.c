#include "./core/helpers.h"
#include "s21_matrix.h"

int main(void) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  print_matrix(a);
  s21_calc_complements(&a, &b);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);

  return 0;
}
