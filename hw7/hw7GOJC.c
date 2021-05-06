// This code was created with help of AlfredoPalace, also the C programming language and classes of satuelisa//

                                              //RECOMENDACIONES
                                              
//  Las intrucciones del codigo te saldran al compilar. Por favor sigue las indicaciones. '0' para admin y '1' para empleado y el pin del admin es '0' 
//  POR FAVOR: Utiliza DEVC o CODEBLOCK para compilar, en ONLINEGBD le da amsiedad y no jala
//  Crea una carpeta con ambos archivos '7main.c' y 'pivote4.h'. Cuando compiles '7main' como administrador, se crearan los archivos .txt donde almacenara la informacion de los empleados 
//  Cualquier duda, me pueden mandar mensaje al discord @soycracklitos

#include "pivote4.h"

int registered(void)
{
	int verificador(int pin);
    int access = 1, pin, flag = 0;
    char time1[30], time2[30], week[40];
    FILE *file;

    file = fopen("system.txt", "a");

    if (file == NULL)
    {
        printf("Oops! The code cant create the file system.txtn"); 
    }
    else
    {
        while (1)
        {
           if (verificador(access))
           {
               access++;
           }else {
               break;
           }
        }
        
        file = fopen("system.txt", "a");
        printf("The new code generated by the code is : %d\n", access); 
        printf("Please, write the days the employee would work, without space (Ex: LunesMartes   OR   MiercolesJuevesViernes\n"); 
        fflush(stdin);
        scanf("%s", &week);
        printf("Please, write the entry hour of the employee (Ex: 10:30 , 23:00 ,etc)\n"); 
        fflush(stdin);
        scanf("%s", &time1);
        printf("Please, write the departure hour of the employee (Ex: 10:30 , 23:00 ,etc)\n"); 
        fflush(stdin);
        scanf("%s", &time2);
        fprintf(file, "c%d e%s s%s d%s\n", access, time1, time2, week);
        printf("exito");
        fflush(file);
        fclose(file);
        file = fopen("times.txt", "a");
        fprintf(file, "%d 0 \n", access);
        fflush(file);
        fclose(file);
        printf("\n");
    }
}


int verificador(int pin)
{
    int p[9], j = 0;
    int c;
    FILE *file;

    file = fopen("system.txt", "r");

    if (file == NULL)
    {
        printf("Oops! The code cant create the file system.txt\n"); 
    }
    else
    {
        while ((c = fgetc(file)) != EOF)
        {
            if (c == 'c')
            {
                c = fgetc(file);
                p[j] = c - '0';
                if (pin == p[j])
                {
                    fflush(file);
                    fclose(file);
                    return 1;
                }
                j = +1;
            }
        }
    }
    fflush(file);
    fclose(file);
}


int assistanceCHECK(int pin)
{
    int c, asistencias = 0;
    FILE *file;
    file = fopen("log.txt", "r");
    while ((c = fgetc(file)) != EOF)
    {
        if (c == 's')
        {
            c = fgetc(file) - '0';
            if (c == pin)
            {
                asistencias++;
            }
        }
    }
    fflush(file);
    fclose(file);
    printf("\n The username %d has : %d asistances\n", pin, asistencias);
}


int timeWorked(int pin)
{
    char tiempo1[20], tiempo2[20];
    int tempo1, tempo2, tempo;
    int c, asistencias = 0;
    FILE *file;
    file = fopen("log.txt", "r");
    while ((c = fgetc(file)) != EOF)
    {
        if (c == 'e')
        {
            c = fgetc(file) - '0';
            if (c == pin)
            {
                c = fgetc(file) - '0';
                fgets(tiempo1, 11, file);
                tempo1 = atoi(tiempo1);
            }
        }
    }
    tempo = (unsigned long)time(NULL) - tempo1;
    fflush(file);
    fclose(file);
    return tempo;
}


int hourWorked(int pin)
{
    int tempo2,c,pinarch ;
    FILE * file;
    file = fopen("times.txt", "r");
    while (1)
    {
        fscanf(file, "%d %d", &pinarch, &tempo2);
        if(pinarch==pin)
        {
            return tempo2;
            break;
        }
        
        }
}

int main()
{
	printf("                          //WELCOME TO CRACKLITOS CODE (CREDITS TO ALFREDOPALACE)//\n");
    printf("                                 //HOW CAN YOU CHECK MY CODE? (INSTRUCTIONS XD)//\n\n\n");
    printf("1.-Complie :v\n");
    printf("2.-Enter as administrator (0) as (pin: '0')\n");
    printf("3.-Add an employee\n");
    printf("4.-Close the code; then, enter as the employee you added with the pin you created it.\n"); 
    printf("5.-Register your entry hour\n");
    printf("6.-Close the program and open it again with the pin of the employee you created and register your departure hour\n");
    printf("7.-Open the code again in administrator mode (pin '0')\n\n\n");
	printf("                             Now, you can verify the data of any employee, etc.\n"); 
	printf("\n                                                 *PLEASE READ THIS*:\n\n");
	printf("                        all the data would be at the .txt docs.\n");
	printf("____________________________________________________________________________________________________________________\n\n");
	FILE *flujo;
	
	
    int temppin, temptime, flag = 1;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output, 128, "%d/%m/%y", tlocal);
    int pin, option, bucle = 1, user;
    char buffer[32];
    struct tm *ts;
    size_t last;
    time_t timestamp = time(NULL);

                                                                    //Get day worked
    
    ts = localtime(&timestamp);
    last = strftime(buffer, 32, "%A", ts);
    buffer[last] = '\0';
    
                                                                    //Get hour worked
    
    char hour[128];
    strftime(hour, 128, "%H:%M", tlocal);

    printf("                                              Welcome to DATABASE3000\n\n");
    printf("Who is there?\n");
    printf("Enter '0' if you are the admin papu pro\n");
    printf("Enter '1' if you are an employee\n");
    scanf("%d", &option);
    if (option == 1)

	                                                      //OPTIONS OF THE EMPLOYEE//
	
    {
        option = 0;
        printf("Welcome panacotA, please enter your pin :): \n\n");
        scanf("%d", &pin);
        
                                                     //The code is analyzing the pin you entered// 
		if (verificador(pin) != 1) 
        {
            printf("This pin doesn't exist, please check the registered pines at system.txt or crate the employee as administrator\n"); 
            printf("asta la PROXIMAAAAAAAAAAAAAAAAA!\n");
            getchar();
            exit(1);
        }
        printf("                 EMPLOYEE MENU\n SLAVE #%d, Welcome to inferno :)\nWhat do you want to do? (enter the option you want to do)  \n", pin);
        printf("1.- Imma join the inferno \n2.- Imnma leave the inferno\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1: 
        
		                                                          //ENTERED HOUR OF THE SLAVE
		
            flujo = fopen("log.txt", "a");
            printf("Your entry hour is registered SLAVE#%d today AT:%s %s\n", pin, output, buffer);
            fprintf(flujo, "e%d %lu %s %s\n", pin, (unsigned long)time(NULL), output, buffer);
            printf("get to work\n");
            fflush(flujo);
            fclose(flujo);
            break;
        case 2: 
         
		                                                    //LEFT HOUR OF THE SLAVE
		
            flujo = fopen("times.txt", "r+");
            while (flag != 0)
            {
                fscanf(flujo, "%d %d", &temppin, &temptime);
                if (temppin == pin)
                {
                    temptime += timeWorked(pin);
                    fseek(flujo, -3, SEEK_CUR);
                    fprintf(flujo, "%d %d", pin, temptime);
                    fflush(flujo);
                    fclose(flujo);
                    flag = 0;
                }
            }
            flujo = fopen("log.txt", "a");
            printf("Your departure hour is registered SLAVE#: %d today AT:%s %s\n", pin, output, buffer);
            fprintf(flujo, "s%d %lu %s %s %d\n", pin, (unsigned long)time(NULL), output, buffer, timeWorked(pin));
            printf("\n You worked %d seconds, flojonazo e.e \n", timeWorked(pin));
            printf("asta la PROXIMAAA");
            fflush(flujo);
            fclose(flujo);

                                                                  // It closes "fichero1.txt". //
                                            
            fclose(flujo);
            fprintf(flujo, "%d %d\n", pin, timeWorked(pin));
            break;
        }
        getchar();
        exit(1);
    }
    else if (option == 0) 
	
	                                                              //BOSS OPTIONS//
	
    {
        option = 0;
        printf("Welcome Boss, please enter your pin: \n");
        scanf("%d", &pin);
        if (pin != 000)
        {
            printf("ITS A TRAP, CODE 999 WE HAVE A TRAITOR \n");
            getchar();
            exit(1);
        }
        else
        {
            while (bucle == 1)
            {
                option = 0;
                printf("\n                                          BOSS MENU\n");
                printf("Welcome MASTERCHIEF, What do you want to do? Please write the number of the option you want to choose\n");
                printf("1.- I want to see the assistance of a slave\n");
                printf("2.- I want to add a new slave\n");
                printf("3.- I want to check the hours worked by my slave\n");
                fflush(stdin);
                scanf("%d", &option);
		    
		    
                                                                           // ACTIONS OF THE SLAVE
                switch (option)
                {
                case 1:
                    printf("Enter the slave you want to check his assistances(check if it is correct): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    assistanceCHECK(pin);
                    break;
                case 2:
                    registered();
                    break;
                case 3:
                    printf("Enter the slave you want to check his assistances(check if it is correct): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    printf("SLAVE#%d,  has worked for %d seconds \n", pin ,hourWorked(pin));
                    break;
                }
               
                printf("If you want to check something else, write whatever you want , if you want to leave, write  '1'\n");
                fflush(stdin);
                scanf("%d", &option);
                if (option == 1)
                {
                    printf("asta la PROXIMAAA!\n"),
                        getchar();
                    exit(1);
                }
            }
        }
    }
    else
    {
        printf("The code can't help you with that. Please, press enter to leave ...");
        getchar();
        exit(1);
    }
    getchar();
    exit(1);
}
