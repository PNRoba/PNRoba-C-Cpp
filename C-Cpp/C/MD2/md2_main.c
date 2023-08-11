#include <stdio.h>
#include <stdlib.h>
#include "md2.h"

int main(int argc, char **argv)
{
	int  w1,h1;
	int *matrix1;
	int *p1;

	scanf("%d", &h1);
	scanf("%d", &w1);



	matrix1 = (int*) malloc(w1 * h1 * sizeof(int));				// reserve space for matrix1
	p1 = matrix1;												// return pointer to matrix1
	for(int i=0; i<(w1*h1); i++)
	{
		scanf("%d", p1);
		p1++;
	}


	int  w2,h2;
	int *matrix2;
	int *p2;

	scanf("%d", &h2);
	scanf("%d", &w2);


	matrix2 = (int*) malloc(w2 * h2 * sizeof(int));				// reserve space for matrix2
	p2 = matrix2;												// return pointer to matrix2
	for(int i=0; i<(w2*h2); i++)
	{
		scanf("%d", p2);
		p2++;
	}

	int *matrix3;
	matrix3 = (int*) malloc(h1 * w2 * sizeof(int));				// reserve space for matrix3
	int *p3;													// return pointer to matrix3
	int h3=h1, w3=w2;

	if (h2==w1) {
		matmul(h1, w1, matrix1, h2, w2, matrix2, matrix3);		// matmul()
		p3 = matrix3;
		
		printf("%d", h3);
		printf(" ");
		printf("%d", w3);
		printf("\n");

		for(int i=0; i<h3; i++)
		{
			for(int j=0; j<w3; j++)
			{
				printf("%d", *p3);
				p3++;
				printf(" ");
			}
			printf("\n");
		}
	}
	else {
		exit(1);
	}

	return 0;
}
