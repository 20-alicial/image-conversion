#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "project1.h"

// Takes an 3 byte RBG and prints each r,g,b as int
void rgb_print(struct rgb color)
{
  int r = color.r;
  int g = color.g;
  int b = color.b;
  printf("%d ", r); 
  printf("%d ", g);
  printf("%d ", b);
}

int main(int argc, char *argv[])
{
  // Magic 
  getchar();
  getchar();
  printf("P3\n");

  getchar();
  getchar();
  
  getchar();
  getchar();

  getchar();
  getchar();
  getchar();
  getchar();

  // Width & Height 
  int width = byte_to_int2();
  int height = byte_to_int2();
  printf("%d %d\n", width, height);
  // int ten = getchar();
  // int eleven = getchar();
  // int twelve = getchar();
  // int thirteen = getchar();


  //printf("%d%d %d%d\n", ten,eleven,twelve,thirteen); // convert

  // Max
  printf("255\n");

  getchar();
  getchar();
  getchar();
  getchar();
  int eighteen = getchar();

  int is_grey;
  if (eighteen == 3) {
    is_grey=1;
  }
  if (eighteen == 1) {
    is_grey=0;
  }

  //char ch = getchar();
  //printf("test ch: %c", ch);
  getchar();
  getchar();

  // Get chars until the string is over
  char getc = 1;
  while (getc != '\0') 
  {
    getc = getchar();
    //printf("char: %c\n", getchar());
  }
  // printf("int: %d\n", getchar());

  // Read run, run lengths, rgb
  // Create array of lengths and rgb
  // printf("int: %d\n", getchar());
  
 // unsigned int run = byte_to_int4();
  unsigned int run = byte_to_int4();
  //printf("run: %d\n", run);

  unsigned int *len_arr = (unsigned int*)malloc(sizeof(unsigned int)*run);
  for (int i = 0; i <run; i++)
  {
    len_arr[i] = byte_to_int4();
  }

  struct rgb* rgb_arr = (struct rgb*)malloc(sizeof(unsigned int)*run);

  // print out rgbs as integers
  if (is_grey == 0)
  {
    for (int i = 0; i <run; i++)
    { 
    rgb_arr[i].r = getchar();
    rgb_arr[i].g = getchar();
    rgb_arr[i].b = getchar();
    }
  }
  //printf("in_grey %d", is_grey);
 //printf("run: %d", run);

  // print out rgbs as integers
  if (is_grey == 1)
  {
    for (int i = 0; i <run; i++)
    {
      int grey = getchar();
      rgb_arr[i].r = grey;
      rgb_arr[i].b = grey;
      rgb_arr[i].g = grey;
    }
  }

  for (int j=0; j<run; j++) {
    for (int k=len_arr[j]; k>0; k--) {
      rgb_print(rgb_arr[j]);
      }
    }

  return 0;
}
