#include "gauss.h"

void main_element(double **matrix, int *rank, int k, int *order)
{
	int i, j, i_max = k, j_max = k;
	double temp;
	/* search for max element */
	for(i = k; i < *rank; i++) {
		for(j = k; j < *rank; j++) {
			if(fabs(matrix[i_max][j_max]) < fabs(matrix[i][j])) {
				i_max = i;
				j_max = j;
			}
		}
	}
	/* lines swap */
	for(j = k; j < *rank+1; j++) {
		temp = matrix[k][j];
		matrix[k][j] = matrix[i_max][j];
		matrix[i_max][j] = temp;
	}
	/* columns swap */
	for(i = 0; i < *rank; i++) {
		temp = matrix[i][k];
		matrix[i][k] = matrix[i][j_max];
		matrix[i][j_max] = temp;
	}
	i = order[k];
	order[k] = order[j_max];
	order[j_max] = i;
	print_matrix(matrix, rank);
}

void gauss(double **matrix, int *rank)
{
	double roots[*rank];
	int order[*rank];
	int i, j, k;

	for(i = 0; i < *rank+1; i++) {
		order[i] = i;
	} 
	for(k = 0; k < *rank; k++) {
		main_element(matrix, rank, k, order);
		if(fabs(matrix[k][k]) <= 0) {
			printf("The system does not have a unique solution!\n");
			return;
		}
		for(j = *rank; j >= k; j--) {
			matrix[k][j] /= matrix[k][k];
		}
		for(i = k+1; i < *rank; i++) {
			for(j = *rank; j >= k; j--) {
				matrix[i][j] -= matrix[k][j]*matrix[i][k];
			}
		}
	}

	for(i = 0; i < *rank; i++) {
		roots[i] = matrix[i][*rank];
	}
	for(i = *rank-2; i >= 0; i--) {
		for(j = i+1; j < *rank; j++) {
			roots[i] -= roots[j]*matrix[i][j];
		}
	}

	print_matrix(matrix, rank);
	printf("\nResult:\n");
	for(i = 0; i < *rank; i++) {
		printf("%lf\n", roots[order[i]]);
	}
	printf("\n\n");
	return;
}
