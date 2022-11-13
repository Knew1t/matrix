#include "../../core/helpers.h"
#include "../test_main.h"

START_TEST(eq_matrix_1) {
  // equal
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t A = {0};
  s21_create_matrix(rows, cols, &A);
  matrix_t B = {0};
  s21_create_matrix(rows, cols, &B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(DBL_MIN, DBL_MAX);
      A.matrix[i][j] = rand_val;
      B.matrix[i][j] = rand_val;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_2) {
  // not equal
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t A = {0};
  s21_create_matrix(rows, cols, &A);
  matrix_t B = {0};
  s21_create_matrix(rows, cols, &B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      A.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
      B.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_3) {
  // error
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(rows, cols, &B);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      B.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_4) {
  // error
  const int rows = 2;
  const int cols = 2;
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(rows, cols, &B);
  s21_create_matrix(rows, cols, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;

  B.matrix[0][0] = 1;
  /* B.matrix[0][1] = 1; */

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(eq_matrix_5) {

  matrix_t A;
  matrix_t B = {0};

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
}
END_TEST

START_TEST(eq_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(-1, 0, &A);
  s21_create_matrix(-1, 0, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
}
END_TEST

Suite *eq_matrix_suite(void) {
  Suite *s = suite_create("eq_matrix_suite");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);
  tcase_add_test(tc, eq_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}
