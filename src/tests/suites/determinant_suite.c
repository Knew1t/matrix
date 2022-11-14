#include "../test_main.h"

START_TEST(det1) {
  // ex 34
  double m2[16] = {1, 3, 9, 2, 5, 8, 4, 3, 0, 0, 0, 0, 2, 3, 1, 8};
  matrix_t m;
  double result = 0;
  double correct_result = 0;
  s21_create_matrix(4, 4, &m);
  fill_with_array_values(m2, &m);
  s21_determinant(&m, &result);
  s21_remove_matrix(&m);
  ck_assert_double_eq_tol(correct_result, result, 1e-6l);
}
END_TEST

START_TEST(det2) {
  double m2[25] = {4,  5, 6, 5, 11, 1, 4, 2, 0, 13, 1, 1, 0,
                   -1, 5, 3, 2, 3,  0, 7, 4, 1, 2,  3, 8};
  matrix_t m;
  double result = 0;
  double correct_result = 264;
  s21_create_matrix(5, 5, &m);
  fill_with_array_values(m2, &m);
  s21_determinant(&m, &result);
  s21_remove_matrix(&m);
  ck_assert_double_eq_tol(correct_result, result, 1e-6l);
}
END_TEST

START_TEST(det3) {
  double m2[16] = {2, 5, 1, 4, 4, 1, 6, 3, 5, 3, 7, 2, 1, 0, 2, 4};
  matrix_t m;
  double result = 0;
  double correct_result = -36;
  s21_create_matrix(4, 4, &m);
  fill_with_array_values(m2, &m);
  s21_determinant(&m, &result);
  s21_remove_matrix(&m);
  ck_assert_double_eq_tol(correct_result, result, 1e-6l);
}
END_TEST

START_TEST(det4) {
  double result = 0;
  double correct_result = 0;
  matrix_t m;
  s21_create_matrix(10, 10, &m);
  fill_matrix(&m);
  s21_determinant(&m, &result);
  s21_remove_matrix(&m);
  ck_assert_double_eq_tol(correct_result, result, 1e-6l);
}
END_TEST

START_TEST(det5_single) {
  double result = 0;
  double correct_result = 1;
  matrix_t m;
  s21_create_matrix(1, 1, &m);
  fill_matrix(&m);
  s21_determinant(&m, &result);
  s21_remove_matrix(&m);
  ck_assert_double_eq_tol(correct_result, result, 1e-6l);
}
END_TEST

Suite *determinant_suite(void) {
  Suite *s = suite_create("determinant_suite");
  TCase *tc = tcase_create("core");
  tcase_add_test(tc, det1);
  tcase_add_test(tc, det2);
  tcase_add_test(tc, det3);
  tcase_add_test(tc, det4);
  tcase_add_test(tc, det5_single);

  suite_add_tcase(s, tc);
  return s;
}
