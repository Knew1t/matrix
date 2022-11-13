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

START_TEST(transpose_matrix_4_uninitialized_fully) {
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
  ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&result);
}
END_TEST

Suite *transpose_matrix_suite(void) {
  Suite *s = suite_create("transpose_matrix_suite");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, transpose_matrix_1);
  tcase_add_test(tc, transpose_matrix_2);
  tcase_add_test(tc, transpose_matrix_3);
  tcase_add_test(tc, transpose_matrix_4_uninitialized_fully);

  suite_add_tcase(s, tc);
  return s;
}
