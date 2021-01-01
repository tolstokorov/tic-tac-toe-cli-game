#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct tableCell {
	char
		XorO,
		flag,
		topOfTheCell,
		lateralOfTheCell,
		bottomOfTheCell;
} x[9] = {
{ ' ', 0, ' ', ' ', ' ' },{ ' ', 0, ' ', ' ', ' ' },{ ' ', 0, ' ', ' ', ' ' },
{ ' ', 0, ' ', ' ', ' ' },{ ' ', 0, ' ', ' ', ' ' },{ ' ', 0, ' ', ' ', ' ' },
{ ' ', 0, ' ', ' ', ' ' },{ ' ', 0, ' ', ' ', ' ' },{ ' ', 0, ' ', ' ', ' ' }
};

char level;
char firstOrSecond = 'X';

void printTable(void);
void toContinue(void);
void hello(void);
void rules(void);
void askLevel(void);
void startFirstOrSecond(void);
void theGame(void);
char analysis(char);
char you(void);
char computer(void);
char finish(char);

extern char algorithm(void);



int main(void) {

	hello();

	rules();

	askLevel();

	startFirstOrSecond();

	theGame();

	toContinue();

	return 0;
}



void toContinue(void) {

	//printf("\n\n Press [Space] to continue...");

	char go = 1;
	while (go != ' ')
		go = (char)_getch();

	system("cls");

	return;
}

void hello(void) {

	//printf("\n\tHello!\n");

	printf("\n"
		"\t\xDB   \xDB  \xDB\xDF\xDF\xDF\xDF  \xDB      \xDB      \xDB\xDF\xDF\xDF\xDB  \xDB\n"
		"\t\xDB   \xDB  \xDB      \xDB      \xDB      \xDB   \xDB  \xDB\n"
		"\t\xDB\xDF\xDF\xDF\xDB  \xDB\xDF\xDF\xDF   \xDB      \xDB      \xDB   \xDB  \xDB\n"
		"\t\xDB   \xDB  \xDB      \xDB      \xDB      \xDB   \xDB  \xDB\n"
		"\t\xDB   \xDB  \xDB\xDC\xDC\xDC\xDC  \xDB\xDC\xDC\xDC\xDC  \xDB\xDC\xDC\xDC\xDC  \xDB\xDC\xDC\xDC\xDB  \xDC\n"
	);

	toContinue();

	return;
}

void rules(void) {

	x[6].XorO = '7'; x[7].XorO = '8'; x[8].XorO = '9';
	x[3].XorO = '4'; x[4].XorO = '5'; x[5].XorO = '6';
	x[0].XorO = '1'; x[1].XorO = '2'; x[2].XorO = '3';

	printTable();

	printf("\n   Here are the rules of the game.\n");
	printf("\n   Here are the rules of the game.\n");
	printf("\n   Here are the rules of the game.\n");
	printf("\n   Here are the rules of the game.\n");
	printf("\n   Here are the rules of the game.\n");

	toContinue();

	return;
}

void askLevel(void) {

	printf("\n"
		"\tSelect a level:\n\n"
		"\tLevel \"God\"    (algorithm \xFC \b4) - [4]\n"
		"\tLevel \"Hard\"   (algorithm \xFC \b3) - [3]\n"
		"\tLevel \"Medium\" (algorithm \xFC \b2) - [2]\n"
		"\tLevel \"Easy\"   (algorithm \xFC \b1) - [1]\n"
		"\tLevel \"Fool\"   (random)       - [0]\n\n"
		"\tPress the corresponding number button >> "
		);
	char c = 0;
	while (c != '4' && c != '3' && c != '2' && c != '1' && c != '0')
		c = (char)_getch();

	system("cls");

	switch (c) {
	case '1':
		printf("\n\n\tLevel \"Easy\" (algorithm \xFC \b1)\n");
		toContinue();
		level = 1;
		return;
	case '2':
		printf("\n\n\tLevel \"Medium\" (algorithm \xFC \b2)\n");
		toContinue();
		level = 2;
		return;
	case '3':
		printf("\n\n\tLevel \"Hard\" (algorithm \xFC \b3)\n");
		toContinue();
		level = 3;
		return;
	case '4':
		printf("\n\n"
			"\tThis algorithm is not yet ready.\n\n"
			"\tRedirection to  >>>\n\n"
			"\tLevel \"Hard\" (algorithm \xFC \b3)\n"); 
		//printf("\n\n\tLevel \"God\" (algorithm \xFC \b4)\n");
		toContinue();
		level = 4;
		return;
	default:
		printf("\n\n\tLevel \"Fool\" (random)\n");
		toContinue();
		return;
	}

	return;
}

void startFirstOrSecond(void) {

	printf("\n"
		"\tWill you start first or second?\n"
		"\tPress [1] or [2] >> ");
	char c = 0;
	while (c != '1' && c != '2')
		c = (char)_getch();

	system("cls");

	printf("\n%s\n",
		(c == '1') ?
		"\t\t\t      \xDB\xDB   \xDB\xDB\n\t\t\t       \xDB\xDB \xDB\xDB\n\t\t\t        \xDB\xDB\xDB\n\t\t\t       \xDB\xDB \xDB\xDB\n You start first and play for \xDB\xDB   \xDB\xDB" :
		"\t\t\t        \xDB\xDB\xDB\xDB\xDB\n\t\t\t       \xDB\xDB   \xDB\xDB\n\t\t\t       \xDB\xDB   \xDB\xDB\n You start second and play for  \xDB\xDB\xDB\xDB\xDB");

	toContinue();

	if (c == '2')
		firstOrSecond = 'O';

	return;
}

void theGame(void) {

	x[0].XorO = x[1].XorO = x[2].XorO = x[3].XorO = x[4].XorO = x[5].XorO = x[6].XorO = x[7].XorO = x[8].XorO = ' ';

	printTable();

	if (firstOrSecond == 'X')
		while (x[0].flag + x[1].flag + x[2].flag + x[3].flag + x[4].flag + x[5].flag + x[6].flag + x[7].flag + x[8].flag != 12) {

			x[you() - 1].XorO = 'X';
			system("cls");
			if (finish('X') == 1) {
				printf("\n\t      You win!\n\n");
				return;
			}
			printTable();

			x[computer() - 1].XorO = 'O';
			system("cls");
			if (finish('O') == 0) {
				printf("\n\t  The computer win\n\n");
				return;
			}
			printTable();

		}
	else
		while (x[0].flag + x[1].flag + x[2].flag + x[3].flag + x[4].flag + x[5].flag + x[6].flag + x[7].flag + x[8].flag != 12) {

			x[computer() - 1].XorO = 'X';
			system("cls");
			if (finish('X') == 0) {
				printf("\n\t  The computer win\n\n");
				return;
			}
			printTable();

			x[you() - 1].XorO = 'O';
			system("cls");
			if (finish('O') == 1) {
				printf("\n\t      You win!\n\n");
				return;
			}
			printTable();
		}

	int ii = 0;
	while (x[ii].flag != 0)
		++ii;

	x[ii].XorO = 'X';
	x[ii].flag = 1;

	if (finish(firstOrSecond) == 1) {
		printf("\n\t      You win!\n\n");
		return;
	}
	else if (finish(firstOrSecond) == 0) {
		printf("\n\t  The computer win\n\n");
		return;
	}

	system("cls");
	printTable();

	printf("\n\t       Draw\n\n");

	return;
}

char analysis(char go) {

	char answer = 0;

	if ((x[go - 1].flag == 1) || (x[go - 1].flag == 2))
		answer = 1;
	else
		answer = 0;

	return answer;
}

char you(void) {
	char go = 0;
	char an = 1;

	while (an != 0) {
		go = 0;
		while (go <= '0' || go > '9')
			go = (char)_getch();
		an = analysis(go - '0');
	}

	if (firstOrSecond == 'X')
		x[go - '0' - 1].flag = 1;
	else if (firstOrSecond == 'O')
		x[go - '0' - 1].flag = 2;

	return go - '0';
}

char computer(void) {
	char go = 0;

	switch (level) {
	case 1:
	case 2:
	case 3:
	case 4:
		go = algorithm();
		break;
	default:
		srand((unsigned int)time(NULL));
		char an = 1;
		while (an != 0) {
			go = rand() % 9 + 1;
			an = analysis(go);
		}
		break;
	}

	if (firstOrSecond == 'X')
		x[go - 1].flag = 2;
	else if (firstOrSecond == 'O')
		x[go - 1].flag = 1;

	return go;
}

char finish(char sign) {

	if (
		((x[0].XorO == sign) && (x[1].XorO == sign) && (x[2].XorO == sign)) ||
		((x[3].XorO == sign) && (x[4].XorO == sign) && (x[5].XorO == sign)) ||
		((x[6].XorO == sign) && (x[7].XorO == sign) && (x[8].XorO == sign)) ||

		((x[0].XorO == sign) && (x[3].XorO == sign) && (x[6].XorO == sign)) ||
		((x[1].XorO == sign) && (x[4].XorO == sign) && (x[7].XorO == sign)) ||
		((x[2].XorO == sign) && (x[5].XorO == sign) && (x[8].XorO == sign)) ||

		((x[0].XorO == sign) && (x[4].XorO == sign) && (x[8].XorO == sign)) ||

		((x[2].XorO == sign) && (x[4].XorO == sign) && (x[6].XorO == sign))
		) {

		system("cls");

		if ((x[6].XorO == sign) && (x[7].XorO == sign) && (x[8].XorO == sign)) {
			x[6].topOfTheCell = x[7].topOfTheCell = x[8].topOfTheCell = '\xDF';
			x[6].lateralOfTheCell = x[7].lateralOfTheCell = x[8].lateralOfTheCell = '\xDB';
			x[6].bottomOfTheCell = x[7].bottomOfTheCell = x[8].bottomOfTheCell = '\xDC';
		}
		else if ((x[3].XorO == sign) && (x[4].XorO == sign) && (x[5].XorO == sign)) {
			x[3].topOfTheCell = x[4].topOfTheCell = x[5].topOfTheCell = '\xDF';
			x[3].lateralOfTheCell = x[4].lateralOfTheCell = x[5].lateralOfTheCell = '\xDB';
			x[3].bottomOfTheCell = x[4].bottomOfTheCell = x[5].bottomOfTheCell = '\xDC';
		}
		else if ((x[0].XorO == sign) && (x[1].XorO == sign) && (x[2].XorO == sign)) {
			x[0].topOfTheCell = x[1].topOfTheCell = x[2].topOfTheCell = '\xDF';
			x[0].lateralOfTheCell = x[1].lateralOfTheCell = x[2].lateralOfTheCell = '\xDB';
			x[0].bottomOfTheCell = x[1].bottomOfTheCell = x[2].bottomOfTheCell = '\xDC';
		}


		if ((x[0].XorO == sign) && (x[3].XorO == sign) && (x[6].XorO == sign)) {
			x[0].topOfTheCell = x[3].topOfTheCell = x[6].topOfTheCell = '\xDF';
			x[0].lateralOfTheCell = x[3].lateralOfTheCell = x[6].lateralOfTheCell = '\xDB';
			x[0].bottomOfTheCell = x[3].bottomOfTheCell = x[6].bottomOfTheCell = '\xDC';
		}
		else if ((x[1].XorO == sign) && (x[4].XorO == sign) && (x[7].XorO == sign)) {
			x[1].topOfTheCell = x[4].topOfTheCell = x[7].topOfTheCell = '\xDF';
			x[1].lateralOfTheCell = x[4].lateralOfTheCell = x[7].lateralOfTheCell = '\xDB';
			x[1].bottomOfTheCell = x[4].bottomOfTheCell = x[7].bottomOfTheCell = '\xDC';
		}
		else if ((x[2].XorO == sign) && (x[5].XorO == sign) && (x[8].XorO == sign)) {
			x[2].topOfTheCell = x[5].topOfTheCell = x[8].topOfTheCell = '\xDF';
			x[2].lateralOfTheCell = x[5].lateralOfTheCell = x[8].lateralOfTheCell = '\xDB';
			x[2].bottomOfTheCell = x[5].bottomOfTheCell = x[8].bottomOfTheCell = '\xDC';
		}


		if ((x[0].XorO == sign) && (x[4].XorO == sign) && (x[8].XorO == sign)) {
			x[0].topOfTheCell = x[4].topOfTheCell = x[8].topOfTheCell = '\xDF';
			x[0].lateralOfTheCell = x[4].lateralOfTheCell = x[8].lateralOfTheCell = '\xDB';
			x[0].bottomOfTheCell = x[4].bottomOfTheCell = x[8].bottomOfTheCell = '\xDC';
		}

		if ((x[2].XorO == sign) && (x[4].XorO == sign) && (x[6].XorO == sign)) {
			x[2].topOfTheCell = x[4].topOfTheCell = x[6].topOfTheCell = '\xDF';
			x[2].lateralOfTheCell = x[4].lateralOfTheCell = x[6].lateralOfTheCell = '\xDB';
			x[2].bottomOfTheCell = x[4].bottomOfTheCell = x[6].bottomOfTheCell = '\xDC';
		}

		printTable();

		if (firstOrSecond == sign)
			return 1;
		else
			return 0;
	}

	return -1;
}

void printTable(void) {

	printf("\n\t\xDA\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xC4\xBF\n");

	printf("\t\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3\n", x[6].lateralOfTheCell, x[6].topOfTheCell, x[6].topOfTheCell, x[6].topOfTheCell, x[6].lateralOfTheCell, x[7].lateralOfTheCell, x[7].topOfTheCell, x[7].topOfTheCell, x[7].topOfTheCell, x[7].lateralOfTheCell, x[8].lateralOfTheCell, x[8].topOfTheCell, x[8].topOfTheCell, x[8].topOfTheCell, x[8].lateralOfTheCell);
	printf("\t\xB3%c %c %c\xB3%c %c %c\xB3%c %c %c\xB3\n", x[6].lateralOfTheCell, x[6].XorO, x[6].lateralOfTheCell, x[7].lateralOfTheCell, x[7].XorO, x[7].lateralOfTheCell, x[8].lateralOfTheCell, x[8].XorO, x[8].lateralOfTheCell);
	printf("\t\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3\n", x[6].lateralOfTheCell, x[6].bottomOfTheCell, x[6].bottomOfTheCell, x[6].bottomOfTheCell, x[6].lateralOfTheCell, x[7].lateralOfTheCell, x[7].bottomOfTheCell, x[7].bottomOfTheCell, x[7].bottomOfTheCell, x[7].lateralOfTheCell, x[8].lateralOfTheCell, x[8].bottomOfTheCell, x[8].bottomOfTheCell, x[8].bottomOfTheCell, x[8].lateralOfTheCell);

	printf("\t\xC3\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xB4\n");

	printf("\t\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3\n", x[3].lateralOfTheCell, x[3].topOfTheCell, x[3].topOfTheCell, x[3].topOfTheCell, x[3].lateralOfTheCell, x[4].lateralOfTheCell, x[4].topOfTheCell, x[4].topOfTheCell, x[4].topOfTheCell, x[4].lateralOfTheCell, x[5].lateralOfTheCell, x[5].topOfTheCell, x[5].topOfTheCell, x[5].topOfTheCell, x[5].lateralOfTheCell);
	printf("\t\xB3%c %c %c\xB3%c %c %c\xB3%c %c %c\xB3\n", x[3].lateralOfTheCell, x[3].XorO, x[3].lateralOfTheCell, x[4].lateralOfTheCell, x[4].XorO, x[4].lateralOfTheCell, x[5].lateralOfTheCell, x[5].XorO, x[5].lateralOfTheCell);
	printf("\t\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3\n", x[3].lateralOfTheCell, x[3].bottomOfTheCell, x[3].bottomOfTheCell, x[3].bottomOfTheCell, x[3].lateralOfTheCell, x[4].lateralOfTheCell, x[4].bottomOfTheCell, x[4].bottomOfTheCell, x[4].bottomOfTheCell, x[4].lateralOfTheCell, x[5].lateralOfTheCell, x[5].bottomOfTheCell, x[5].bottomOfTheCell, x[5].bottomOfTheCell, x[5].lateralOfTheCell);
	printf("\t\xC3\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xC4\xB4\n");


	printf("\t\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3\n", x[0].lateralOfTheCell, x[0].topOfTheCell, x[0].topOfTheCell, x[0].topOfTheCell, x[0].lateralOfTheCell, x[1].lateralOfTheCell, x[1].topOfTheCell, x[1].topOfTheCell, x[1].topOfTheCell, x[1].lateralOfTheCell, x[2].lateralOfTheCell, x[2].topOfTheCell, x[2].topOfTheCell, x[2].topOfTheCell, x[2].lateralOfTheCell);
	printf("\t\xB3%c %c %c\xB3%c %c %c\xB3%c %c %c\xB3\n", x[0].lateralOfTheCell, x[0].XorO, x[0].lateralOfTheCell, x[1].lateralOfTheCell, x[1].XorO, x[1].lateralOfTheCell, x[2].lateralOfTheCell, x[2].XorO, x[2].lateralOfTheCell);
	printf("\t\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3%c%c%c%c%c\xB3\n", x[0].lateralOfTheCell, x[0].bottomOfTheCell, x[0].bottomOfTheCell, x[0].bottomOfTheCell, x[0].lateralOfTheCell, x[1].lateralOfTheCell, x[1].bottomOfTheCell, x[1].bottomOfTheCell, x[1].bottomOfTheCell, x[1].lateralOfTheCell, x[2].lateralOfTheCell, x[2].bottomOfTheCell, x[2].bottomOfTheCell, x[2].bottomOfTheCell, x[2].lateralOfTheCell);

	printf("\t\xC0\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xC4\xD9\n");

	return;
}