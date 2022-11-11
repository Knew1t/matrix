#include "../test_main.h"

START_TEST(remove_matrix_1) {
  matrix_t m = {0};
  s21_create_matrix(2, 2, &m);
  s21_remove_matrix(&m);
  ck_assert_ptr_null(m.matrix);
}
END_TEST
Suite *remove_matrix_suite(void) {
  Suite *s = suite_create("remove_matrix_suite");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, remove_matrix_1);

  suite_add_tcase(s, tc);
  return s;
}
