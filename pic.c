#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(){

  int r, g, b, x, y;
  int file;
  int xres, yres;
  int max_c = 255;
  char line[100];
  char header[100];
  
  xres = 500;
  yres = 500;
  
  file = open("pic.ppm", O_CREAT|O_WRONLY|O_RDONLY);
  
  sprintf(header, "P3 \n %i,%i \n %i \n", xres, yres, max_c);
  write(file, header, strlen(header));
  for(y = 0;y<yres; y++){
    for (x = 0;x<xres; x++){
      r = y + 1;
      g = (x * x)+ (5 * y);
      b = 255;
      sprintf(line, "%d %d %d ", r , g, b);
      write(file, line, strlen(line));
    }
    sprintf(line, "%s\n", line);
    write(file, line, strlen(line));
  }
  close(file);  
}
