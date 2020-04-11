#include "io.h"

int scan_rang(int* rang)
{
	printf("Number of equstions:"); 
	scanf("%d", rang); 
	return *rang <= MAX_RANG;
}

void scan_matrix(double** matrix, int* rang) 
{
	int i, j;
	printf("Enter the coefficients:\n");
	for(i = 0; i < *rang; i++) {
		for(j = 0; j < *rang +1; j++) {
			printf ("Element [%d][%d]= ", i, j);
			scanf ("%lf", &matrix[i][j]);
		} 
	} 
}

void print_matrix(double** matrix, int* rang)
{
	int i, j;
	for(i = 0; i < *rang; i++) {
		for(j = 0; j < *rang+1; j++) {
			printf("[%5.3lf]", matrix[i][j]);
		}
		printf("\n"); 
	}
	printf("\n"); 
	return;
}
