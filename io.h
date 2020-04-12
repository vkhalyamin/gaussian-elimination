#ifndef IO_H_
#define IO_H_

#include <stdio.h>

enum {MAX_RANK = 20};

int scan_rank(int* rank);
void scan_matrix(double** matrix, int* rank);
void print_matrix(double** matrix, int* rank);

#endif
