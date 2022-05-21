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

    for (int i = 0; i < size; i+=3) {
        unsigned char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
    }

    this->lastData = data;

    return data;
}

uint32_t **bmp::convertToUint32(unsigned char* data) {
     uint32_t** image2 = new uint32_t*[this->width];
    for (int i = 0; i < this->width; i++) {

        image2[i] = new uint32_t[this->height];
    }

    uint32_t sum;
    int imageX = 0;
    int imageY = 0;

    for (int i = 0; i < this->width * this->height * 3; i += 3) {
        sum = (data[i] * 0x10000) + (data[i + 1] * 0x100) +(data[i + 2]);
        image2[imageX][imageY] = sum;

        imageX++;

        if (imageX == this->width) {
            imageX = 0;
            imageY++;
        }
    }

    return image2;
}

void bmp::bmpExport(string path, int width, int height, pixel** matrix) {
    ofstream f;
    f.open(path.c_str(), ios::out | ios::binary);

    if (!f.is_open()) {
        std::cerr << "No se puede abrir el archivo.";
        return;
    }

    unsigned char bmpPad[3] = {0, 0, 0};

    const int paddingAmount = ((4 - (width * 3) % 4) % 4);

    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;
    const int fileSize = fileHeaderSize + informationHeaderSize + (width * height * 3);

    unsigned char fileHeader[fileHeaderSize] = {'B', 'M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char informationHeader[informationHeaderSize] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};

    // Tipo de archivo

    // Tamano archivo
    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;

    // Reservados

    // Profundidad pixel

    // Header size
    //informationHeader[0] = informationHeaderSize;
    //informationHeader[1] = 0;
    //informationHeader[2] = 0;
    //informationHeader[3] = 0;

    // Ancho
    informationHeader[4] = width;
    informationHeader[5] = width >> 8;
    informationHeader[6] = width >> 16;
    informationHeader[7] = width >> 24;

    // Alto
    informationHeader[8] = height;
    informationHeader[9] = height >> 8;
    informationHeader[10] = height >> 16;
    informationHeader[11] = height >> 24;

    // Planos
    //informationHeader[12] = 1;
    //informationHeader[13] = 0;

    // Bits por pixel (RGB)
    //informationHeader[14] = 24;
    //informationHeader[15] = 0;

    // Compresion
    //informationHeader[16] = 0;
    //informationHeader[17] = 0;
    //informationHeader[18] = 0;
    //informationHeader[19] = 0;

    // Tamano de imagen
    //informationHeader[20] = 0;
    //informationHeader[21] = 0;
    //informationHeader[22] = 0;
    //informationHeader[23] = 0;

    // Piexeles por metro X
    //informationHeader[24] = 0;
    //informationHeader[25] = 0;
    //informationHeader[26] = 0;
    //informationHeader[27] = 0;

    // Pixeles por metro Y
    //informationHeader[28] = 0;
    //informationHeader[29] = 0;
    //informationHeader[30] = 0;
    //informationHeader[31] = 0;

    // Total color information
    //informationHeader[32] = 0;
    //informationHeader[33] = 0;
    //informationHeader[34] = 0;
    //informationHeader[35] = 0;

    // Colores importantes
   // informationHeader[36] = 0;
    //informationHeader[37] = 0;
    //informationHeader[38] = 0;
    //informationHeader[39] = 0;

    f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
    f.write(reinterpret_cast<char*>(informationHeader), informationHeaderSize);

    unsigned char color[3];
    uint32_t matrixColor;

    for (int y = height - 1; y > 0; y--) {
        for (int x = 0; x < width; x++) {
            matrixColor = matrix[x][y].getColor();
            color[0] = matrixColor;       // b
            color[1] = matrixColor >> 8;  // g
            color[2] = matrixColor >> 16; // r

            f.write(reinterpret_cast<char*>(color), 3);
        }
    }
    f.write(reinterpret_cast<char*>(bmpPad), paddingAmount);

    std::cout << "Archivo creado";
}



