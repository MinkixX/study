/*
 * matrix.c
 *
 *  Created on: Dec 2, 2018
 *      Author: phillip
 */
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


Vector* newVector(unsigned int size)
{
	Vector* vec = (Vector*)malloc(sizeof(Vector));

	vec->size = size;
	vec->vec = (double*)malloc(size * sizeof(double));

	return vec;
}


Matrix* newMatrix(unsigned int rows, unsigned int columns)
{
	Matrix* mat = (Matrix*)malloc(sizeof(Matrix)); //direct leak

	mat->rows = rows;
	mat->columns = columns;
	mat->mat = (double**)malloc(columns * sizeof(double*)); //indirect leak

	for(int i = 0; i < columns; i++)
	{
		mat->mat[i] = (double*)malloc(rows * sizeof(double)); //indirect leak
	}


	return mat;
}


Vector* vecCopy(Vector* x)
{
	Vector* y = newVector(x->size);

	for(int i = 0; i < x->size; i++)
		y->vec[i] = x->vec[i];

	return y;
}


Matrix* matCopy(Matrix* A)
{
	Matrix* B = newMatrix(A->rows, A->columns);

	for(int i = 0; i < A->columns; i++)
		for(int j = 0; j < A->rows; j++)
			B->mat[i][j] = A->mat[i][j];

	return B;
}


void freeVector(Vector* vec)
{
	free(vec->vec);
	free(vec);
}


void freeMatrix(Matrix* mat)
{
	for(int i = 0; i < mat->columns; i++)
	{
		free(mat->mat[i]);
	}

	free(mat->mat);
	free(mat);
}


void fillVector(Vector* vec, double data[])
{
	for(int i = 0; i < vec->size; i++)
	{
		vec->vec[i] = data[i];
	}
}


void fillMatrix(Matrix* mat, double* data[])
{
	for(int i = 0; i < mat->columns; i++)
	{
		for(int j = 0; j < mat->rows; j++)
		{
			mat->mat[i][j] = data[i][j];
		}
	}
}

//Addition of vector x and vector y, returning z
Vector* vecplus(Vector* x,  Vector* y)
{
	Vector*	z = newVector(x->size);

	if(x->size == y->size)
	{
		for(int i = 0; i < x->size; i++)
		{
			z->vec[i] = x->vec[i] + y->vec[i];
		}
	}
	else
	{
		printf("\nDie Vektoren müssen von gleicher Größe sein!");
		exit(-1);
	}

	return z;
}

//Multiplication of vector x and vector y, returning z
Vector* vecmult(Vector* x,  Vector* y)
{
	Vector*	z = newVector(x->size);

	if(x->size == y->size)
	{
		for(int i = 0; i < x->size; i++)
		{
			z->vec[i] = x->vec[i] * y->vec[i];
		}
	}
	else if(x->size == 1)
	{
		for(int i = 0; i < y->size; i++)
		{
			z->vec[i] = x->vec[0] * y->vec[i];
		}
	}
	else if(y->size == 1)
	{
		for(int i = 0; i < x->size; i++)
		{
			z->vec[i] = x->vec[i] * y->vec[0];
		}
	}
	else
	{
		printf("\nDie Vektoren müssen von gleicher Größe sein oder mit einem Skalar multipliziert werden!");
		exit(-1);
	}

	return z;
}

//Addition of matrix A and matrix B, returning C
Matrix* matplus(Matrix* A,  Matrix* B)
{
	Matrix* C = newMatrix(A->rows, A->columns);

	if(A->rows == B->rows && A->columns == B->columns)
	{
		for(int i = 0; i < A->rows; i++)
		{
			for(int j = 0; j < A->columns; j++)
			{
				C->mat[j][i] = A->mat[j][i] + B->mat[j][i];
			}
		}
	}
	else
	{
		printf("\nDie Matrizen müssen von gleicher Größe sein!");
		exit(-1);
	}

	return C;
}

//Multiplication of matrix A and matrix B, returning C
Matrix* matmult(Matrix* A,  Matrix* B)
{
	Matrix* C = newMatrix(A->rows, B->columns);

	if(A->columns == B->rows)
	{
		for(int i = 0; i < A->rows; i++)
		{
			for(int j = 0; j < B->columns; j++)
			{
				C->mat[j][i] = 0;

				for(int k = 0; k < B->rows; k++)
				{
					C->mat[j][i] += A->mat[k][i] * B->mat[j][k];
				}
			}
		}
	}
	else
	{
		printf("\nDie Anzahl der Spalten von Matrix A muss der Anzahl der Zeilen von Matrix B entsprechen!");
		exit(-1);
	}

	return C;
}

//Multiplication of matrix A and vector x, returning vector y
Vector* matmulvec(Matrix* A,  Vector* x)
{
	Vector*	y = newVector(x->size);

	if(A->columns == x->size)
	{
		for(int i = 0; i < A->columns; i++)
		{
			y->vec[i] = 0;

			for(int j = 0; j < A->rows; j++)
			{
				y->vec[i] += A->mat[i][j] * x->vec[i];
			}
		}
	}
	else
	{
		printf("\nDie Anzahl der Spalten von Matrix A muss der Anzahl der Zeilen von Vektor B entsprechen!");
		exit(-1);
	}

	return y;
}


Matrix* unityMat(unsigned int rows, unsigned int columns)
{
	Matrix* mat = newMatrix(rows, columns);

	for(int i = 0; i < columns; i++)
	{
		for(int j = 0; j < rows; j++)
		{
			mat->mat[i][j] = (i == j);
		}
	}

	return mat;
}

//Power k of Matrix A, returning B (recursive, optimized)
Matrix* matpow(Matrix* A, unsigned int k)
{
	Matrix* B;
	unsigned int q;

	if(k > 1)
	{
		if(k & 1)
		{
			q = (k - 1) / 2;
			Matrix* temp = matpow(A, q);
			Matrix* temp2 = matmult(temp, temp);

			B = matmult(A, temp2);

			freeMatrix(temp);
			freeMatrix(temp2);
		}
		else
		{
			q = k / 2;
			Matrix* temp = matpow(A, q);

			B = matmult(temp, temp);

			freeMatrix(temp);
		}
	}
	else if(k == 1)
	{
		B = matCopy(A);
	}
	else
	{
		B = unityMat(A->rows, A->columns);
	}


	return B;
}

//Power k of Matrix A, returning B (recursive)
Matrix* matpowR(Matrix* A, unsigned int k)
{
	Matrix* B;

	if(k > 0)
	{
		Matrix* temp = matpowR(A, --k);
		B = matmult(A, temp);

		freeMatrix(temp);
	}
	else
	{
		B = unityMat(A->rows, A->columns);
	}

	return B;
}

//Power k of Matrix A, returning B (iterative)
Matrix* matpowI(Matrix* A, unsigned int k)
{
	Matrix* B;

	if(k > 1)
	{
		B = matmult(A, A);

		for(int i = 2; i < k; i++)
		{
			Matrix* temp = matmult(A, B);

			freeMatrix(B);
			B = matCopy(temp);

			freeMatrix(temp);
		}
	}
	else if(k == 1)
	{
		B = matCopy(A);
	}
	else
	{
		B = unityMat(A->rows, A->columns);
	}

	return B;
}
