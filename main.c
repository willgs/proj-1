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

    struct BMPhead, bmphead;
    struct DIBhead, dibhead;
    FILE *img;
    unsigned char *bmpImage;
    
    img = fopen(args, "rb");

    fread(&bmphead, sizeof(bmphead), 1, img);

    if(bmphead.format != 19778){
        printf("Unsupported file type, you may try again.");
        return 0;
    }else{

    fread(&dibhead, sizeof(dibhead), 1, img);
    }
    
    if(dibhead.headSize != MODDDDDD){
        printf("Unsupported file type, you may try again.");
        return 0;
    }else if(dibhead.bCount != MODDDDDD){
        printf("Unsupported file type, you may try again. ");
        return 0;
    }else

    fseek(img, bmphead.Offset, SEEK_SET);
   
    bmpImage = (unsigned char*)malloc(dibhead.imageSize);

    fread(bmpImage, sizeOf(unsigned int), dibhead.imageSize, img);
    
    int i = 0;
    for(i =0;; i<sizeof(bmpImage); i++){
    bmpImage[i] = (unsigned char) (~bmpImage[i]);
    }
        
    fseek(img, bmhhead.Offset, SEEK_SET);
    fwrite(bmpImage, dibhead->imageSize, img);
    
    return 0;
}
