#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "project1.h"

int main(int argc, char *argv[])
{
  // Initializing variables 
  char type1;
  char type2;
  int width;
  int height; 
  int max;
 
  //struct rgb *pixels[width * height];

 //Reading file with scanf
  scanf("%c %c", &type1, &type2);
  scanf("%d %d", &width, &height);
  // printf("types: %c, %c\n", type1, type2);

  //Printing first few rows (not color)
  printf("P3\n");
  printf("%d %d\n", width, height);
  printf("255\n");
  scanf("%d", &max);
  // printf("max: %d \n", max);
  
  //Printing pixels
  int ch;
  scanf("%d \n", ch);
  while ((ch = getchar()) != EOF) {
    printf("%d ", ch); 
  }
  
  return 0;
}
