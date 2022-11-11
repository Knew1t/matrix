#include "../test_main.h"

START_TEST(mult_number_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  double mult_number = get_rand(DBL_MIN, DBL_MAX);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] * mult_number;
    }
  }
  matrix_t res = {0};
  int a = s21_mult_number(&m, mult_number, &res);
  ck_assert_int_eq(a, OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_2_inf) {
  double number = INFINITY;
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t res = {0};
  int a = s21_mult_number(&m, number, &res);
  ck_assert_int_eq(a, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(mult_number_3_nan) {
  double number = NAN;
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t res = {0};
  int a = s21_mult_number(&m, number, &res);
  ck_assert_int_eq(a, CALCULATION_ERROR);
  s21_remove_matrix(&m);
}
END_TEST

Suite *mult_number_suite(void) {
  Suite *s = suite_create("mult_number_suite");
  TCase *tc = tcase_create("core");

  tcase_add_loop_test(tc, mult_number_1, 0, 100);
  tcase_add_test(tc, mult_number_2_inf);
  tcase_add_test(tc, mult_number_3_nan);

  suite_add_tcase(s, tc);
  return s;
}
