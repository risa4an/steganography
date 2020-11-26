#include "steganography.h"
#include "string"
#include "QImage"
#include "QColor"

steganography::steganography(char *url)
{
    url = url;
    image = QImage(url);
}

int *ByteToBit(char letter){
    int *mass = new int[8];
    int t, i;
                for (t = 128, i = 0; t > 0; t /= 2, i++)
                {
                    if ((letter & t) != 0) mass[i] = 1;
                    else if ((letter & t) == 0) mass[i] = 0;
                }
      return mass;
}

int GetBitValue (unsigned char byte, int n){
    int k = 256;

          for (int i = 0; i < n; i++) k /= 2;

          if ((byte & k) != 0) return 1;
          else return 0;
}

unsigned char PixelToBit(unsigned char Pixel, int bit){
    unsigned char a = 00000001;
    unsigned char Result = Pixel;
    if (bit == GetBitValue(Pixel,8)) return Pixel;
            else if (bit == 1) return Result = Result|a;
                 else if (bit == 0) return Pixel - a;
    return NULL;
}

void encrypt(string text, char *url){
    QImage image = QImage(url);
    int x = 0, y = 0;
    for (int i; i < text.length(); i++){
        int *letter = ByteToBit(text[i]);
        for (int k = 0; k < 8; k++){
            QColor color = image.pixelColor(x, y);
            unsigned char red = color.red();
            unsigned char green = color.green();
            unsigned char blue = color.blue();
            green = PixelToBit(green, letter[k]);
            image.setPixelColor( x, y, QColor(red, green, blue));
        }
    }
    image.save(url);
}




