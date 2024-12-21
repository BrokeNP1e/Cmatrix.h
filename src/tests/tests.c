#include "tests.h"

int main(void) {
  int failed = 0;
  int all = 0;
  int success = 0;
  Suite *list_cases[] = {test_create_matrix(),
                         test_remove_matrix(),
                         test_eq_matrix(),
                         test_sub_matrix(),
                         test_sum_matrix(),
                         test_mult_matrix(),
                         test_mult_number(),
                         test_transpose_matrix(),
                         test_calc_complements_matrix(),
                         test_determinant_matrix(),
                         test_inverse_matrix(),
                         NULL};

  for (int i = 0; list_cases[i] != NULL; i++) {
    SRunner *sr = srunner_create(list_cases[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    all += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  success = all - failed;
  printf("\033[45m\t----------ALL: %d--------------\t\t\033[0m \n", all);
  printf("\033[45m\t----------SUCCESS: %d----------\t\t\033[0m \n", success);
  printf("\033[45m\t----------FAILED: %d------------\t\t\033[0m \n", failed);

  return failed == 0 ? 0 : 1;
}