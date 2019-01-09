/*
 * matrix.c
 *
 *  Created on: Dec 2, 2018
 *      Author: phillip
 */
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>


//Addition of vector x and vector y, returning z
void vecplus(int sizeX, int sizeY, double* x, double* y, double* z)
{
	if(sizeX == sizeY)
	{
		for(int i = 0; i < sizeX; i++)
		{
			z[i] = x[i] + y[i];
		}
	}
	else
	{
		printf("\nDie Vektoren müssen von gleicher Größe sein!");
		exit(-1);
	}
}

//Multiplication of vector x and vector y, returning z
void vecmult(int sizeX, int sizeY, double* x, double* y, double* z)
{
	if(sizeX == sizeY)
	{
		for(int i = 0; i < sizeX; i++)
		{
			z[i] = x[i] * y[i];
		}
	}
	else if(sizeX == 1)
	{
		for(int i = 0; i < sizeY; i++)
		{
			z[i] = x[0] * y[i];
		}
	}
	else if(sizeY == 1)
	{
		for(int i = 0; i < sizeX; i++)
		{
			z[i] = x[i] * y[0];
		}
	}
	else
	{
		printf("\nDie Vektoren müssen von gleicher Größe sein oder mit einem Skalar multipliziert werden!");
		exit(-1);
	}
}

//Addition of matrix A and matrix B, returning C
void matplus(int sizeAx, int sizeAy, int sizeBx, int sizeBy, double** A, double** B, double** C)
{
	if(sizeAx == sizeBx && sizeAy == sizeBy)
	{
		for(int i = 0; i < sizeAy; i++)
		{
			for(int j = 0; j < sizeAx; j++)
			{
				C[j][i] = A[j][i] + B[j][i];
			}
		}
	}
	else
	{
		printf("\nDie Matrizen müssen von gleicher Größe sein!");
		exit(-1);
	}
}

//Multiplication of matrix A and matrix B, returning C
void matmult(int sizeAx, int sizeAy, int sizeBx, int sizeBy, double** A, double** B, double** C)
{
	if(sizeAy == sizeBx)
	{
		for(int i = 0; i < sizeAx; i++)
		{
			for(int j = 0; j < sizeBy; j++)
			{
				C[i][j] = 0;

				for(int k = 0; k < sizeBx; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
	}
	else
	{
		printf("\nDie Anzahl der Spalten von Matrix A muss der Anzahl der Zeilen von Matrix B entsprechen!");
		exit(-1);
	}
}

//Multiplication of matrix A and vector x, returning vector y
void matmulvec(int sizeAx, int sizeAy, int sizeX, double** A, double* x, double* y)
{
	if(sizeAx == sizeX)
	{
		for(int i = 0; i < sizeAx; i++)
		{
			y[i] = 0;

			for(int j = 0; j < sizeAy; j++)
			{
				y[i] += A[i][j] * x[i];
			}
		}
	}
	else
	{
		printf("\nDie Anzahl der Spalten von Matrix A muss der Anzahl der Zeilen von Vektor B entsprechen!");
		exit(-1);
	}
}
