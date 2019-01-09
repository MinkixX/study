#include <stdio.h>
#include "numbers.h"

int main(int argc, char *argv[])
{
	char *str = "";
	int x;

	if(argc > 1)
	{
		str = argv[1];
	}

	if(str == "")
	{
		char binBuf[DIGITS + 1];
		char octBuf[DIGITS + 1];
		char hexBuf[DIGITS + 1];

		printf("|dez\t|bin\t\t |oct\t\t  |hex\t\t   |\n");
		printf("------------------------------------------------------------\n");

		for(int i = -65; i <= 65; i++)
		{
			intToBinary(i, binBuf);
			intToOctal(i, octBuf);
			intToHex(i, hexBuf);

			printf("|%i\t|%s|%s|%s|\n", i, binBuf, octBuf, hexBuf);
		}
	}
	else
	{
		char buf[DIGITS + 1];

		x = stringToInt(str);
		printf("Zeichenkette \"%s\" als int:%d\n", str, x);

		intToBinary(x, buf);
		printf ("Zahl int:%d als Binaerzahl: %s\n", x, buf);

		intToOctal(x, buf);
		printf ("Zahl int:%d als Octalzahl: %s\n", x, buf);

		intToHex(x, buf);
		printf ("Zahl int:%d als Hexadezimalzahl: %s\n", x, buf);
	}

	return 0;
}
