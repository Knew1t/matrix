#include "core/helpers.h"
#include "s21_matrix.h"
int main(int argc, char *argv[]) {
  matrix_t m = {0};
  int rows = atoi(argv[argc - 2]);
  int columns = atoi(argv[argc - 1]);
  s21_create_matrix(rows, columns, &m);
  print_matrix(m);
  fill_matrix(&m);
  print_matrix(m);
  s21_remove_matrix(&m);

  return 0;
}
