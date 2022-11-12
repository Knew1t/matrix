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

START_TEST(mult_number_4_not_fully_initialised) {
  double number = 0.5;
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t expected = {0};
  s21_create_matrix(rows, cols, &expected);
  s21_create_matrix(rows, cols, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 4;
  m.matrix[0][2] = 6;
  m.matrix[1][0] = 8;
  m.matrix[1][1] = 10;
  m.matrix[1][2] = 12;

  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 2;
  expected.matrix[0][2] = 3;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = 5;
  expected.matrix[1][2] = 6;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 0;
  expected.matrix[2][2] = 0;

  matrix_t res = {0};
  s21_mult_number(&m, number, &res);
  ck_assert_int_eq(1, s21_eq_matrix(&res, &expected));
  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_5_same_matrix_in_and_out) {
  double number = 0.5;
  const int rows = 3;
  const int cols = 3;
  matrix_t m = {0};
  matrix_t expected = {0};
  s21_create_matrix(rows, cols, &expected);
  s21_create_matrix(rows, cols, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 4;
  m.matrix[0][2] = 6;
  m.matrix[1][0] = 8;
  m.matrix[1][1] = 10;
  m.matrix[1][2] = 12;

  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = 2;
  expected.matrix[0][2] = 3;
  expected.matrix[1][0] = 4;
  expected.matrix[1][1] = 5;
  expected.matrix[1][2] = 6;
  expected.matrix[2][0] = 0;
  expected.matrix[2][1] = 0;
  expected.matrix[2][2] = 0;

  s21_mult_number(&m, number, &m);
  ck_assert_int_eq(1, s21_eq_matrix(&m, &expected));
  s21_remove_matrix(&m);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(mult_number_6_not_initialised) {
  double number = 0.5;
  matrix_t m = {0};
  matrix_t expected = {0};
  s21_mult_number(&m, number, &expected);
  ck_assert_int_eq(1, INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&m);
}

Suite *mult_number_suite(void) {
  Suite *s = suite_create("mult_number_suite");
  TCase *tc = tcase_create("core");

  tcase_add_loop_test(tc, mult_number_1, 0, 100);
  tcase_add_test(tc, mult_number_2_inf);
  tcase_add_test(tc, mult_number_3_nan);
  tcase_add_test(tc, mult_number_4_not_fully_initialised);
  tcase_add_test(tc, mult_number_5_same_matrix_in_and_out);
  tcase_add_test(tc, mult_number_6_not_initialised);

  suite_add_tcase(s, tc);
  return s;
}
