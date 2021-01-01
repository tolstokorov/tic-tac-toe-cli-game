#include <stdlib.h>
#include <time.h>

extern struct tableCell {
	char
		XorO,
		flag,
		topOfTheCell,
		lateralOfTheCell,
		bottomOfTheCell;
} x[];
extern char level;
extern char firstOrSecond;

char twoIcons(void);
char against(void);
char oneIcon123(void);
char noIcon12(void);
char oneIcon4(void);
char noIcon34(void);



char algorithm(void) {

	// Заглушка
	//static char a = 10;
	//return --a;

	////////////////////////////

	char c = twoIcons();
	if (c)
		return c;

	c = (level == 1) ? 0 : against();

	if (!c)
		c = (level == 4) ? oneIcon4() : oneIcon123();

	if (c)
		return c;

	return (level == 3 || level == 4) ? noIcon34() : noIcon12();
}



char twoIcons(void) {
	char sign, res;
	if (firstOrSecond == 'X') {
		sign = 'X';
		res = 4;
	}
	else {
		sign = 'O';
		res = 2;
	}

	if (x[0].flag + x[1].flag + x[2].flag == res &&
		x[0].XorO != sign && x[1].XorO != sign && x[2].XorO != sign) {

		if (x[0].flag == 0)
			return 1;
		else if (x[1].flag == 0)
			return 2;
		else if (x[2].flag == 0)
			return 3;

	}
	else if (x[3].flag + x[4].flag + x[5].flag == res &&
		x[3].XorO != sign && x[4].XorO != sign && x[5].XorO != sign) {

		if (x[3].flag == 0)
			return 4;
		else if (x[4].flag == 0)
			return 5;
		else if (x[5].flag == 0)
			return 6;

	}
	else if (x[6].flag + x[7].flag + x[8].flag == res &&
		x[6].XorO != sign && x[7].XorO != sign && x[8].XorO != sign) {

		if (x[6].flag == 0)
			return 7;
		else if (x[7].flag == 0)
			return 8;
		else if (x[8].flag == 0)
			return 9;

	}


	else if (x[0].flag + x[3].flag + x[6].flag == res &&
		x[0].XorO != sign && x[3].XorO != sign && x[6].XorO != sign) {

		if (x[0].flag == 0)
			return 1;
		else if (x[3].flag == 0)
			return 4;
		else if (x[6].flag == 0)
			return 7;

	}
	else if (x[1].flag + x[4].flag + x[7].flag == res &&
		x[1].XorO != sign && x[4].XorO != sign && x[7].XorO != sign) {

		if (x[1].flag == 0)
			return 2;
		else if (x[4].flag == 0)
			return 5;
		else if (x[7].flag == 0)
			return 8;

	}
	else if (x[2].flag + x[5].flag + x[8].flag == res &&
		x[2].XorO != sign && x[5].XorO != sign && x[8].XorO != sign) {

		if (x[2].flag == 0)
			return 3;
		else if (x[5].flag == 0)
			return 6;
		else if (x[8].flag == 0)
			return 9;

	}


	else if (x[0].flag + x[4].flag + x[8].flag == res &&
		x[0].XorO != sign && x[4].XorO != sign && x[8].XorO != sign) {

		if (x[0].flag == 0)
			return 1;
		else if (x[4].flag == 0)
			return 5;
		else if (x[8].flag == 0)
			return 9;

	}
	else if (x[2].flag + x[4].flag + x[6].flag == res &&
		x[2].XorO != sign && x[4].XorO != sign && x[6].XorO != sign) {

		if (x[2].flag == 0)
			return 3;
		else if (x[4].flag == 0)
			return 5;
		else if (x[6].flag == 0)
			return 7;

	}

	return 0;
}

char against(void) {
	char sign, res;
	if (firstOrSecond == 'X') {
		sign = 'O';
		res = 2;
	}
	else {
		sign = 'X';
		res = 4;
	}

	if (x[0].flag + x[1].flag + x[2].flag == res &&
		x[0].XorO != sign && x[1].XorO != sign && x[2].XorO != sign) {

		if (x[0].flag == 0)
			return 1;
		else if (x[1].flag == 0)
			return 2;
		else if (x[2].flag == 0)
			return 3;

	}
	else if (x[3].flag + x[4].flag + x[5].flag == res &&
		x[3].XorO != sign && x[4].XorO != sign && x[5].XorO != sign) {

		if (x[3].flag == 0)
			return 4;
		else if (x[4].flag == 0)
			return 5;
		else if (x[5].flag == 0)
			return 6;

	}
	else if (x[6].flag + x[7].flag + x[8].flag == res &&
		x[6].XorO != sign && x[7].XorO != sign && x[8].XorO != sign) {

		if (x[6].flag == 0)
			return 7;
		else if (x[7].flag == 0)
			return 8;
		else if (x[8].flag == 0)
			return 9;

	}


	else if (x[0].flag + x[3].flag + x[6].flag == res &&
		x[0].XorO != sign && x[3].XorO != sign && x[6].XorO != sign) {

		if (x[0].flag == 0)
			return 1;
		else if (x[3].flag == 0)
			return 4;
		else if (x[6].flag == 0)
			return 7;

	}
	else if (x[1].flag + x[4].flag + x[7].flag == res &&
		x[1].XorO != sign && x[4].XorO != sign && x[7].XorO != sign) {

		if (x[1].flag == 0)
			return 2;
		else if (x[4].flag == 0)
			return 5;
		else if (x[7].flag == 0)
			return 8;

	}
	else if (x[2].flag + x[5].flag + x[8].flag == res &&
		x[2].XorO != sign && x[5].XorO != sign && x[8].XorO != sign) {

		if (x[2].flag == 0)
			return 3;
		else if (x[5].flag == 0)
			return 6;
		else if (x[8].flag == 0)
			return 9;

	}


	else if (x[0].flag + x[4].flag + x[8].flag == res &&
		x[0].XorO != sign && x[4].XorO != sign && x[8].XorO != sign) {

		if (x[0].flag == 0)
			return 1;
		else if (x[4].flag == 0)
			return 5;
		else if (x[8].flag == 0)
			return 9;

	}
	else if (x[2].flag + x[4].flag + x[6].flag == res &&
		x[2].XorO != sign && x[4].XorO != sign && x[6].XorO != sign) {

		if (x[2].flag == 0)
			return 3;
		else if (x[4].flag == 0)
			return 5;
		else if (x[6].flag == 0)
			return 7;

	}

	return 0;
}


char oneIcon123(void) {

	char sign;
	if (firstOrSecond == 'X')
		sign = 'O';
	else
		sign = 'X';

	srand((unsigned int)time(NULL));
	char al[9] = { 0 };
	char returnAl;
	char pathSelection[4] = { 0 };

	if (x[0].XorO == sign &&
		(x[1].flag + x[2].flag == 0 ||
			x[3].flag + x[6].flag == 0 ||
			x[4].flag + x[8].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;
		pathSelection[2] = 0;

		if (x[1].flag + x[2].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 2;
				break;
			case 1:
				pathSelection[0] = 3;
				break;
			}
		if (x[3].flag + x[6].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 4;
				break;
			case 1:
				pathSelection[1] = 7;
				break;
			}
		if (x[4].flag + x[8].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[2] = 5;
				break;
			case 1:
				pathSelection[2] = 9;
				break;
			}

		while ((al[0] = pathSelection[rand() % 3]) == 0)
			;

	}

	if (x[1].XorO == sign &&
		(x[0].flag + x[2].flag == 0 ||
			x[4].flag + x[7].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;

		if (x[0].flag + x[2].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 1;
				break;
			case 1:
				pathSelection[0] = 3;
				break;
			}
		if (x[4].flag + x[7].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 5;
				break;
			case 1:
				pathSelection[1] = 8;
				break;
			}

		while ((al[1] = pathSelection[rand() % 2]) == 0)
			;

	}

	if (x[2].XorO == sign &&
		(x[0].flag + x[1].flag == 0 ||
			x[5].flag + x[8].flag == 0 ||
			x[4].flag + x[6].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;
		pathSelection[2] = 0;

		if (x[0].flag + x[1].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 1;
				break;
			case 1:
				pathSelection[0] = 2;
				break;
			}
		if (x[5].flag + x[8].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 6;
				break;
			case 1:
				pathSelection[1] = 9;
				break;
			}
		if (x[4].flag + x[6].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[2] = 5;
				break;
			case 1:
				pathSelection[2] = 7;
				break;
			}

		while ((al[2] = pathSelection[rand() % 3]) == 0)
			;

	}

	if (x[3].XorO == sign &&
		(x[0].flag + x[6].flag == 0 ||
			x[4].flag + x[5].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;

		if (x[0].flag + x[6].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 1;
				break;
			case 1:
				pathSelection[0] = 7;
				break;
			}
		if (x[4].flag + x[5].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 5;
				break;
			case 1:
				pathSelection[1] = 6;
				break;
			}

		while ((al[3] = pathSelection[rand() % 2]) == 0)
			;

	}

	if (x[4].XorO == sign &&
		(x[1].flag + x[7].flag == 0 ||
			x[3].flag + x[5].flag == 0 ||
			x[0].flag + x[8].flag == 0 ||
			x[2].flag + x[6].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;
		pathSelection[2] = 0;
		pathSelection[3] = 0;

		if (x[1].flag + x[7].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 2;
				break;
			case 1:
				pathSelection[0] = 8;
				break;
			}
		if (x[3].flag + x[5].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 4;
				break;
			case 1:
				pathSelection[1] = 6;
				break;
			}
		if (x[0].flag + x[8].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[2] = 1;
				break;
			case 1:
				pathSelection[2] = 9;
				break;
			}
		if (x[2].flag + x[6].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[3] = 3;
				break;
			case 1:
				pathSelection[3] = 7;
				break;
			}

		while ((al[4] = pathSelection[rand() % 4]) == 0)
			;

	}

	if (x[5].XorO == sign &&
		(x[2].flag + x[8].flag == 0 ||
			x[3].flag + x[4].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;

		if (x[2].flag + x[8].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 3;
				break;
			case 1:
				pathSelection[0] = 9;
				break;
			}
		if (x[3].flag + x[4].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 4;
				break;
			case 1:
				pathSelection[1] = 5;
				break;
			}

		while ((al[5] = pathSelection[rand() % 2]) == 0)
			;

	}

	if (x[6].XorO == sign &&
		(x[0].flag + x[3].flag == 0 ||
			x[7].flag + x[8].flag == 0 ||
			x[4].flag + x[2].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;
		pathSelection[2] = 0;

		if (x[0].flag + x[3].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 1;
				break;
			case 1:
				pathSelection[0] = 4;
				break;
			}
		if (x[7].flag + x[8].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 8;
				break;
			case 1:
				pathSelection[1] = 9;
				break;
			}
		if (x[4].flag + x[2].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[2] = 5;
				break;
			case 1:
				pathSelection[2] = 3;
				break;
			}

		while ((al[6] = pathSelection[rand() % 3]) == 0)
			;

	}

	if (x[7].XorO == sign &&
		(x[1].flag + x[4].flag == 0 ||
			x[6].flag + x[8].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;

		if (x[1].flag + x[4].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 2;
				break;
			case 1:
				pathSelection[0] = 5;
				break;
			}
		if (x[6].flag + x[8].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 7;
				break;
			case 1:
				pathSelection[1] = 9;
				break;
			}

		while ((al[7] = pathSelection[rand() % 2]) == 0)
			;

	}

	if (x[8].XorO == sign &&
		(x[2].flag + x[5].flag == 0 ||
			x[6].flag + x[7].flag == 0 ||
			x[0].flag + x[4].flag == 0)
		) {

		pathSelection[0] = 0;
		pathSelection[1] = 0;
		pathSelection[2] = 0;

		if (x[2].flag + x[5].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[0] = 3;
				break;
			case 1:
				pathSelection[0] = 6;
				break;
			}
		if (x[6].flag + x[7].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[1] = 7;
				break;
			case 1:
				pathSelection[1] = 8;
				break;
			}
		if (x[0].flag + x[4].flag == 0)
			switch (rand() % 2) {
			case 0:
				pathSelection[2] = 1;
				break;
			case 1:
				pathSelection[2] = 5;
				break;
			}

		while ((al[8] = pathSelection[rand() % 3]) == 0)
			;

	}

	if (al[0] + al[1] + al[2] + al[3] + al[4] + al[5] + al[6] + al[7] + al[8] > 0)
		while ((returnAl = al[rand() % 9]) == 0)
			;
	else returnAl = 0;

	return returnAl;
}

char oneIcon4(void) {
	
	// Надо дописать Level "God"

	return oneIcon123();
}


char noIcon12(void) {

	char c;

	do {
		c = rand() % 9;
	} while (x[c].flag != 0);

	return c + 1;
}

char noIcon34(void) {
	char c;

	if (x[4].flag == 0)
		c = 5;
	else if (x[0].flag == 0 || x[2].flag == 0 || x[6].flag == 0 || x[8].flag == 0)
		do {
			switch (rand() % 4) {
			case 0:
				c = 1;
				break;
			case 1:
				c = 3;
				break;
			case 2:
				c = 7;
				break;
			case 3:
				c = 9;
				break;
			}
		} while (x[c - 1].flag != 0);
	else
		c = noIcon12();

	return c;
}