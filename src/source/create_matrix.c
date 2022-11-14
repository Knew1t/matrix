#include "../core/helpers.h"
#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_value = OK;
  /* initiate_matrix(result); */
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          for (int j = 0; j < i; j++) {
            free(result->matrix[j]);
          }
          free(result->matrix);
        }
      }
    } else {
      return_value = INCORRECT_MATRIX_ERROR;
    }
  } else {
    return_value = INCORRECT_MATRIX_ERROR;
  }
  return return_value;
}

/* int s21_create_matrix(int rows, int columns, matrix_t *result) { */
/*   int error = OK; */
/*   initiate_matrix(result); */
/*   if (rows > 0 && columns > 0) { */
/*     int matrix_size = rows * columns; */
/*     result->rows = rows; */
/*     result->columns = columns; */
/*     double **m = */
/*         calloc(1, sizeof(double) * matrix_size + sizeof(double *) * rows); */
/*     /1* double **m = (double **)malloc(sizeof(double) * matrix_size + *1/ */
/*     /1*                                sizeof(double *) * rows); *1/ */
/*     if (m != NULL) { */
/*       double *ptr = (double *)(m + rows); */
/*       for (int i = 0; i < rows; i++) { */
/*         m[i] = ptr + columns * i; */
/*       } */
/*       /1* memset(m + rows, 0, matrix_size * (sizeof(double))); *1/ */
/*       result->matrix = m; */
/*     } else { */
/*       error = INCORRECT_MATRIX_ERROR; */
/*     } */
/*   } else { */
/*     error = INCORRECT_MATRIX_ERROR; */
/*   } */
/*   return error; */
/* } */
