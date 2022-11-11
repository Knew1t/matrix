#include "../test_main.h"
START_TEST(s21_inverse_2) {
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 44300.0 / 367429.0;
  C.matrix[0][1] = -236300.0 / 367429.0;
  C.matrix[0][2] = 200360.0 / 367429.0;
  C.matrix[1][0] = 20600.0 / 367429.0;
  C.matrix[1][1] = 56000.0 / 367429.0;
  C.matrix[1][2] = -156483.0 / 367429.0;
  C.matrix[2][0] = 30900.0 / 367429.0;
  C.matrix[2][1] = 84000.0 / 367429.0;
  C.matrix[2][2] = -51010.0 / 367429.0;

  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(s21_inverse_1) {
  matrix_t A = {0}, C = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B = {0};
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_one_by_one) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_double_eq_tol(result.matrix[0][0], (1.0 / m.matrix[0][0]), 1e-06);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_zero_det) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_double_eq_tol(result.matrix[0][0], (1.0 / m.matrix[0][0]), 1e-06);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALCULATION_ERROR);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_normal) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec2 = OK;
  int codec1 = s21_create_matrix(3, 3, &m);
  if (!codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (!codec1 && !codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), 1);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), 1);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_error) {
  matrix_t m = {0};
  matrix_t mtx = {0};
  s21_create_matrix(0, -6, &mtx);

  ck_assert_int_eq(s21_inverse_matrix(&mtx, &m), INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(huge_test) {
  matrix_t val1 = {0}, result = {0}, expected = {0};
  int size = 8;
  s21_create_matrix(size, size, &val1);
  s21_create_matrix(size, size, &expected);

  val1.matrix[0][0] = 2;
  val1.matrix[0][1] = 8;
  val1.matrix[0][2] = 7;
  val1.matrix[0][3] = 4;
  val1.matrix[0][4] = 1;
  val1.matrix[0][5] = 8;
  val1.matrix[0][6] = 3;
  val1.matrix[0][7] = 9;

  val1.matrix[1][0] = 4;
  val1.matrix[1][1] = 2;
  val1.matrix[1][2] = 6;
  val1.matrix[1][3] = 2;
  val1.matrix[1][4] = 2;
  val1.matrix[1][5] = 1;
  val1.matrix[1][6] = 5;
  val1.matrix[1][7] = 8;

  val1.matrix[2][0] = 8;
  val1.matrix[2][1] = 6;
  val1.matrix[2][2] = 7;
  val1.matrix[2][3] = 7;
  val1.matrix[2][4] = 3;
  val1.matrix[2][5] = 4;
  val1.matrix[2][6] = 4;
  val1.matrix[2][7] = 1;

  val1.matrix[3][0] = 1;
  val1.matrix[3][1] = 7;
  val1.matrix[3][2] = 0;
  val1.matrix[3][3] = 4;
  val1.matrix[3][4] = 4;
  val1.matrix[3][5] = 3;
  val1.matrix[3][6] = 0;
  val1.matrix[3][7] = 5;

  val1.matrix[4][0] = 5;
  val1.matrix[4][1] = 7;
  val1.matrix[4][2] = 5;
  val1.matrix[4][3] = 6;
  val1.matrix[4][4] = 8;
  val1.matrix[4][5] = 3;
  val1.matrix[4][6] = 1;
  val1.matrix[4][7] = 9;

  val1.matrix[5][0] = 3;
  val1.matrix[5][1] = 7;
  val1.matrix[5][2] = 8;
  val1.matrix[5][3] = 0;
  val1.matrix[5][4] = 5;
  val1.matrix[5][5] = 7;
  val1.matrix[5][6] = 0;
  val1.matrix[5][7] = 2;

  val1.matrix[6][0] = 5;
  val1.matrix[6][1] = 8;
  val1.matrix[6][2] = 3;
  val1.matrix[6][3] = 5;
  val1.matrix[6][4] = 9;
  val1.matrix[6][5] = 1;
  val1.matrix[6][6] = 2;
  val1.matrix[6][7] = 0;

  val1.matrix[7][0] = 7;
  val1.matrix[7][1] = 8;
  val1.matrix[7][2] = 7;
  val1.matrix[7][3] = 4;
  val1.matrix[7][4] = 7;
  val1.matrix[7][5] = 9;
  val1.matrix[7][6] = 1;
  val1.matrix[7][7] = 5;

  expected.matrix[0][0] = -0.5349902183;
  expected.matrix[0][1] = 0.2894503762;
  expected.matrix[0][2] = 0.2648128502;
  expected.matrix[0][3] = 0.6295578936;
  expected.matrix[0][4] = -0.1684575429;
  expected.matrix[0][5] = 0.2471263249;
  expected.matrix[0][6] = -0.3773947292;
  expected.matrix[0][7] = 0.0217143747;

  expected.matrix[1][0] = -0.3358379646;
  expected.matrix[1][1] = 0.2037511071;
  expected.matrix[1][2] = 0.2032547229;
  expected.matrix[1][3] = 0.6234293334;
  expected.matrix[1][4] = -0.1799149334;
  expected.matrix[1][5] = 0.3295114996;
  expected.matrix[1][6] = -0.2254070837;
  expected.matrix[1][7] = -0.1935314328;

  expected.matrix[2][0] = 0.09452225456;
  expected.matrix[2][1] = -0.09221066155;
  expected.matrix[2][2] = 0.03813722914;
  expected.matrix[2][3] = -0.2190871073;
  expected.matrix[2][4] = 0.1695573745;
  expected.matrix[2][5] = 0.1092580516;
  expected.matrix[2][6] = 0.007715043036;
  expected.matrix[2][7] = -0.1600498331;

  expected.matrix[3][0] = 0.3630563639;
  expected.matrix[3][1] = -0.3052665388;
  expected.matrix[3][2] = -0.04656927155;
  expected.matrix[3][3] = -0.4771776828;
  expected.matrix[3][4] = 0.2389343637;
  expected.matrix[3][5] = -0.2685487089;
  expected.matrix[3][6] = 0.1928760759;
  expected.matrix[3][7] = -0.001245826966;

  expected.matrix[4][0] = 0.2619837848;
  expected.matrix[4][1] = -0.133556544;
  expected.matrix[4][2] = -0.2495968906;
  expected.matrix[4][3] = -0.4562289726;
  expected.matrix[4][4] = 0.1044612934;
  expected.matrix[4][5] = -0.2245895097;
  expected.matrix[4][6] = 0.3128420752;
  expected.matrix[4][7] = 0.1500734843;

  expected.matrix[5][0] = 0.2992174649;
  expected.matrix[5][1] = -0.1560300945;
  expected.matrix[5][2] = -0.1850280149;
  expected.matrix[5][3] = -0.3646314915;
  expected.matrix[5][4] = -0.02339656554;
  expected.matrix[5][5] = -0.2701059926;
  expected.matrix[5][6] = 0.1915783395;
  expected.matrix[5][7] = 0.2628500238;

  expected.matrix[6][0] = 0.3028673486;
  expected.matrix[6][1] = 0.0418714657;
  expected.matrix[6][2] = -0.2001336669;
  expected.matrix[6][3] = -0.3106910771;
  expected.matrix[6][4] = -0.1692459178;
  expected.matrix[6][5] = -0.2826713255;
  expected.matrix[6][6] = 0.3477738954;
  expected.matrix[6][7] = 0.1562734201;

  expected.matrix[7][0] = -0.1023914038;
  expected.matrix[7][1] = 0.1015348978;
  expected.matrix[7][2] = 0.0104305565;
  expected.matrix[7][3] = 0.1667915738;
  expected.matrix[7][4] = 0.02489382894;
  expected.matrix[7][5] = 0.04583280613;
  expected.matrix[7][6] = -0.1284726616;
  expected.matrix[7][7] = -0.01017100922;

  ck_assert_int_eq(s21_inverse_matrix(&val1, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&expected, &result), 1);
  s21_remove_matrix(&val1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected);
}
END_TEST

Suite *inverse_matrix_suite(void) {
  Suite *s = suite_create("inverse_matrix_suite");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, inverse);
  tcase_add_test(tc, s21_inverse_1);
  tcase_add_test(tc, s21_inverse_2);

  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_not_sqare);
  tcase_add_test(tc, test_zero_det);
  tcase_add_test(tc, test_incorrect);
  tcase_add_test(tc, test_one_by_one);
  tcase_add_test(tc, inverse_matrix_error);
  tcase_add_test(tc, huge_test);

  suite_add_tcase(s, tc);
  return s;
}
