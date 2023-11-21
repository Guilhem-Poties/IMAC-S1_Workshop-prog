#include "workshop.hpp"


void neGarderQueLeVert(sil::Image image) {
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.f;
            image.pixel(x, y).b = 0.f;
        }
    }
    image.save("output/neGarderQueLeVert.png");
}

void echangerLesCanaux(sil::Image image) {
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::swap(image.pixel(x, y).r, image.pixel(x, y).b);
        }
    }
    image.save("output/EchangerLesCanaux.png");

}

void noirEtBlanc(sil::Image image) {
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float moyenneCouleurs = (image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b) / 3;
            image.pixel(x,y) = {moyenneCouleurs, moyenneCouleurs, moyenneCouleurs};
        }
    }
    image.save("output/noirEtBlanc.png");
}

void negatif(sil::Image image) {
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x,y)={1-image.pixel(x,y).r,1-image.pixel(x,y).g,1-image.pixel(x,y).b};  
        }
    }
    image.save("output/Negatif.png");

}
void degrade(sil::Image image) {

}

void miroir(sil::Image image, bool horizontal) {
    if (horizontal)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height()/2; y++)
            {
                std::swap(image.pixel(x,y), image.pixel(x,image.height() -(y+1)));
            }
        }
    }
    else
    {
        for (int x{0}; x < image.width()/2; x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                std::swap(image.pixel(x,y), image.pixel(image.width() -(x+1),y));
            }
        }    
    }
    image.save("output/miroir.png");
}

void imageBruitee(sil::Image image) {
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (random_int(0, 4) == 0)
            {
                image.pixel(x, y).r = random_float(0.f, 1.f);
                image.pixel(x, y).b = random_float(0.f, 1.f);
                image.pixel(x, y).g = random_float(0.f, 1.f);
            }
        }
    }
    image.save("output/imageBruitee.png");
}

void rotation90(sil::Image image) {
    sil::Image image2resultat {image.height(),image.width()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            //image2resultat.pixel(x,y)=image.pixel(y,image.width()-x-1);
            image2resultat.pixel(y,image.width()-x-1)=image.pixel(x,y);
        }
    }
    image2resultat.save("output/Rotation.png");
    //std::cout<<image.height()<<" "<<image.width();
    //345 300
}

void splitRGB(sil::Image image) {
    sil::Image nouvelleImage{image.width(), image.height()};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 couleur {0,image.pixel(x,y).g, 0};
            if (x-30 >= 0)
            {
                couleur[0] = image.pixel(x-30,y).r;
            }

            if (x+30 < image.width())
            {
                couleur[2] = image.pixel(x+30,y).b;
            }

            nouvelleImage.pixel(x,y) = couleur;
            
            //image.pixel(x, y) = {image.pixel((x-20 >= 0 ? x-20 : x), y).r, image.pixel(x, y).g, image.pixel((x-20 >= 0 ? x-20 : x), y).r};
        }
    }
    nouvelleImage.save("output/splitRGB.png");
}

void luminosite(sil::Image image);

void disque(int rayon) {
    sil::Image image {500, 500};

    if (rayon < 250)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if (pow(x-250,2.0)+pow(y-250,2.0)< pow(rayon,2.0))
                {
                    image.pixel(x,y) = {1, 1, 1};
                }
                
            }
        }
    }
    image.save("output/disque.png");
}

void cercle(int rayon, int epaisseur, int centre) {

}

void rosace(int rayon, int epaisseur, int centre);

void mosaique(sil::Image image, int repetition) {
    sil::Image nouvelleImage {image.width(), image.height()};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            nouvelleImage.pixel(x,y) = image.pixel((x*repetition)%image.width(),(y*repetition)%image.height());
        }
    }
    nouvelleImage.save("output/mosaique.png");
}

void mosaiqueMiroir(sil::Image image, int repetition) {
    sil::Image nouvelleImage {image.width(), image.height()};

    bool miroirHorizontal {false};
    bool miroirVertical {false};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if ((x/(image.width()/repetition))%2 != 0)
            {
                miroirHorizontal = true;
            }
            
            if (miroirHorizontal)
            {
                nouvelleImage.pixel(x,y) = image.pixel(((image.width() - (x+1))*repetition)%image.width(),(y*repetition)%image.height());
            }
            else
            {
                nouvelleImage.pixel(x,y) = image.pixel((x*repetition)%image.width(),(y*repetition)%image.height());
            }
            
        }
    }
    nouvelleImage.save("output/mosaiqueMiroir.png");
}

void glitch(sil::Image image) {
    int w {};
    int h {};

    struct position {
        int x;
        int y;
    };

    position pos1 {};
    position pos2 {};

    for (int _{0}; _ < 75; _++)
    {
        w = random_int(15, 40);
        h = random_int(2, 10);

        pos1 = {random_int(0,image.width()-(w+1)), random_int(0,image.height()-(h+1))};
        pos2 = {random_int(0,image.width()-(w+1)), random_int(0,image.height()-(h+1))};

        for (int x{0}; x < w; x++)
        {
            for (int y{0}; y < h; y++)
            {
                std::swap(image.pixel(pos1.x+x, pos1.y+y), image.pixel(pos2.x+x, pos2.y+y));
            }
        }
    }
    image.save("output/glitch.png");
}

void fractaleMandelbrot(sil::Image image);

void vortex(sil::Image image);

void tramage(sil::Image image);

void normalisationHistogramme(sil::Image image);

void convolutions(sil::Image image);

void netteteContoursEtc(sil::Image image);

void filtresSeparables(sil::Image image);

void differencesGaussiennes(sil::Image image);

void triPixel(sil::Image image);

void filtreKuwahara(sil::Image image);

void Kmeans(sil::Image image);

void diamondSquare(sil::Image image);

void heightMap(sil::Image image);


//Bonus

void croix(int taille) {
    sil::Image image {500, 500};

    if (taille < 250)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if ((x > ((image.width() - taille)/2) && (x < image.width() - ((image.width() - taille)/2))) || (y > ((image.height() - taille)/2) && (y < image.height() - ((image.height() - taille)/2))))
                {
                    image.pixel(x,y) = {1, 1, 1};
                }
                
            }
        }
    }
    image.save("output/croix.png");
}

void mariniere(sil::Image image) {
    sil::Image nouvelleImage {image.width(), image.height()};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            nouvelleImage.pixel(x,y) = image.pixel(x%5,y%5);
        }
    }

    nouvelleImage.save("output/mariniere.png");
}

void symetrie(sil::Image image){
    sil::Image image2resultat {image.height(),image.width()};
    
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image2resultat.pixel(y,x)=image.pixel(x,y);
        }
    }
    image2resultat.save("output/Symetrie.png");
}