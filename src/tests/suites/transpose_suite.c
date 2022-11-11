#include "../../core/helpers.h"
#include "../test_main.h"

START_TEST(transpose_matrix_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);

  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(-10e10, 10e10);
      m.matrix[i][j] = rand_val;
      check.matrix[j][i] = rand_val;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), 1);

  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix_2) {
  // null pointer
  matrix_t A = {0};
  matrix_t *result = NULL;

  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_transpose(&A, result), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_matrix_3) {
  // incorrect input
  matrix_t A = {0};
  matrix_t result = {0};

  ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX_ERROR);
}
END_TEST

Suite *transpose_matrix_suite(void) {
  Suite *s = suite_create("transpose_matrix_suite");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, transpose_matrix_1);
  tcase_add_test(tc, transpose_matrix_2);
  tcase_add_test(tc, transpose_matrix_3);

  suite_add_tcase(s, tc);
  return s;
}
