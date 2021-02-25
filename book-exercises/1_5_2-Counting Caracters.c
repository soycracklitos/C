#include<stdio.h>

main()
{
	long nc;
	nc= 1;
	while (getchar()!=EOF)
	++nc;
	printf("%ld\n", nc);
	

}
