//To use the code in ONLINEGBD, you need to paste this code as the document 'main.c'. 
//Then, you need to open another paper and create a file code with the name "pivo3.h//
//In onlinegbd, there is an option to upload files, if you want to use it, it would work//
//If you dont follow these steps, it would not work :c please panacota//
//It works in DEVC++ too, but it is more complex 'cause you need to create 2 documents xd//

//Credits for Alfredo Palacios Trejo to help me with the code. Also it was used "The C PROGRAMMING LANGUAGE" and the explanation of our teacher :3//

//There are 2 warnings at the code, but it stills working xd//

//If you want to check the code with my tree, the archive.png is on my github!//

#include "pivo3.h"

{ 
 // Memory of code
 
    size_t tamanioNodo = sizeof(usuario);
    size_t tamanioNodopass = sizeof(usuario);
    usuario *nodo = (usuario *)malloc(tamanioNodo);
    usuario *nodopass = (usuario *)malloc(tamanioNodopass);
    
    // info of pivote3_ and start the code
    
    strcpy(nodo->username, username);    
    strcpy(nodo->password, password);
    nodo->lBaby = nodo->rBaby = NULL;
    return nodo;
}

void agregar(usuario *nodo, char *cadena, char *password)
{
    if (strcmp(cadena, nodo->username) > 0)
    {
        if (nodo->rBaby == NULL)
        {
            nodo->rBaby = nuevoNodo(cadena, password);
        }
        else
        {
            agregar(nodo->rBaby, cadena, password);
        }
    }
    else
    {
        if (nodo->lBaby == NULL)
        {
            nodo->lBaby = nuevoNodo(cadena, password);
        }
        else
        {
            agregar(nodo->lBaby, cadena, password);
        }
    }
}

usuario *buscarUsername(usuario *nodo, char *cadena)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->username) == 0)
    {
        return nodo;
    }
    else if (strcmp(cadena, nodo->username) > 0)
    {
        return buscarUsername(nodo->rBaby, cadena);
    }
    else
    {
        return buscarUsername(nodo->lBaby, cadena);
    }
}
usuario *buscarPassword(usuario *nodo, char *cadena, char *pass)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->username) == 0)
    {
        if (strcmp(pass, nodo->password) == 0)
        {
            *nodo->username = NULL;
            *nodo->password=NULL;
            return NULL;
        }
    }
    else if (strcmp(cadena, nodo->username) > 0)
    {
        return buscarPassword(nodo->rBaby, cadena, pass);
    }
    else
    {
        return buscarPassword(nodo->lBaby, cadena, pass);
    }
}

// If a node is not equal to a null, it goest depends of the letter (you know, < or >)//

void ordenar(usuario *nodo) 
{
    if (nodo != NULL)
    {
        ordenar(nodo->lBaby);
        printf("%s,", nodo->username);
        ordenar(nodo->rBaby);
    }
}


//Matrix of the code, it reads the username and password, detect if it's a null  and do the process of delete//


int main()
{
    char nickname[MAX];
    char adress[MAX];
    usuario *raiz = NULL;
    printf("\nWelcome to cracklitos tree code\n\nThanks for checking my code, i aprecciate. First, you need to add an username to begin the tree \n");
    printf("Please, write the username you want to add:\n");
    scanf("%s", &nickname[0]);
    printf("Please, write the password of the username:\n");
    scanf("%s", &adress[0]);
    printf("\n\t USERNAME '%s' is added! \n", nickname);
    raiz = nuevoNodo(nickname,adress);
    int addition = INVALID;
    int supreme= INVALID;
	int watch= INVALID;
    char option, c;
    while ((c = getchar()) != EOF)
    {
        
        printf("\n-> If you want to add an username, press 'a' \n-> If you want to delete an username, press 'd' \n-> If you want to view the tree, press 'v' \n");

        scanf("%c", &option);
        switch (option)
        {
        case 'a': // 'a' means addition, to add a nickname&password
            addition = TRUE;
            break;
        case 'd': // 'd' means delete, to delete a nickname&password
            supreme = TRUE;
            break;
        case 'v': // 'v' means watch, to watch the finale result of the tree
            watch = TRUE;
            break;
        default:
            printf("I do not think that is correct...");
            break;
        }
        if (addition != 0 || supreme != 0 || watch != 0)
        {
            if (addition == TRUE)                                   		
            {
                char nickname[MAX];
                char adress[MAX]; 
                printf("Please, add the username you want to add:\n");
                scanf("%s", &nickname[0]);
                struct nodoCadena *apuntadorUser = buscarUsername(raiz, nickname);
                if (apuntadorUser != NULL)
                {
                    printf("\n\t Dude, '%s' has already added\n");
                }
                else
                {
                    printf("Please, write the password of the user:\n");
                    scanf("%s", &adress[0]);
                    agregar(raiz, nickname, adress);
                    printf("\n\t The username '%s' was added correctly");
                }
            }
            else if (supreme == TRUE)
            {
                char nickname[MAX];
                char adress[MAX];
                printf("Please, write the username you want to eliminate:\n");
                scanf("%s", &nickname[0]);
                struct nodoCadena *apuntadorUser = buscarUsername(raiz, nickname);
                if (apuntadorUser != NULL)
                {
                    printf("Please, write the password of the user:\n");
                    scanf("%s", &adress[0]
					);
                    struct nodoCadena *apuntadorPass = buscarPassword(raiz, nickname, adress);
                    if (apuntadorPass == NULL)
                    {
                        printf("\n\t The username %s is completely delete \n", nickname);
                    }
                    else
                    {
                        printf("\t!Password incorrect\n");
                    }
                }
                else
                {
                    printf("\n !El usuario no se encuentra en nuestro sistemas\n"); ("\n The username you write is not at the system\n");
                }
            }
            else if (watch == 1)
            {
                ordenar(raiz);
                printf("\nPress enter to continue:)\n");
                getchar();
            }
        }
        addition = INVALID;
        supreme = INVALID;
        watch = INVALID;
    }
return 0; 
}
