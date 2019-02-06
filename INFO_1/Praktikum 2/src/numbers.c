#include "numbers.h"

int charToInt(char c)
{
	if(c <= '9')
		return c - '0';
	else if(c <= 'F')
		return c - '7';
	else if(c <= 'f')
		return c - 'W';
	else
		return 0;
}

char intToChar(int i)
{
	if(i < 10)
		return '0' + i;
	else
		return '7' + i;
}

int stringLen(char str[])
{
	int size = 0;

	while(str[size] != '\0') //Länge bis binäre Null
	{
		size++;
	}

	return size;
}

int stringToInt(char str[])
{
	int num = 0, size = stringLen(str);
	int exp, dec, shift, base, neg;

	if(str[0] == '-') //Überprüfen ob Zahl negativ
	{
		neg = 1;
		shift = 1; //Anfang der Schleife verschieben wegen Vorzeichen
	}
	else
	{
		neg = 0;
		shift = 0;
	}

	if(str[1 + shift] == 'x') //Basis bestimmen (Aufg 2)
	{
		base = 16;
		shift += 2;
	}
	else if(str[0 + shift] == '0')
	{
		base = 8;
		shift += 1;
	}
	else
	{
		base = 10;
	}

	for(int i = shift; i < size; i++)
	{
		exp = 1;

		for(int n = 1; n < (size - i); n++) //Wertigkeit der Stelle
		{
			exp *= base;
		}

		dec = charToInt(str[i]);

		if(neg == 1)
			num -=  dec * exp; //Wertigkeit mit Stelle multiplizieren
		else
			num += dec * exp;
	}

	return num;
}

void changeBase(int i, char str[], int base)
{
	char buf[DIGITS + 1];
	int num, mod, j, k;

	for(int i = 0; i <= DIGITS; i++) //Array mit 0 füllen
	{
		str[i] = '0';
	}

	if(i < 0) //Absoluten Betrag von i bestimmen
		num = -i;
	else
		num = i;

	for(j = 0; num != 0; j++) //Wert durch Modulo Division umrechnen
	{
		mod = num % base;
		num = (num - mod) / base;

		buf[j] = intToChar(mod);
	}

	for(k = 0; k < j; k++) //Array umkehrern
	{
		str[DIGITS - 1 - k] = buf[k];
	}

	str[DIGITS] = '\0'; //Binäre Null an letzte Stelle setzen
}

void intToOctal(int i, char str[])
{
	changeBase(i, str, 8); //In Octal konvertieren
	int size = stringLen(str);

	if(i < 0) //Überprüfen ob negativ und ggf. Komplement bilden
	{
		str[0] = '7';

		for(int j = 1; j < size; j++) //Negieren
		{
			str[j] = intToChar(7 - charToInt(str[j]));
		}

		for(int k = size - 1; k > 0; k--) //1 Addieren
		{
			if(charToInt(str[k]) < 7)
			{
				str[k] = intToChar(charToInt(str[k]) + 1);
				break;
			}
			else
			{
				str[k] = '0';
			}
		}
	}
}

void intToHex(int i, char str[])
{
	changeBase(i, str, 16); //In Octal konvertieren

	int size = stringLen(str);

	if(i < 0) //Überprüfen ob negativ und ggf. Komplement bilden
	{
		str[0] = 'F';

		for(int j = 1; j < size; j++) //Negieren
		{
			str[j] = intToChar(15 - charToInt(str[j]));
		}

		for(int k = size - 1; k > 0; k--) //1 Addieren
		{
			if(charToInt(str[k]) < 15)
			{
				str[k] = intToChar(charToInt(str[k]) + 1);
				break;
			}
			else
			{
				str[k] = '0';
			}
		}
	};
}

void intToBinary(int i, char str[])
{
	changeBase(i, str, 2); //In Binär konvertieren
	int size = stringLen(str);

	if(i < 0) //Überprüfen ob negativ und ggf. Komplement bilden
	{
		str[0] = '1';

		for(int j = 1; j < size; j++) //Negieren
		{
			if(str[j] == '1')
				str[j] = '0';
			else
				str[j] = '1';
		}

		for(int k = size - 1; k > 0; k--) //1 Addieren
		{
			if(str[k] == '0')
			{
				str[k] = '1';
				break;
			}
			else
			{
				str[k] = '0';
			}
		}
	}
}
