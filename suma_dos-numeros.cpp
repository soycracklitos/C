#include<stdio.h>

int main()
{
	float num1, num2, suma, producto;
	printf("Ingrese primer valor:");
	scanf ("%f", &num1);
	printf("Ingrese segundo valor:");
	scanf("%f", &num2);
	suma= num1+num2;
	producto = num1*num2;
	printf("La suma de los dos valores es:");
	printf("%f", suma);
	printf("\n");
	printf("El producto de los dos valores es:");
	printf("%f", producto);
	getchar();
	return 0;
}
