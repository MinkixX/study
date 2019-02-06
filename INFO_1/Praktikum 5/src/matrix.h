/*
 * matrix.h
 *
 *  Created on: Dec 2, 2018
 *      Author: phillip
 */

#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_


typedef struct Matrix
{
	unsigned int rows, columns;

	double** mat;
} Matrix;


typedef struct Vector
{
	unsigned int size;

	double* vec;
} Vector;


Vector* newVector(unsigned int size);

Matrix* newMatrix(unsigned int rows, unsigned int columns);

Vector* vecCopy(Vector* x);

Matrix* matCopy(Matrix* A);

void freeVector(Vector* vec);

void freeMatrix(Matrix* mat);

void fillVector(Vector* vec, double data[]);

void fillMatrix(Matrix* mat, double* data[]);

//Addition of vector x and vector y, returning z
Vector* vecplus(Vector* x, Vector* y);

//Multiplication of vector x and vector y, returning z
Vector* vecmult(Vector* x,  Vector* y);

//Addition of matrix A and matrix B, returning C
Matrix* matplus(Matrix* A,  Matrix* B);

//Multiplication of matrix A and matrix B, returning C
Matrix* matmult(Matrix* A,  Matrix* B);

//Multiplication of matrix A and vector B, returning C
Vector* matmulvec(Matrix* A,  Vector* x);

Matrix* unityMat(unsigned int rows, unsigned int columns);

//Power k of Matrix A, returning B (recursive)
Matrix* matpow(Matrix* A, unsigned int k);

//Power k of Matrix A, returning B (recursive)
Matrix* matpowR(Matrix* A, unsigned int k);

//Power k of Matrix A, returning B (iterative)
Matrix* matpowI(Matrix* A, unsigned int k);


#endif /* SRC_MATRIX_H_ */
