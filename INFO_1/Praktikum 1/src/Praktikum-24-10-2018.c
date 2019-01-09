/*
 ============================================================================
 Name        : Praktikum-24-10-2018.c
 Author      : Phillip Seeliger
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	/*float a, b, c;

	a = 3.141;
	b = 2.718;

	c = a + b;

	printf("%f", c);*/

	for(int i = 1; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	int q, n;
	int sum = 0, qsum = 0;

	printf("n\t|n*n\t|s(n)\t|q(n)\n");
	printf("-----------------------------\n");

	for(n = 1; n <= 10; n++)
	{
		q = n*n;
		sum += n;
		qsum += q;

		printf("%d\t|%d\t|%d\t|%d\n", n, q, sum, qsum);
	}

	return 0;
}
