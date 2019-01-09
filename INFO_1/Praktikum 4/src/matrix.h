/*
 * matrix.h
 *
 *  Created on: Dec 2, 2018
 *      Author: phillip
 */

#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_


//Addition of vector x and vector y, returning z
void vecplus(int sizeX, int sizeY, double* x, double* y, double* z);

//Multiplication of vector x and vector y, returning z
void vecmult(int sizeX, int sizeY, double* x, double* y, double* z);

//Addition of matrix A and matrix B, returning C
void matplus(int sizeAx, int sizeAy, int sizeBx, int sizeBy, double** A, double** B, double** C);

//Multiplication of matrix A and matrix B, returning C
void matmult(int sizeAx, int sizeAy, int sizeBx, int sizeBy, double** A, double** B, double** C);

//Multiplication of matrix A and vector B, returning C
void matmulvec(int sizeAx, int sizeAy, int sizeX, double** A, double* x, double* y);


#endif /* SRC_MATRIX_H_ */
