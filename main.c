#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#pragma pack(1);

typedef unsigned int DWORD;
typedef short WORD;


struct BMPhead{
    WORD format;
    DWORD size;
    DWORD resVal1;
    WORD resVal2;
    DWORD Offset;
};

struct DIBhead{
    DWORD headSize;
    long width;
    long height;
    WORD planes;
    WORD bCount;
    DWORD comp;
    DWORD imageSize;
    long horRes;
};

int main(char args[]){

    struct BMPhead bmphead;
    struct DIBhead dibhead;
    FILE *img;

    img = fopen(args, 'r');

    fread(&bmphead, sizeof(bmphead), 1, img);

    if(bmphead.format != 19778)
    {
        printf("Unsupported file type, you may try again.");
        return 0;
    }

    fread(&dibhead, sizeof(dibhead), 1, img);

    if(dibhead.headSize != 40){
        printf("Unsupported file type, you may try again.");
        return 0;
    }
    
     if(dibhead.bCount != 24){
        printf("Unsupported file type, you may try again. ");
        return 0;
    }

    fseek(img, bmphead.Offset, SEEK_SET);

    unsigned char *bmpImage = (unsigned char*)malloc(dibhead.imageSize);

    fread(bmpImage, sizeOf(unsigned int), dibhead.imageSize, img);
    
    bmpImage = ~bmpImage;

    fseek(img, bmhhead.Offset, SEEK_SET);
    fwrite(bmpImage, dibhead->imageSize, img);
}
