#ifndef BMP_H
#define BMP_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "pixel.h"

using namespace std;

struct dataFileInfo {
    int width = 0;
    int height = 0;
};

class bmp
{
private:
    dataFileInfo fileinfo;
    unsigned char* lastData;
    int width = 0;
    int height = 0;
public:
    bmp();
    unsigned char* readBMP(string filename);
    uint32_t **convertToUint32(unsigned char *data);
    int getWidth() const;
    int getHeight() const;
    void bmpExport(string path, int width, int height, pixel **matrix);
};

#endif // BMP_H
