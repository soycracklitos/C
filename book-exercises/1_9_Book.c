#include<stdio.h>
#define MAXLINE 1000

int getline (char line [], int maxline);
void copy (char to [], char from []);

main()
{
	 int len; //current line lenght//
	 int max; // maxmium lenght seen so far//
	 char line [MAXLINE]; // current input line //
	 char longest [MAXLINE]; // longest line saved here //
	 
	 max= 0;
	 while ((len = getline (line, MAXLINE)) > 0)
	 if (len > max) {
	 	max = len;
	 	copy (longest, line);
	 }
	 if (max > 0) // there was a line //
	 printf("%s", longest);
	 return 0;	 
}
// getline : reada line into s, return lenght//

int getline (char s [], int lim)
{
	int c, i;
	
	for (i=0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
	s [i] = c;
	if (c== '\n'){
		s [i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
