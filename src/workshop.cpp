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

void luminosite(sil::Image image) {
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

struct position {
    int x;
    int y;
};

void glitch(sil::Image image, int intensite) {
    int w {};
    int h {};

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
            float i{0};
            while(i<50)
            {
                z = z * z + c;

                if (std::abs(z)>2)
                {
                break;
                }
                i++;
            }
            image.pixel(x,y).r = 0.f + i/50;
            image.pixel(x,y).g = 0.f + i/50;
            image.pixel(x,y).b = 0.f + i/50;
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

void normalisationHistogramme(sil::Image image) {
    //recherche du pixel le plus sombre et du plus luminineux
    glm::vec3 min {1,1,1};
    glm::vec3 max {0,0,0};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            min = glm::min(min, image.pixel(x,y));
            max = glm::max(max, image.pixel(x,y));
        }
    }

    glm::vec3 ratioMax = {1,1,1};

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x,y) = (image.pixel(x,y) - min) * (ratioMax / max) ;
        }
    }
    image.save("output/normalisationHistogramme.png");
}

void convolutions(sil::Image image)
{
    int taille{5};
    
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (x>taille/2 && x<image.width()-taille/2 && y>taille/2 && y<image.height()-taille/2)
            {
                float sommeR{};
                float sommeG{};
                float sommeB{};
                for (int w{(x-taille/2)}; w < ((x-taille/2))+taille; w++)
                {
                    for (int h{(y-taille/2)}; h < ((y-taille/2))+taille; h++)
                    {
                        sommeR+= image.pixel(w,h).r;
                        sommeG+= image.pixel(w,h).g;
                        sommeB+= image.pixel(w,h).b;
                    }
                }
                image.pixel(x,y).r = sommeR/pow(static_cast<float>(taille),2.0);
                image.pixel(x,y).g = sommeG/pow(static_cast<float>(taille),2.0);
                image.pixel(x,y).b = sommeB/pow(static_cast<float>(taille),2.0);
            }
            //pixel=moyenne pixels autour
           /*  if (x>0 && x<image.width()-1 && y>0 && y<image.height()-1)
            {
                image.pixel(x,y).r = (image.pixel(x,y).r + image.pixel(x-1,y-1).r + image.pixel(x,y-1).r + 
                image.pixel(x+1,y-1).r + image.pixel(x+1,y).r + image.pixel(x-1,y).r + image.pixel(x-1,y+1).r +
                image.pixel(x,y+1).r + image.pixel(x+1,y+1).r)/9;

                image.pixel(x,y).g = (image.pixel(x,y).g + image.pixel(x-1,y-1).g + image.pixel(x,y-1).g + 
                image.pixel(x+1,y-1).g + image.pixel(x+1,y).g + image.pixel(x-1,y).g + image.pixel(x-1,y+1).g +
                image.pixel(x,y+1).g + image.pixel(x+1,y+1).g)/9;

                image.pixel(x,y).b = (image.pixel(x,y).b + image.pixel(x-1,y-1).b + image.pixel(x,y-1).b + 
                image.pixel(x+1,y-1).b + image.pixel(x+1,y).b + image.pixel(x-1,y).b + image.pixel(x-1,y+1).b +
                image.pixel(x,y+1).b + image.pixel(x+1,y+1).b)/9;
            } */
        }
    }
    image.save("output/convolutions.png");
}

void netteteContoursEtc(sil::Image image);

void filtresSeparables(sil::Image image);

void differencesGaussiennes(sil::Image image);

float brightness(glm::vec3 v)
{
    return (v.r+v.g+v.b)/3;
}

void triPixel(sil::Image image)
{
    sil::Image nouvelleImage{image.width(), image.height()};
    std::vector<glm::vec3> v{};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            v.push_back(image.pixel(x,y));
        }
    } 
    std::sort(v.begin(), v.end(), [](glm::vec3 const& color1, glm::vec3 const& color2)
    {
        return brightness(color1) < brightness(color2); // Trie selon la luminosité des couleurs (NB : c'est à vous de coder la fonction `brightness`)
    });
    int i{0};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            nouvelleImage.pixel(x,y) = v[i];
            i++;
        }
    }
    
    nouvelleImage.save("output/triPixel.png");
    
}

void filtreKuwahara(sil::Image image);

void Kmeans(sil::Image image);

void diamondSquare() {
    int sizeImage = pow(2, 8) + 1;
    int sizeChunk {sizeImage - 1};
    float roughness {0.5f};

    sil::Image image {sizeImage, sizeImage};

    image.pixel(0,0) = glm::vec3{random_float(0.00f, 1.00f)};
    image.pixel(sizeImage-1,0) =  glm::vec3{random_float(0.00f, 1.00f)};
    image.pixel(0,sizeImage-1) =  glm::vec3{random_float(0.00f, 1.00f)};
    image.pixel(sizeImage-1,sizeImage-1) =  glm::vec3{random_float(0.00f, 1.00f)};


    while (sizeChunk > 1)
    {
        int halfChunk = sizeChunk/2;

        //saquare step
        for (int x = 0; x < sizeImage-1; x += sizeChunk)
        {
            for (int y = 0; y < sizeImage-1; y += sizeChunk)
            {
                image.pixel(x + halfChunk, y + halfChunk) = ((
                    image.pixel(x,y) + image.pixel(x+sizeChunk,y) +
                    image.pixel(x,y+sizeChunk) + image.pixel(x+sizeChunk,y+sizeChunk)) 
                    / glm::vec3 {4}) + glm::vec3 {random_float(-roughness, roughness)};
            }
            
        }
        
        //diamond step
        for (int x = 0; x < sizeImage; x += halfChunk)
        {
            for (int y = (x + halfChunk) % sizeChunk; y < sizeImage; y += sizeChunk)
            {
                glm::vec3 tempPixel {glm::vec3 {0}};
                float count {0};

                if (x-halfChunk >= 0)
                {
                    tempPixel += image.pixel(x-halfChunk, y);
                    count++;
                }
                if (x+halfChunk < image.width())
                {
                    tempPixel += image.pixel(x+halfChunk, y);
                    count++;
                }
                if (y-halfChunk >= 0)
                {
                    tempPixel += image.pixel(x, y-halfChunk);
                    count++;
                }
                if (y+halfChunk < image.height())
                {
                    tempPixel += image.pixel(x, y+halfChunk);
                    count++;
                }

                image.pixel(x, y) = (tempPixel / glm::vec3 {count}) + glm::vec3 {random_float(-roughness, roughness)};
            }
            
        }

        roughness /= 2;
        sizeChunk /= 2;
    }
        image.save("output/diamondSquare.png");
}

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