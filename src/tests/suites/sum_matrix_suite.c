#include "../../core/helpers.h"
#include "../test_main.h"

START_TEST(sum_matrix_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(-6e6, 6e6);
      mtx.matrix[i][j] = get_rand(-6e6, 6e6);
      check.matrix[i][j] = m.matrix[i][j] + mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(sum_matrix_2_error) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  matrix_t mtx = {0};
  s21_create_matrix(rows, cols, &mtx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  matrix_t res = {0};

  ck_assert_int_eq(s21_sum_matrix(&m, &mtx, &res), INCORRECT_MATRIX_ERROR);

  // s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
}
END_TEST

START_TEST(sum_matrix_3_wrong_size) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix_4_null_pointer) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t *result = NULL;

  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, result), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

Suite *sum_matrix_suite(void) {
  Suite *s = suite_create("sum_matrix_suite");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, sum_matrix_1);
  tcase_add_test(tc, sum_matrix_2_error);
  tcase_add_test(tc, sum_matrix_3_wrong_size);
  tcase_add_test(tc, sum_matrix_4_null_pointer);

  suite_add_tcase(s, tc);
  return s;
}
