#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 


#define INVALID 0
#define TRUE 1
#define MAX 100


typedef struct nodoCadena
{
    char username[MAX];
    char password[MAX];
    // Las ramas
    struct nodoCadena *lBaby;
    struct nodoCadena *rBaby;
} usuario;
usuario *nuevoNodo(char username[MAX], char password[MAX])
