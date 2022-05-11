#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "project1.h"
 
//takes an rgb struct prints the ascii symbol version
void rgb_to_binary(int r, int g, int b) {
 //int red = c.r, green = c.g, blue = c.b;
 putchar(r); 
 putchar(g); 
 putchar(b);
}

int main(int argc, char *argv[])
{
  // Initializing variables 
  char type1;
  char type2;
  int width;
  int height; 
  int max;
  int red;
  int blue;
  int green;
  //struct rgb *pixels[width * height];

  //Reading file with scanf
  scanf("%c %c", &type1, &type2);
  scanf("%d %d", &width, &height);
  // printf("types: %c, %c\n", type1, type2);

  //Printing first few rows (not color)
  printf("P6\n");
  printf("%d %d\n", width, height);
  printf("255\n");
  scanf("%d", &max);
  // printf("max: %d \n", max);

  //Printing pixels
  for (int i = 0; i < 3*width*height; i += 3) {
      //printf("i = %d\n", i);
      scanf("%d %d %d", &red, &blue, &green);
      //printf("r: %d, b: %d, g: %d\n", red, blue, green);
      rgb_to_binary(red, blue, green);
    }
  return 0;
  }
