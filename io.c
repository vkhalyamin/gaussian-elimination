#include "io.h"

int scan_rank(int *rank)
{
	printf("Number of equstions:"); 
	scanf("%d", rank); 
	return *rank <= MAX_RANK && *rank;
}

void scan_matrix(double **matrix, const int *rank) 
{
	int i, j;
	printf("Enter the coefficients:\n");
	for(i = 0; i < *rank; i++) {
		for(j = 0; j < *rank +1; j++) {
			printf ("Element [%d][%d]= ", i, j);
			scanf ("%lf", &matrix[i][j]);
		} 
	} 
}

void print_matrix(double **matrix, const int *rank)
{
	int i, j;
	for(i = 0; i < *rank; i++) {
		for(j = 0; j < *rank+1; j++) {
			printf("[%5.3lf]", matrix[i][j]);
		}
		printf("\n"); 
	}
	printf("\n"); 
	return;
}
