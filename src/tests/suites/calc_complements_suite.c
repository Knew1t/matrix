#include "../test_main.h"

START_TEST(calc_complements_1) {
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t res = {0};
  s21_create_matrix(3, 3, &res);
  matrix_t m;
  double result_array[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  double m2[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  fill_with_array_values(m2, 9, &a);
  fill_with_array_values(result_array, 9, &res);
  s21_calc_complements(&a, &m);
  ck_assert_int_eq(s21_eq_matrix(&res, &m), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(calc_complements_2_empty) {
  matrix_t a = {0};
  matrix_t b = {0};
  ck_assert_int_eq(s21_calc_complements(&a, &b), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(calc_complements_3_wrong_size) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(1, 2, &a);
  ck_assert_int_eq(s21_calc_complements(&a, &b), CALCULATION_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(calc_complements_4) {
  const int size = 3;
  matrix_t m = {0};
  matrix_t result = {0};
  s21_create_matrix(size, size, &m);
  s21_create_matrix(size, size, &result);
  double m_array[9] = {1, 2, 3, 1, 4, 2, 5, 2, 1};
  double result_array[9] = {0, 9, -18, 4, -14, 8, -8, 1, 2};
  fill_with_array_values(m_array, 9, &m);
  fill_with_array_values(result_array, 9, &result);
  matrix_t res = {0};
  s21_calc_complements(&m, &res);
  ck_assert_int_eq(s21_eq_matrix(&result, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_5) {
  const int size = 3;
  double m_array[9] = {5.63, 4.789,  -6.781, 100.03, 10.23,
                       45.3, -78.21, -11.11, 0};
  double expected_array[9] = {503.283000, -3542.913000, -311.245000,
                              75.336910,  -530.342010,  -311.998390,
                              286.311330, -933.342430,  -421.448770};
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  fill_with_array_values(m_array, 9, &m);
  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  fill_with_array_values(expected_array, 9, &expected);
  matrix_t res = {0};
  s21_calc_complements(&m, &res);

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&expected);
}
END_TEST

START_TEST(calc_complements_6_negaitve_columns) {
  matrix_t a = {0};
  matrix_t b = {0};
  s21_create_matrix(-1, 0, &a);
  s21_create_matrix(10, -13, &b);
  ck_assert_int_eq(s21_calc_complements(&a, &b), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

Suite *calc_complements_suite(void) {
  Suite *s = suite_create("calc_complements_suite");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2_empty);
  tcase_add_test(tc, calc_complements_3_wrong_size);
  tcase_add_test(tc, calc_complements_4);
  tcase_add_test(tc, calc_complements_5);
  tcase_add_test(tc, calc_complements_6_negaitve_columns);

  suite_add_tcase(s, tc);
  return s;
}
