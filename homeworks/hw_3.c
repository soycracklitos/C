#include <stdio.h>
#define YES 1
#define NO 0

//thanks to Alfredo Palacios Trejo, he nevers forget me and he help me to finish my code! //

int main(int c) {
  int number = YES;
  int p = YES;
  int e = NO; // sign counter//

  while ((c = getchar()) != EOF) {
      switch(c){
      	
      //increment by one each time the code read these signs//
      
      case '[':  case '(': case '{': case '<': 
          p=NO;
          putchar(c);
          break;

      case ']': case ')': case '}': case '>':
          p=YES;
          putchar(c);
          break;

      case '\"': case '\'':
          putchar(c);
          e++;
          break;

      default:

        if(c!='.'&&c!=':'&&c!='\?'&&c!='!'&&c!='-'&&c!=';'&&c!='_'){ //delete all kind of signs like this//
            if (p==NO||e==YES){
            putchar(c);
            }
            else{
                if (e==2){
                    e=0;
                }
                if (c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0'){
                    number++;
                }else{
                  number=0;
                }
                if (number==1){
                    putchar('X');
                }
                if (number==0){
                    putchar(c);
                }
            }
        }

        }
    }


    return 0;
  }
