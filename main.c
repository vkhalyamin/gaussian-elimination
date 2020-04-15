#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "gauss.h"

enum { EXIT = 48, CALCULATE }; /* key '0' code and key '1' code */

void calculate();

int main() 
{ 
	int menu_item;
	printf("GAUSSIAN ELIMINATION v3.1\nCopyright (C) 2018 Khalymain Vladimir\n\n");
	while(1) {
    		printf("0 - exit\n1 - calculate\n\nSelect menu item: ");
		menu_item = getchar();

		switch(menu_item) {
		case CALCULATE: calculate(); break;
		case EXIT: exit(0);
		default: printf("Incorrect menu item! Please enter again.\n");
		}

		menu_item = getchar();
	}  
}

void calculate()
{
	double **matrix;
	int i, rank;

	while(!scan_rank(&rank)) {
		printf("\nIncorrect equestions number! Please enter again.\n\n");
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
