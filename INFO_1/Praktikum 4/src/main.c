/*
 * main.c
 *
 *  Created on: Dec 2, 2018
 *      Author: phillip
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void test1();
void test2();
void printVec(int size, double* vec);
void printMat(int sizeX, int sizeY, double** mat);

int main(int argc, char* argv[])
{
	test1();
	test2();

	return 0;
}


void test1()
{
	int sizeAx = 3, sizeBx = 3;
	int sizeAy = 3, sizeBy = 3;

	double a1[] = {0.5,-1.0,-1.0};
	double a2[] = {-1.0,1.0,2.0};
	double a3[] = {-1.0,2.0,1.0};

	double b1[] = {0.5,0.0,1.5};
	double b2[] = {5.0,-0.5,-3.0};
	double b3[] = {-1.0,-1.0,-0.75};

	double c1[] = {0.0,0.0,0.0};
	double c2[] = {0.0,0.0,0.0};
	double c3[] = {0.0,0.0,0.0};

	double* A[] = {a1, a2, a3};
	double* B[] = {b1, b2, b3};
	double* C[] = {c1, c2, c3};


	int sizeX = 3, sizeY = 3;

	double x[] = {1.0,2.0,4.0};
	double y[] = {2.0,3.0,5.0};
	double z[] = {0.0,0.0,0.0};


	printf("\n---------------Aufgabe 4---------------\n");

	printf("\n\nvecplus");
	vecplus(sizeX, sizeY, x, y, z);
	printVec(sizeX, z);

	printf("\n\nvecmult");
	vecmult(sizeX, sizeY, x, y, z);
	printVec(sizeX, z);

	printf("\n\nmatplus");
	matplus(sizeAx, sizeAy, sizeBx, sizeBy, A, B, C);
	printMat(sizeAx, sizeBx, C);

	printf("\n\nmatmult");
	matmult(sizeAx, sizeAy, sizeBx, sizeBy, A, B, C);
	printMat(sizeAx, sizeBx, C);

	printf("\n\nmatmulvec");
	matmulvec(sizeAx, sizeBx, sizeX, A, x, z);
	printVec(sizeX, z);
}

void test2()
{
	int sizeAx = 5, sizeBx = 3;
	int sizeAy = 3, sizeBy = 4;

	double a1[] = {0.5,-1.0,-1.0};
	double a2[] = {-1.0,1.0,2.0};
	double a3[] = {-1.0,2.0,1.0};
	double a4[] = {2.0,3.0,1.0};
	double a5[] = {0.5,2.0,1.0};

	double b1[] = {0.5, 0.0, 1.5,-3};
	double b2[] = {5.0,-0.5,-3.0,2.0};
	double b3[] = {-1.0,-1.0,-0.75,4.0};

	double c1[] = {0.0,0.0,0.0,0.0};
	double c2[] = {0.0,0.0,0.0,0.0};
	double c3[] = {0.0,0.0,0.0,0.0};
	double c4[] = {0.0,0.0,0.0,0.0};
	double c5[] = {0.0,0.0,0.0,0.0};

	double* A[] = {a1, a2, a3, a4, a5};
	double* B[] = {b1, b2, b3};
	double* C[] = {c1, c2, c3, c4, c5};


	int sizeX = 5, sizeY = 5;

	double x[] = {1.0,2.0,4.0,1.5,3.0};
	double y[] = {2.0,3.0,5.0,1.5,6.0};
	double z[] = {0.0,0.0,0.0,0.0,0.0};


	printf("\n---------------Aufgabe 5---------------\n");

	printf("\n\nvecplus");
	vecplus(sizeX, sizeY, x, y, z);
	printVec(sizeX, z);

	printf("\n\nvecmult");
	vecmult(sizeX, sizeY, x, y, z);
	printVec(sizeX, z);

	printf("\n\nmatmult");
	matmult(sizeAx, sizeAy, sizeBx, sizeBy, A, B, C);
	printMat(sizeBy, sizeAx, C);

	printf("\n\nmatmulvec");
	matmulvec(sizeAx, sizeBx, sizeX, A, x, z);
	printVec(sizeX, z);

	printf("\n\nmatplus");
	matplus(sizeAx, sizeAy, sizeBx, sizeBy, A, B, C);
	printMat(sizeBy, sizeAx, C);
}

void printVec(int size, double* vec)
{
	printf("\n");

	for(int i = 0; i < size; i++)
	{
		printf("%f\n", vec[i]);
	}
}


void printMat(int sizeX, int sizeY, double** mat)
{
	printf("\n");

	for(int i = 0; i < sizeY; i++)
	{
		for(int j = 0; j < sizeX; j++)
		{
			printf("%f\t", mat[i][j]);
		}

		printf("\n");
	}
}
