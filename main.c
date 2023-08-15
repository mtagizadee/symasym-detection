#include <stdio.h>
#include "bmp/bmp.h"

int main(void) {
  printf("Hello, world!\n");

  char *sPath = "/Users/mtaghizada/Dev/Projects/symasym-detection/data/train/ha1716168.bmp";
  
  BMPHeader header;
  BMPInfoHeader infoHeader;

  uint8_t* pImage;
  initBMP(sPath, &header, &infoHeader, &pImage);
  uint8_t pixels[infoHeader.width][infoHeader.height][3]; // 3 for RGB

  readBMP(infoHeader, pImage, pixels);

  // iterate over the pixels
  for (int row = 0; row < infoHeader.height; row++) {
      for (int col = 0; col < infoHeader.width; col++) {
          printf("%d %d %d\n", pixels[row][col][0], pixels[row][col][1], pixels[row][col][2]);
      }
  }
  return 0;
}