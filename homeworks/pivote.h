//BEFORE YOU START, I WANT TO THANK MY FRIEND ALFREDO TO HELP ME TO EXPLAIN HOW TO DO IT, PLEASE CHECK THE CODE WITH GBD, IDK WHY IN DEVC DOESNT WORK XD//

#include <stdio.h>
#include <stdlib.h>		

#define MOP	100		/*100 is the maximum size of operator */
#define SYMBOL	'0'		/* WHEN THE PROBLEM FOUNDS A NUMBER */
#define DRIVER	'1' /* WHEN THE PROGRAM FOUNDS AN OPERATOR */
#define COMMAND		'2'	/* WHEN THE PROGRAM FOUNDS A COMMAND*/
#define OPERATION	'3'	/* WHEN THE PROGRAM FOUNDS A MATH OPERATOR */
#define CHANGEABLE		'4'	/* WHEN THE PROGRAM FOUNDS A CHANGEABLE */

int getop(char []);
void push(double);
double pop(void);
void dup(void);
void clear(void);

