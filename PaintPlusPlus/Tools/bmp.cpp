#include "bmp.h"

int bmp::getWidth() const
{
    return width;
}

int bmp::getHeight() const
{
    return height;
}

bmp::bmp()
{

}

unsigned char *bmp::readBMP(string filename)
{
    FILE* f = fopen(filename.c_str(), "rb");
    unsigned char info[54];
    fread(&info, sizeof(unsigned char), 54, f);

    int width, height;
    width = *(int*)&info[18];
    height = *(int*)&info[22];

    fileinfo.width = width;
    this->width = width;
    fileinfo.height = height;
    this->height = height;

    int size = width * height * 3;
    unsigned char* data = new unsigned char[size];

    fread(data, sizeof(unsigned char), size, f);
    fclose(f);

    for (int i = 0; i < size; i+= 3) {
        unsigned char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
    }
    this->lastData = data;
    return data;
}

uint32_t **bmp::convertToUint32(unsigned char* data) {
    uint32_t** image = new uint32_t*[fileinfo.width];

    for (int i = 0; i < fileinfo.width; i++) {
        image[i] = new uint32_t[fileinfo.height];
    }

    uint32_t sum;
    int imageX = 0;
    int imageY = 0;

    for (int i = 0; i < (fileinfo.width * fileinfo.height * 3); i += 3) {
        sum = (data[i] * 0x10000) + (data[i + 1] * 0x100) + data[i + 2];
        image[imageX][imageY] = sum;

        imageX++;
        if (imageX == fileinfo.width) {
            imageX = 0;
            imageY++;
        } else if (imageY == fileinfo.height - 1) {
            break;
        }
    }

    for (int i = 0; i < fileinfo.height; i++) {
        for (int j = 0; j < fileinfo.width; j++) {
            printf("%x ", image[i][j]);

        }
        cout << "..."<< endl;
    }

    return image;
}
