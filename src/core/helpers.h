#ifndef HELPERS_H
#define HELPERS_H
#include <float.h>

#include "../s21_matrix.h"

void initiate_matrix(matrix_t *m);
void print_matrix(matrix_t m);
int is_matrix_correct(matrix_t m);
double calc_minor(int i, int j, matrix_t *A);
void fill_lesser_matrix(int i, int j, matrix_t *lesser_matrix,
                        matrix_t *main_matrix);
void fill_matrix(matrix_t *m);
void fill_with_array_values(const double *m, size_t array_size1, matrix_t *A);
double get_rand(double min, double max);
#endif /* ifndef HELPERS_H */
