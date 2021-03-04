#include <stdio.h> 
#include <math.h> //defines various mathematical functions//
#define K 21   //constants
#define YES 1 
#define NO 0
// * PLEASE USE GBD ONLINE DEBUGGER TO CHECK THE CODE, IN DEVC DOESNT WORK! *//
// * MENTIONS: thanks to Alfredo Palacios and Abner Velazquez to help me with my code, also i use this video to inspirate my homework https://www.youtube.com/watch?v=RFVJHeDL9LA *//
int prime (int k) // code to check if the numbers are prime or not//
{
    int counter = YES; // YES equals to 1//
    int sroot; //squareroot//
    int h; // variable // 
    int ally; // prime number //
    int c = YES; // YES equals to 1//
    int ignore = YES; // YES equals to 1//
    while (counter <= k) {
        sroot = sqrt (c); //squareroot//
        ally = YES;
        for (h=2; h<= sroot; h= h+1){
         if (c%h==0) {
          ally = NO;  //if the number is not prime, the code doesn't print it//
           ignore = YES;
         }
        }
    if (ally == YES) { //if the number is prime, the code print it//
            binary (c);
    counter = counter + 1;
    }
    c = c+1;
}
}
int prime (int P);   //prime number//
int main () {
prime (K); //prime result//
return 1;
}
//convert to binary number//
int binary (int b)
{
    int h = NO; 
    int base [7] = {0};
    while (b != 0){       //lines 50-55 are the code to convert decimal numbers to binary numbers//
        base [h] = b%2; 
        b /= 2; 
    h=h+1;
    }
    for (int p=6;p>=0;--p) 
    {
        printf ("%01d", base [p]); 
    }
    printf ("\n"); 
}