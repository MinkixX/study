/*
 * main.c
 *
 *  Created on: Dec 2, 2018
 *      Author: phillip
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


void test();
void testFree();
void printVec(Vector* x);
void printMat(Matrix* A);


int main(int argc, char* argv[])
{
	test();
	//testFree();

	return 0;
}


void testFree()
{
	Matrix* A = newMatrix(5, 5);

	freeMatrix(A);
}


void test()
{
	int rowsA = 3, columnsA = 3;
	double a1[] = {1.0,1.0,3.0};
	double a2[] = {5.0,2.0,6.0};
	double a3[] = {-2.0,-1.0,-3.0};

	int rowsB = 2, columnsB = 2;
	double b1[] = {2.0,-1.0};
	double b2[] = {0.0,2.0};

	int rowsC = 5, columnsC = 5;
	double c1[] = {0.0, 0.0, 0.0, 0.0, 16.0};
	double c2[] = {(3.0/4.0), 0.0, 0.0, 0.0, 0.0};
	double c3[] = {0.0, (2.0/3.0), 0.0, 0.0, 0.0};
	double c4[] = {0.0, 0.0, (1.0/2.0), 0.0, 0.0};
	double c5[] = {0.0, 0.0, 0.0, (1.0/4.0), 0.0};

	int rowsD = 3, columnsD = 3;
	double d1[] = {(1.0/2.0),-1.0,-1.0};
	double d2[] = {-1.0,1.0,2.0};
	double d3[] = {-1.0,2.0,1.0};

	double* a[] = {a1, a2, a3};
	double* b[] = {b1, b2};
	double* c[] = {c1, c2, c3, c4, c5};
	double* d[] = {d1, d2, d3};


	Matrix* A = newMatrix(rowsA, columnsA);
	Matrix* B = newMatrix(rowsB, columnsB);
	Matrix* C = newMatrix(rowsC, columnsC);
	Matrix* D = newMatrix(rowsD, columnsD);

	Matrix *r;


	fillMatrix(A, a);
	fillMatrix(B, b);
	fillMatrix(C, c);
	fillMatrix(D, d);



	printf("\n\n---------------iterativ---------------\n");

	printf("\n\nMatrix 1");
	r = matpowI(A, 3);
	printMat(r);
	freeMatrix(r);

	printf("\n\nMatrix 2");
	r = matpowI(B, 8);
	printMat(r);
	freeMatrix(r);

	printf("\n\nMatrix 3");

	for(int k = 0; k < 7; k++)
	{
		printf("\n%d. Potenz", k);
		r = matpowI(C, k);
		printMat(r);
		freeMatrix(r);
	}

	printf("\n\nMatrix 4");
	r = matpowI(C, 5);
	printMat(r);
	freeMatrix(r);


	printf("\n\n---------------rekursiv---------------\n");

	printf("\n\nMatrix 1");
	r = matpowR(A, 3);
	printMat(r);
	freeMatrix(r);

	printf("\n\nMatrix 2");
	r = matpowR(B, 8);
	printMat(r);
	freeMatrix(r);

	printf("\n\nMatrix 3");

	for(int k = 0; k < 7; k++)
	{
		printf("\n%d. Potenz", k);
		r = matpowR(C, k);
		printMat(r);
		freeMatrix(r);
	}

	printf("\n\nMatrix 4");
	r = matpowR(C, 5);
	printMat(r);
	freeMatrix(r);


	printf("\n\n----------rekursiv optimiert-----------\n");

	printf("\n\nMatrix 1");
	r = matpow(A, 3);
	printMat(r);
	freeMatrix(r);

	printf("\n\nMatrix 2");
	r = matpow(B, 8);
	printMat(r);
	freeMatrix(r);

	printf("\n\nMatrix 3");

	for(int k = 0; k < 7; k++)
	{
		printf("\n%d. Potenz", k);
		r = matpow(C, k);
		printMat(r);
		freeMatrix(r);
	}

	printf("\n\nMatrix 4");
	r = matpow(C, 5);
	printMat(r);
	freeMatrix(r);


	freeMatrix(A);
	freeMatrix(B);
	freeMatrix(C);
	freeMatrix(D);
}


void printVec(Vector* x)
{
	printf("\n");

	for(int i = 0; i < x->size; i++)
	{
		printf("%f\n", x->vec[i]);
	}
}


void printMat(Matrix* A)
{
	printf("\n");

	for(int i = 0; i < A->rows; i++)
	{
		for(int j = 0; j < A->columns; j++)
		{
			printf("%f\t", A->mat[i][j]);
		}

		printf("\n");
	}
}
