#ifndef IO_H_
#define IO_H_

#include <stdio.h>

enum {MAX_RANG = 20};

int scan_rang(int* rang);
void scan_matrix(double** matrix, int* rang);
void print_matrix(double** matrix, int* rang);

#endif
