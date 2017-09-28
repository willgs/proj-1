#include <time.h> 
#include <stdlib.h>
pragma pack(1)

struct BMPhead{
    WORD format;
    DWORD size;
    WORD resVal1;
    WORD resVal2;
    DWORD Offset;
};

struct DIBhead{
    DWORD headSize;
    LONG width;
    LONG height;
    WORD planes;
    WORD bCount;
    DWORD comp;
    DWORD imageSize;
    LONG horRes;
};

int main(char[] args){

    struct BMPhead bmphead;
    struct DIBhead dibhead;
    FILE *file;

    file = fopen(args, 'r');

    fread(&bmphead, sizeof(bmphead), 1, file);

    if(bmphead.format != 19778)
    {
        printf("Unsupported file type, you may try again.");
        return 0;
    }

    fread(&dibhead, sizeof(dibhead), 1, file);

    if(dibhead.headSize != 40){
        printf("Unsupported file type, you may try again.")
        return 0;
    }
    
     if(dibhead.bCount != 24){
        printf("Unsupported file type, you may try again. ")
        return 0;
    }

    fseek(file, bmphead.Offset, SEEK_SET);

    unsigned char *bmpImage = (insigned
char*)malloc(dibhead->imageSize);

    fread(bmpImage, dibhead->imageSize, file);

        printf("Unsupported file type, you may try again. ")
        return 0;
    }

    fseek(file, bmphead.Offset, SEEK_SET);
    
    unsigned char *bmpImage = (insigned char*)malloc(dibhead->imageSize);

    fread(bmpImage, dibhead->imageSize, file);

    bmpImage = ~bmpImage;

    fseek(file, bmhhead.Offset, SEEK_SET);
    fwrite(bmpImage, dibhead->imageSize, file);
}
