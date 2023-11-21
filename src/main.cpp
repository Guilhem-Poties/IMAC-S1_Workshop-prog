#include "workshop.hpp"

int main()
{
    sil::Image image{"images/logo.png"};

    mosaiqueMiroir(image, 5);

    return 0;
}