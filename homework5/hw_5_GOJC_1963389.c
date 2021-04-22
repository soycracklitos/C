//I got help by Alfredo Palacios <3 you can check the code in any compiler//

//REMEMBER, PILAR MEANS COLUMNA AND ROW MEANS FILA, SO YOU NEED TO DEFINE WHAT PILAR YOU WANT TO CHOSE (1 TO 5) AND ROW (A TO E)//

#include <stdio.h>  
#include <ctype.h>   
#include <stdlib.h>  
#include <assert.h>  
#include <unistd.h>  
#include "pivote2.h"


//At this part of the code, it indicates the correct counters to the other cells//

int Ccell(int line, int col, char grid[ROW][PILLAR]) {
  int counter = 0, Irow, FinalRow, IP, FP;
  if (line <= 0) {
    Irow = FALSE;
  } else {
    Irow = line - 1;
  }

  if (line + 1 >= ROW) {
    FinalRow = ROW - 1;
  } else {
    FinalRow = line + 1;
  }

  if (col <= 0) {
    IP = FALSE;
  } else {
    IP = col - 1;
  }
  if (col + 1 >= PILLAR) {
    FP = PILLAR - 1;
  } else {
    FP = col + 1;
  }
  int a;
  for (a = Irow; a <= FinalRow; a++) {
    int b;
    for (b = IP; b <= FP; b++) {
      if (grid[a][b] == KABOOM) {
        counter++;
      }
    }
  }
  return counter;
}

// The program returns a random number between an interval of minimun and maxmium//


int randomV(int min, int max) {
  return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}


//The program fills the board with blank lineas without be founded//

void initial(char grid[ROW][PILLAR]) {
  int b;
  for (b = 0; b < ROW; b++) {
    int a;
    for (a = 0; a < PILLAR; a++) {
      grid[b][a] = HMM;
    }
  }
}

//Put a bomb at the coords that you choose//


void HE(int line, int col, char grid[ROW][PILLAR]) {
  grid[line][col] = KABOOM;
}

//Put the bomb in a random cell//


void AHE(char cuadricula[ROW][PILLAR]) {
  int b;
  for (b = 0; b < BOMB; b++) {
    int fila = randomV(0, ROW - 1);
    int columna = randomV(0, PILLAR - 1);
    HE(fila, columna, cuadricula);
  }
}

//grid format//


void HEADER() {
  printf("    ");
  int b;
  for (b = 0; b < PILLAR; b++) {
    printf("  %d ", b + 1);
    if (b + 1 == PILLAR) {
      printf(" ");
    }
  }
  printf("\n");
}

char chAr(int numero) {   
  return numero + '0';
}

void printgrid(char grid[ROW][PILLAR], int showbomb) {
  HEADER();
  char letra = 'A';
  int b;
  for (b = 0; b < ROW; b++) {
    int a;
    printf("  %c ", letra); 
    letra++;
    for (a = 0; a < PILLAR; a++) {
    	
    	
      // Invisible bombs//
      
      char letter = HMM;
      char actualetter = grid[b][a];
      if (actualetter == KABOOM) {
        letter = HMM;
      } else if (actualetter == SPACE) {
        
		
		// If you loose, the code shows you the bombs in the game//
		
		
        int nearbomb = Ccell(b, a, grid);
        letter = chAr(nearbomb);
      }
      if (actualetter == KABOOM && showbomb) {
        letter = KABOOM;
      }
      printf("  %c ", letter);
      if (a + 1 == PILLAR) {
        printf(" ");
      }
    }
    printf("\n");
  }
}


int showbox(char lineletter, int col, char grid[ROW][PILLAR]) {
  lineletter = toupper(lineletter);   
  col--; 
  int line = lineletter - 'A'; 
  assert(col < PILLAR && col >= 0);
  assert(line < ROW && line >= 0);
  
  if (grid[line][col] == KABOOM) {
    return GG_EZ_PZ;
  }
  if (grid[line][col] == SPACE) {
    return SPACE_FOUNDED_XD;
  }
  
  
  // Without error, the program begins//
  
  grid[line][col] = SPACE;
  return KEEP_DOING;
}

// If the user wins//


int open(char grid[ROW][PILLAR]) {
  int b;
  for (b = 0; b < ROW; b++) {
    int a;
    for (a = 0; a < PILLAR; a++) {
      char actual = grid[b][a];
      if (actual == HMM) {
        return 0;
      }
    }
  }
  return 1;
}

//FINAL GAME//

int main() {
  printf("* DON PEPE Y SUS GLOBOS 777 *\nINSTRUCTIONS: FIRST, YOU NEED TO ENTER THE PILLAR YOU WANT TO CHOOSE, THEN THE LINE. IF YOU FOUND A BOMB, YOU LOOSE! \n");
  char grid[ROW][PILLAR];
  int isthereabomb = FALSE; //flag
  srand(getpid());
  initial(grid);
  AHE(grid);
  
  
  //  loop if you loose and show you the bombs//
  while (1) {
    printgrid(grid, isthereabomb);
    if (isthereabomb) {
      break;
    }
    int col; 
    char line;
    printf("What pillar you want to choose?: ");
    scanf("%d", & col );
        printf("What line you want to choose?: ");
    scanf(" %c", & line);
    int status = showbox(line, col, grid);
    if (open(grid)) {
      printf("---------YOU WIN! SEND ME A MESSAGE BY DISCORD AND I SEND YOU A HUG   B)-------\n");
      isthereabomb = TRUE;
    } else if (status == SPACE_FOUNDED_XD) {
      printf("You already chose this box, omegalul\n");
    } else if (status == GG_EZ_PZ ) {
      printf("-----------RIP, TRY AGAIN XD :(------------\n");
      isthereabomb = TRUE;
    }
  }
  return 0;
}
