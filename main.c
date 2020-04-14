#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "gauss.h"

void calculate();

int main() 
{ 
    int menu_item;
    printf("GAUSSIAN ELIMINATION v3.1\nCopyright (C) 2018 Khalymain Vladimir\n\n");
    while(1) {
    	printf("0 - exit\n1 - calculate\n\nSelect menu item:");
	scanf("%d", &menu_item);

	if(menu_item != 0 && menu_item != 1)
		printf("\nNonexistent menu item! Please enter again.\n");
	else
		menu_item ? calculate() : exit(0);		
    }  
}

void calculate()
{
	double** matrix;
	int i, rank;

	while(!scan_rank(&rank)) {
		printf("\nToo many equastinos! Please enter again.\n\n");
	}

	/* memory allocation for matrix */
	matrix = (double**)malloc(sizeof(double*)*(rank+1));
	for (i = 0; i < rank; i++) {
		matrix[i] = (double*)malloc(sizeof(double)*rank);
	}

	scan_matrix(matrix, &rank);
	print_matrix(matrix, &rank);
	gauss(matrix, &rank);

	for (i = 0; i < rank; i++)
		free(matrix[i]);
	free(matrix);
	return;
}
