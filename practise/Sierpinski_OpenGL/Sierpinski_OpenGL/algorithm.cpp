#include"algorithm.h"


SierpinskiTriangle setupTriangle(float positions[], unsigned int count)
{
	SierpinskiTriangle triangle =
	{
		(float*)malloc(count*sizeof(float)),
		count,
		0
	};
	
	memcpy_s(triangle.positions, count*sizeof(float), positions, count*sizeof(float));

	return triangle;
}

SierpinskiTriangle sierpinski(SierpinskiTriangle* oldTriangle)
{
	SierpinskiTriangle newTriangle =
	{
		(float*)malloc(oldTriangle->count * 3 * sizeof(float)),
		oldTriangle->count * 3,
		oldTriangle->step+1
	};

	for (unsigned int i = 0; i < oldTriangle->count; i+=6)
	{
		unsigned int i2 = i * 3;
		unsigned int size = sizeof(float);

		/*upper triangle - vertecies clockwise*/
		newTriangle.positions[i2]	= oldTriangle->positions[i];
		newTriangle.positions[i2+1] = oldTriangle->positions[i+1];

		newTriangle.positions[i2+2] = (oldTriangle->positions[i] + oldTriangle->positions[i+2]) / 2.0f;
		newTriangle.positions[i2+3] = (oldTriangle->positions[i+1] + oldTriangle->positions[i+3]) / 2.0f;

		newTriangle.positions[i2+4]	= (oldTriangle->positions[i] + oldTriangle->positions[i+4]) / 2.0f;
		newTriangle.positions[i2+5] = (oldTriangle->positions[i+1] + oldTriangle->positions[i+5]) / 2.0f;

		/*lower right triangle - vertecies clockwise*/
		newTriangle.positions[i2+6] = newTriangle.positions[i2+2];
		newTriangle.positions[i2+7] = newTriangle.positions[i2+3];

		newTriangle.positions[i2+8] = oldTriangle->positions[i+2];
		newTriangle.positions[i2+9] = oldTriangle->positions[i+3];

		newTriangle.positions[i2+10] = oldTriangle->positions[i];
		newTriangle.positions[i2+11] = (oldTriangle->positions[i+3] + oldTriangle->positions[i+5]) / 2.0f;

		/*lower left triangle - vertecies clockwise*/
		newTriangle.positions[i2+12] = newTriangle.positions[i2+4];
		newTriangle.positions[i2+13] = newTriangle.positions[i2+5];

		newTriangle.positions[i2+14] = newTriangle.positions[i2+10];
		newTriangle.positions[i2+15] = newTriangle.positions[i2+11];

		newTriangle.positions[i2+16] = oldTriangle->positions[i+4];
		newTriangle.positions[i2+17] = oldTriangle->positions[i+5];
	}

	free(oldTriangle->positions);

	return newTriangle;
}