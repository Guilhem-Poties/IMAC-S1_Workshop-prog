#include "workshop.hpp"

int main()
{
    sil::Image image{"images/logo.png"};

    splitRGB(image);
    
    /*
    int repetition {5};
    sil::Image nouvelleImage {image.width(), image.height()*repetition};

    for (int i{0}; i < repetition^2; i++)
    {
        for (int x{0}; x < image.width()/2; x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                nouvelleImage.pixel(x + ((image.width()*i)%repetition), y + ((image.height()*i)%repetition)) = image.pixel(x,y);
            }
        }
    }

    nouvelleImage.save("output/mosaique.png");
    */
    return 0;
}