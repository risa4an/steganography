#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H
#include "QImage"
#include "string"

using namespace std;
class steganography
{

public:
    steganography(char *url);
    int max_text_size;
     QImage image;
    void encrypt(string text);
    char * url;

private:

    int *ByteToBit (char letter);
    void PixelToBit(int k, int l, int b);
    int GetBitValue (unsigned char byte, int n);
};

#endif // STEGANOGRAPHY_H
