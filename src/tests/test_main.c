#include "test_main.h"

int main(void) {
  Suite *test_suites[] = {eq_matrix_suite(),        determinant_suite(),
                          calc_complements_suite(), create_matrix_suite(),
                          transpose_matrix_suite(), sum_matrix_suite(),
                          calc_complements_suite(), mult_matrix_suite(),
                          mult_number_suite(),      sub_matrix_suite(),
                          inverse_matrix_suite()};

  SRunner *sr = srunner_create(test_suites[0]);
  srunner_set_fork_status(sr, CK_NOFORK);

  for (size_t i = 1; i < ARRAY_SIZE(test_suites); i++)
    srunner_add_suite(sr, test_suites[i]);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
