#include "workshop.hpp"
#include <iostream>

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

void miroir(sil::Image image, sens sens) {
    if (sens == sens::horizontal)
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

void splitRGB(sil::Image image, int ecart) {
    sil::Image nouvelleImage{image.width(), image.height()};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            glm::vec3 couleur {0,image.pixel(x,y).g, 0};
            if (x-ecart >= 0)
            {
                couleur[0] = image.pixel(x-ecart,y).r;
            }

            if (x+ecart < image.width())
            {
                couleur[2] = image.pixel(x+ecart,y).b;
            }

            nouvelleImage.pixel(x,y) = couleur;
            
            //image.pixel(x, y) = {image.pixel((x-20 >= 0 ? x-20 : x), y).r, image.pixel(x, y).g, image.pixel((x-20 >= 0 ? x-20 : x), y).r};
        }
    }
    nouvelleImage.save("output/splitRGB.png");
}

void luminosite(sil::Image image)
{
    sil::Image clair{image.width(), image.height()};
    sil::Image sombre{image.width(), image.height()};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            clair.pixel(x,y).r=pow(image.pixel(x,y).r,0.5);
            clair.pixel(x,y).g=pow(image.pixel(x,y).g,0.5);
            clair.pixel(x,y).b=pow(image.pixel(x,y).b,0.5);

            sombre.pixel(x,y).r=pow(image.pixel(x,y).r,2.0);
            sombre.pixel(x,y).g=pow(image.pixel(x,y).g,2.0);
            sombre.pixel(x,y).b=pow(image.pixel(x,y).b,2.0);
        }
    }
    clair.save("output/luminositeClair.png");
    sombre.save("output/luminositeSombre.png");

}

void disque(int rayon) {
    sil::Image image {500, 500};

    if (rayon < 250)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if (pow(x-250,2.0)+pow(y-250,2.0)< pow(rayon,20))
                {
                    image.pixel(x,y) = {1, 1, 1};
                }
                
            }
        }
    }
    image.save("output/disque.png");
}

void cercle(int rayon, int epaisseur) {
    sil::Image image {500, 500};
    int rayon2{};
    rayon2 = rayon - epaisseur;

    if (rayon < 250)
    {
        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y < image.height(); y++)
            {
                if (pow(x-250,2.0)+pow(y-250,2.0)< pow(rayon,2.0)&& pow(x-250,2.0)+pow(y-250,2.0)> pow(rayon2,2.0))
                {
                    image.pixel(x,y) = {1, 1, 1};
                }
                
            }
        }
    }
    image.save("output/cercle.png");
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
            if (((x/(image.width()/repetition)))%2 != 0)
            {
                miroirHorizontal = true;
            }
            else
            {
                miroirHorizontal = false;
            }
            
            if (((y/(image.height()/repetition)))%2 != 0)
            {
                miroirVertical = true;
            }
            else
            {
                miroirVertical = false;
            }
            
            if (miroirHorizontal && miroirVertical)
            {
                nouvelleImage.pixel(x,y) = image.pixel(((image.width() - (x+1))*repetition)%image.width(),((image.height() - (y+1))*repetition)%image.height());
            }
            else if (miroirVertical)
            {
                nouvelleImage.pixel(x,y) = image.pixel((x*repetition)%image.width(),((image.height() - (y+1))*repetition)%image.height());
            }
            else if (miroirHorizontal)
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

void glitch(sil::Image image, int intensite) {
    int w {};
    int h {};

    struct position {
        int x;
        int y;
    };

    position pos1 {};
    position pos2 {};

    for (int _{0}; _ < intensite; _++)
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

void fractaleMandelbrot()
{
    sil::Image image{500/*width*/, 500/*height*/};

    //std::complex<float> c{3.f, 2.f}; // Définis le nombre c = 3 + 2*i
    
    for (float x{0}; x < image.width(); x++)
    {
        for (float y{0}; y < image.height(); y++)
        {
            float a = ((x*4)/500)-2;
            float b = ((y*4)/500)-2;
            //std::cout << a << "  " << b << std::endl;
            std::complex<float> z{0.f,0.f};
            std::complex<float> c{a , b};
            for(int i{0}; i<50; i++)
            {
                z = z * z + c;
            }
            if (std::abs(z)<2)
            {
                image.pixel(x,y) = {1, 1, 1};
            }
        }
    }
    image.save("output/fractale.png");
}

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle) {
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}

void vortex(sil::Image image, forme forme, unsigned int intensite) {
    sil::Image nouvelleImage{image.width(), image.height()};

    glm::vec2 center {image.width()/2, image.height()/2};
    glm::vec2 point {};

    float angle = 2*M_PI;

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (forme == forme::losange)
            {
                point = rotated({x,y}, center, (angle * ((abs(center[0] - x))/image.width()/2 + abs(center[1] - y)/image.height()/2) * intensite));
            }
            else if (forme == forme::ciculaire)
            {
                point = rotated({x,y}, center, sqrt(pow(abs(center[0] - x),2.0) + pow(abs(center[1] - y), 2.0)) * intensite);
            }
            
            
            if (0 <= point[0] && point[0] < image.width() && 0 <= point[1] && point[1] < image.height())
            {
                nouvelleImage.pixel(x,y) = image.pixel(point[0], point[1]);
            }
        }
    }
    nouvelleImage.save("output/vortex.png");
}

void tramage(sil::Image image);

void normalisatiHistogramme(sil::Image image);

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

void caleidoscope(sil::Image image) {
    sil::Image nouvelleImage{image.width(), image.height()};

    glm::vec2 center {image.width()/2, image.height()/2};
    glm::vec2 point {};

    float angle = M_PI;

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            point = rotated({x,y}, center, (angle * (x - center[0])) * (angle * (y - center[1])) * M_PI);
            if (0 <= point[0] && point[0] < image.width() && 0 <= point[1] && point[1] < image.height())
            {
                nouvelleImage.pixel(x,y) = image.pixel(point[0], point[1]);
            }
        }
    }
    nouvelleImage.save("output/caleidoscope.png");
}

void reflet(sil::Image image) {
    sil::Image nouvelleImage{image.width(), image.height()};

    glm::vec2 center {image.width()/2, image.height()/2};
    glm::vec2 point {};

    float angle = M_PI;

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            point = rotated({x,y}, center, angle * ((x - center[0]) + (y - center[1])));
            if (0 <= point[0] && point[0] < image.width() && 0 <= point[1] && point[1] < image.height())
            {
                nouvelleImage.pixel(x,y) = image.pixel(point[0], point[1]);
            }
        }
    }
    nouvelleImage.save("output/reflet.png");
}

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