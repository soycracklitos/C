#include <stdio.h>

int main()
{
    char c;
    
    int ignore = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '<')
        {
            ignore = 1;
        }
        else if (ignore != 1)
        {
            putchar(c);
        }
        else if (c == '>')
        {
            ignore = 0;
        }
}
{
    else if (c==' '){
        printf('_');
        c= getchar();}

        putchar(c);

}
