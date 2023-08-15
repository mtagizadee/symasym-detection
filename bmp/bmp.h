#include <stdint.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

#define RGB 3

void initBMP(char* sPath, BMPHeader* pHeader, BMPInfoHeader* pInfoHeader, uint8_t** ppImage);
void readBMP(BMPInfoHeader header, uint8_t* pImage, uint8_t pixels[header.width][header.height][RGB]);