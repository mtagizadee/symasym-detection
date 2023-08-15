#include <stdio.h>
#include "bmp.h"

void initBMP(char* sPath, BMPHeader* pHeader, BMPInfoHeader* pInfoHeader, uint8_t** ppImage) {
  FILE *pFile = fopen(sPath, "rb");
  
  if (!pFile) {
      perror("Unable to open file");
      return;
  }

  fread(pHeader, sizeof(BMPHeader), 1, pFile);
  fread(pInfoHeader, sizeof(BMPInfoHeader), 1, pFile);

  if (pHeader->type != 0x4D42) {
      fprintf(stderr, "Not a BMP file\n");
      fclose(pFile);
      return;
  }

  int nWidth = pInfoHeader->width, nHeight = pInfoHeader->height;
  int nSize = nWidth * nHeight * RGB;

  *ppImage = (uint8_t *)malloc(nSize);
  fseek(pFile, pHeader->offset, SEEK_SET);
  fread(*ppImage, 1, nSize, pFile);

  fclose(pFile);
}

void readBMP(BMPInfoHeader header, uint8_t* pImage, uint8_t pixels[header.width][header.height][RGB]) {
  // Convert imageData to the pixelColors array
  int index = 0;
  for (int row = 0; row < header.height; row++) {
      for (int col = 0; col < header.width; col++) {
          pixels[row][col][2] = pImage[index++]; // Red
          pixels[row][col][1] = pImage[index++]; // Green
          pixels[row][col][0] = pImage[index++]; // Blue
      }
  }
}