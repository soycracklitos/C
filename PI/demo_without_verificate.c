#include "header.h"

FILE *flujo;
int main()
{
	system("title Agenda San Jorge 2021");
    int opt, bucle = 1;
   
    time_t tiemp  = time(0); 

    while (bucle == 1)
    {
    	printf("       ==========================================================================================\n");
    	printf("       |                      Bienvenido al sistema de Agendado San Jorge 2021                  |\n");
    	printf("       ==========================================================================================\n\n");
        printf("Por favor, seleccione la opsion que desee ejecutar\n\n");
        printf("1.-Catalogo de Eventos\n");
        printf("2.-Reservar un evento\n");
        printf("3.-Eliminar una reservacion\n");
        printf("4.-Salir de sistema\n\n");
        fflush(stdin);
        opt = getchar();

        switch (opt)
        {
        case '1':
            imprimeReservaciones();
            break;

        case '2':
            reservacion();
            break;
        case '3':
            eliminar();
            break;

        case '4':
            printf("Gracias por utilizar el sistema de Agendas San Jorge 2021. Recuerda siempre atender de manera atenta al cliente.\nAdios!\n\n");
            exit(1);
            getchar();
            break;

        default:
            printf("\nLa opcion seleccionada es invalida, por favor, vuelve a intentarlo\n\n");
            break;
        }
    }
}




int reservacion(void)
{
    double monto;
    char mes[10], nombre[30], paquete[50];
    int opt, file = 1, dia, anio; // file 1 exterior, 2 interior
    printf("\nSi el cliente busca rentar la alberca o el exterior, escriba '1'\nSi el cliente busca rentar el salon techado, escriba '2'\n\n");
    fflush(stdin);
    scanf("%d", &opt);

    if (opt != 1 && opt != 2)
    {
        printf("La opcion escrita no se encuentre en el sistema. Por favor, intente denuevo\n");
        return 0;
    }
    printf("\nEscriba el nombre de la reservacion como este ejemplo 'Albercada_de_Ana o 'Fie");
    printf("sta_de_Ana'\ndependiendo si es en la alberca,en la explanada o en el interior:\n\n"); 
    fflush(stdin);
    scanf("%s", &nombre);
    printf("Escribe el dia a reservar\n\n");
    fflush(stdin);
    scanf("%d", &dia);
    printf("Escribe el mes a reservar\n\n");
    fflush(stdin);
    scanf("%s", &mes);
    printf("Escribe el año de la reservacion:\n\n");
    fflush(stdin);
    scanf("%d", &anio);
    printf("Ahora, escoja el paquete que el cliente ha contratado\n");
    printf("Paquete Sencillo (Sillas, mesas, manteles, cubremanteles, servicio y vigilancia)\n");
    printf("Precio: $4,000.00 MXN de Domingo a Jueves y $10,000.00 MXN en fin de semana)\n\n");
    printf("Paquete Plata (Sillas thiffany, mesas, manteles, cubremanteles, servicio, vigilancia, arcos para boda, banquete a tres tiempos y dj basico)\n");
    printf("Precio: $10,000.00 MXN de Domingo a Jueves y $18,500.00 MXN en fin de semana)\n\n");
    printf("Paquete Oro (Sillas thiffany, mesas, manteles, cubremanteles, servicio, vigilancia, arcos para boda, banquete de tres a cinco tiempos, dj o conjunto y mesa de dulces)\n");
    printf("Precio: $22,000.00 MXN de Domingo a Jueves y $30,000.00 MXN en fin de semana)\n\n");
    printf("Paquete Platino (Sillas thiffany, mesas, manteles, cubremanteles, servicio, vigilancia, arcos para boda, banquete de tres a cinco tiempos, dj, conjunto o batucada, mesa de dulces y coordinador del evento a su disposicion)\n");
    printf("Precio: $32,000.00 MXN de Domingo a Jueves y $40,000.00 MXN en fin de semana)\n\n");
    printf("Paquete Albercada para 30 personas (Sillas, manteles y servicio de vigilancia)\n");
    printf("Precio: $2,500.00 MXN de Domingo a Jueves y $10,000.00 MXN en fin de semana)\n\n");
    printf("Paquete Albercada para 50 personas (Sillas, mesas y servicio de vigilancia)\n");
    printf("Precio: $4,500.00 MXN de Domingo a Jueves y $12,000.00 MXN en fin de semana)\n\n");
    fflush(stdin);
    scanf("%s", &paquete);
    
    
    if (opt == 1)
    {
        flujo = fopen("Exterior.txt", "a");
        
    }
    else if (opt == 2)
    {
    	
        flujo = fopen("Interior.txt", "a");
        
    }
    fprintf(flujo, " %s %d %s %d %s %lu \n", nombre, dia, mes, anio, paquete,(unsigned long)time(NULL));
    printf("Se ha registrado correctamente el evento '%s' del '%d'de '%s' del '%d'\n con el '%s' \n", nombre, dia, mes, anio, paquete);
    fflush(flujo);
    fclose(flujo);
}

int imprimeReservaciones(void)
{
    FILE *fichero;
    char c;

    printf("Estas son las reservaciones que se han hecho en el salon cerrado:\n");
    fichero = fopen("Interior.txt", "rb");
    while (!feof(fichero))
    {
        c = getc(fichero);
        printf("%c", c);
    }
    fclose(fichero);

    fichero = fopen("Exterior.txt", "rb");
    printf("Estas son las reservaciones que se han hecho en la alberca o el exterior:\n");
    while (!feof(fichero))
    {
        c = getc(fichero);
        printf("%c", c);
    }
    fclose(fichero);
    return 0;
}



int eliminar(void) 
{
    FILE *fileptr1, *fileptr2;

    char ch;
    int delete_line, temp = 1, opt;

    printf("Esta por eliminar una reservacion.\nEscriba '1' si desea eliminar una albercada o evento en exterior\nEscriba '2' si desea eliminar una evento en interior\n\n");
    fflush(stdin),

        scanf("%d", &opt);
    if (opt != 1 && opt != 2)
    {
        printf("\nLa opcion seleccionada es invalida, por favor, vuelve a intentarlo\n\n");
        return 0;
    }

    //Abir para leer

    (opt==1) 
    ? (fileptr1 = fopen("Exterior.txt", "r")) 
    :  (fileptr1 = fopen("Interior.txt", "r")); 
    
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    
    rewind(fileptr1);
    printf("\nPara eliminar un evento, debe escogerlo dependiendo de la linea donde este:\n\n");
    scanf("%d", &delete_line);
   
    fileptr2 = fopen("replica.c", "w");
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        if (ch == '\n')
        {
            temp++;
        }
        
        if (temp != delete_line)
        {
            
            putc(ch, fileptr2);
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    
    (opt==1) 
    ? (remove("Exterior.txt")) 
    :  (remove("Interior.txt")); 
    
  

    (opt==1) 
    ? (rename("replica.c", "Exterior.txt")) 
    :  (rename("replica.c", "Interior.txt")); 
    
    printf("\nEl evento ha sido eliminado. Ahora, estos son los eventos del salon programados:\n\n");

    (opt==1) 
    ? (fileptr1 = fopen("Exterior.txt", "r")) 
    :  (fileptr1 = fopen("Interior.txt", "r")); 
   
    ch = getc(fileptr1);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fileptr1);
    }
    fclose(fileptr1);
    return 0;
}
