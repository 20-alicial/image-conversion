#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include "project1.h"


// Takes three integer values for r,g,b and outputs a rgb struct 
struct rgb int_to_rgb(int r, int g, int b)
{
  struct rgb color;
  color.r=r;
  color.g=g;
  color.b=b;

  return color;
}

// Takes an image and outputs the number of runs
int run_number(struct image *img)
{
  int size = 1;
  struct rgb prev;

  prev = img->pixels[0]; 
    for (int i = 1; i < img->w * img->h; i++) {
        if (rgb_eq(img->pixels[i], prev)) {
            continue;
        } else {
            size += 1;
            prev = img->pixels[i];
        }
    } return size;
    printf("%d\n", size);
}

// Takes an image and ouputs a pointer to an array 
// of the length of each run
int *run_len(struct image *img)
{
  int size = 0;
  int length = 1;
  struct rgb prev;
  prev = img->pixels[0]; 

  int run_num = run_number(img);
  int *run_lengths = (int *) malloc(sizeof(int) * run_num);
    for (int i = 1; i < img->w * img->h+1; i++) {
        if (rgb_eq(img->pixels[i], prev)) {
            length += 1;
            continue;
        } else {
            run_lengths[size] = length;
            length = 1;
            size += 1;
            prev = img->pixels[i];
        }
    } return run_lengths;
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
  char a = '.'; // for future expansion

  // printf("types: %c, %c\n", type1, type2);

  // Bytes 0:1 
  printf("PZ");

  // Bytes 2:3
  printf("%c%c",a,a);
  // printf("255\n");
  // scanf("%d", &max);

  // Byte 4:5 Time
  struct tm *local_time;
  time_t t = time(NULL);
  local_time = localtime(&t);
  int hour = local_time->tm_hour;
  int min = local_time->tm_min;
  putchar(hour);
  putchar(min);

  // Byte 6:9 Date
  int year = 1900+local_time->tm_year;
  int month = 1+local_time->tm_mon;
  int date = local_time->tm_mday;

  putchar(year>>8);
  putchar(year);
  putchar(month);
  putchar(date);

  // Byte 10:11, 12:13
  //scanf("%c %c\n", &type1, &type2);
  getchar();
  getchar();
  scanf("%d %d\n", &width, &height);
  scanf("%d\n", &max);
  putchar(width>>8);
  putchar(width&255);
  putchar(height>>8);
  putchar(height&255);

  // Byte 14:17
  printf("%c%c%c%c", a,a,a,a);

  // Creating img struct by scanning; used for Byte18
  int w = (uint32_t) width;
  int h = (uint32_t) height;
  struct rgb* pix = (struct rgb*)malloc(sizeof(struct rgb)*w*h);

  for (int i = 0; i < width*height; i += 1) {
      //printf("i = %d\n", i);
      scanf("%d %d %d", &red, &blue, &green);
      //printf("r: %d, b: %d, g: %d\n", red, blue, green);
      pix[i] = int_to_rgb(red, blue, green);
    }

  struct image i1;
  i1.w=w;
  i1.h=h;
  i1.pixels=pix;
  
  // Byte 18
  unsigned int zero = 0;
  unsigned int grey = 3;
  unsigned int not_grey = 1;
  if (img_grayscale(&i1)) {
    putchar(grey);
  } 
  if (img_grayscale(&i1) == 0) {
    putchar(not_grey);
  }

  // Byte 19:21
  printf("%c%c%c", a,a,a);

  //Byte 22:??
  if (argv[1] != NULL) {
  printf("%s", argv[1]);
  putchar('\0');
  } else {
    putchar('\0');
  }

  //Bytes following the string-----
  //Number of runs, length of each run, corresponding color
  int r_num = run_number(&i1);
 //printf("run_number: %d\n",r_num);
  int_to_byte4(r_num);

  int *len_arr = run_len(&i1);

  for (int i = 0; i < r_num; i++) {
    int_to_byte4(len_arr[i]);
  }

  if (img_grayscale(&i1)==0) {
    for (int i = 0; i < i1.w * i1.h; i++) {
        if (rgb_eq(pix[i], pix[i+1])==0) {
            int r = pix[i].r;
            int g = pix[i].g;
            int b = pix[i].b;
            putchar(r);
            putchar(g);
            putchar(b);
        }
    } 
  }

  if (img_grayscale(&i1)) {
    for (int i = 0; i < i1.w * i1.h; i++) {
        if (rgb_eq(i1.pixels[i], i1.pixels[i+1])==0) {
            int r = i1.pixels[i].r;
            putchar(r);
            
        }
    } 
  }

  return 0;
}
