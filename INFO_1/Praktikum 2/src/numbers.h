/* Verwende zur Darstellung maximal
	DIGITS lange Zeichenketten */
#define DIGITS 16

/* Verwandle ein ASCII char in die entsprechende
	Ganzzahl und gebe diese als Ergebnis zurueck. */
int charToInt(char c);

/* Verwandle eine Ganzzahl in das entsprechende
	ASCII Zeichen und gebe diese als Ergebnis zurueck. */
char intToChar(int i);

int stringLen(char str[]);

/* Bilde aus der Zeichenkette str eine Ganzzahl zur Basis 10
	und gebe diese als Ergebnis zurueck. */
int stringToInt(char str[]);

void changeBase(int i, char str[], int base);

/* Schreibt Binaerdarstellung der
	Ganzzahl i nach str. */
void intToBinary(int i, char str[]);

void intToOctal(int i, char str[]);

void intToHex(int i, char str[]);
