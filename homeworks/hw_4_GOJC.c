//BEFORE YOU START, I WANT TO THANK MY FRIEND ALFREDO TO HELP ME TO EXPLAIN HOW TO DO IT//


#include "pivote.h"


int main()
{
	int type;
	double op2, op1;
	char s[MOP];
	double variables[26] = {0.0};
	char var;
    printf("Welcome to the CALCULATOR 3000!\n For assign a variable, write something like this:  Number letter = . \nYou neeed to make operations like this! :   1 2 + , this equals to  1+2\n\n !!!!!! IMPORTANT PLEASE READ !!!!!! : USE THE SPACEBOARD ('12+' IS NOT THE SAME '1 2 +')\n");

	while ((type = getop(s)) != EOF) {
		switch(type) {
			case SYMBOL:
				push(atof(s));
				break;
			case DRIVER:
				switch(s[0]) {
					case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					op2 = pop();
					if(op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: zero divisor\n");
					break;
				case '%':
					op2 = pop();
					if(op2 != 0.0)
						push((int)pop() % (int)op2);
					else
						printf("error: zero divisor\n");
					break;
				case '=':
					pop();
					push(variables[var - 'A'] = pop());
					break;
				case  '?':
					push(variables[var - 'A']);
					break;
				}
				break;

			case OPERATION:{
					push(atof(s));;
				}
				break;
			case  CHANGEABLE:
				var = s[0];
				push(variables[var - 'A']);
				break;
			case '\n':
				dup();
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
}


#define VALM	100		// the maximum value of the value stack //

int sp = 0;				// the next position of the value stack //
double val[VALM];		//  the value stack //


void push(double f)
{
	if (sp < VALM)
		val[sp++] = f;
	else
		printf("error: stack full, cant push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);


int getop(char s[])
{
	int z, k, op, sign = 0;

	while((s[0] = k = getch()) == ' ' || k == '\t')
		;
	s[1] = '\0';

	if(k == '\n')
		return k;

	z = 0;

	// WHEN THE PROGRAM COLLECTS ALL THE CARACTER //
	while(isalnum(s[++z] = k = getch()) || k == '.')
		;

	s[z] = '\0';
	if(k != EOF)
		ungetch(k);

	// DETERMINE IF ITS A DEFINED CONSTANT//
	
	if(z == 1 && !isalnum(s[0]))
			return DRIVER;
	else if(z == 1 && isupper(s[0]))
		return CHANGEABLE;
	else if(z > 1 &&  isalpha(s[0]))
		return OPERATION;
	else
		return SYMBOL;

}

#define BSIZE	100

char buf[BSIZE];		// the ungetchar of the buffer //
int bufp = 0;			// would be the next position of the buffer //

int getch(void)			// get a character //
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		
{
	if (bufp >= BSIZE)
		printf("ungetch: oops, there are too many characters, try again!\n");
	else
		buf[bufp++] = c;
}
