#include <stdio.h>

main()
{  // before you check the code, i want to thanks to Abner Velazquez, Alfredo Palacios, Angel Soria and Julio Arias to help me with my code//
    char c;
    int  i=0;
    int ignore = 0;
    char strong[14]={"strong/strong"};
    char scrip[14]={"script/script"};
    
    while ((c = getchar()) != EOF) //read the code//
    {// delete '<' and '>'
        if (c == '<') // if c equals to <
        {
            ignore = 1;
        }
        else if (ignore != 1)
        {
            putchar(c);
        }
        else if (c == '>') // if c equals to >
        {
            ignore = 0;
        }
    }
    if(i== 13){
         i=0;}
         while (c != EOF && c!= '>'){
         	c =getchar();}

     {
     	 if (i== 6 && i<14){
    	     if (c == ' ')
             printf('_');{
        	 putchar (c);}
	         if((i!=6 && c!= '<' && c!= '>') || c == '\n'){
	         	putchar (c);
	         	i=0;
			 }
        putchar(c);  //answer of getchar, insert each character
	 }
}

}


