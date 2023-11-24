#pragma once

#include <sil/sil.hpp>
#include "random.hpp"
#include <math.h>
#include <complex>
#include <glm/gtx/matrix_transform_2d.hpp>
#include <iostream>
#include <algorithm>


void neGarderQueLeVert(sil::Image image);
/*Fait
Aucune difficulté
Mettre le bleu et le rouge à 0
*/

void echangerLesCanaux(sil::Image image);
/*Fait
Aucune difficulté en utilisant l'indice
utilisation de swap pour les couleurs
*/

void noirEtBlanc(sil::Image image);
/*Fait
Difficulté à trouver la formule
Faire la moyenne des couleurs d'un pixel et mettre chacun des canaux à cette moyenne
*/

void negatif(sil::Image image);
/*Fait
Aucune difficulté une fois la formule du noir et blanc saisie
Pour chacune des couleurs faire 1 - la valeur de la couleur
*/

void degrade();

enum sens {horizontal, vertical};

void miroir(sil::Image image, sens sens = sens::vertical);
/*Fait
Aucune difficulté
Echanger tous les pixels avec leurs pixels opposés sur l'axe horizontal
*/

void imageBruitee(sil::Image image);
/*Fait
Aucune difficulté
Utilisation de la fonction random pour que chaque pixel ait 
une certaine chance d'être changé en une couleur aléatoire
*/

void rotation90(sil::Image image);
/*Fait
Difficultés à comprendre qu'il fallait créer une nouvelle image 
,le mécanisme à utiliser pour retourner les pixels (réalisation d'une symétrie avant réussite)
et l'ajout d'un -1 pour ne pas dépasser le cadre
Donner de nouvelles coordonnées à la nouvelle image (de dimensions inversées) 
à partir des coordonnées de l'image originelle 
*/

void splitRGB(sil::Image image, int ecart = 30);
/*Fait
Difficultés à comprendre qu'il fallait créer une nouvelle image
et comment décaler les pixels sans sortir du cadre
Chaque pixel sur la nouvelle image regarde, s'il le peut le rouge sur un pixel 
qui le précède, le bleu sur un qui le devance et le vert à ses coordonnées actuelles
*/

void luminosite(sil::Image image);
/*Fait
Difficultés à comprendre sur quoi appliquer la puissance
On créé deux nouvelles images sur une on applique une puissance 1/2 sur 
les paramètre rgb de l'image de départ pour l'éclaicir et sur l'autre une 
puissance 2 pour l'assombrir
*/

void disque(int rayon);
/*Fait
Dificulté à trouver la bonne formule pour le cercle.
On colore en blanc les pixels se trouvant à l'intérieur du cercle de rayon r
*/

void cercle(int rayon, int epaisseur);
/*Fait 
Aucune difficulté une fois le disque trouvé.
On rajoute une condition pour colorer les pixels dans le cercle extérieur mais
en dehors du cercle intérieur.
*/

void rosace(int rayon, int epaisseur, int centre);

void mosaique(sil::Image image, int repetition = 5);
/*Fait
Difficulté à toruver l'emplacement correct du modulo
Sur une une nouvelle image prend un pixel sur le nombre de répétition 
pour le recopier et faire n^2 répetition de l'image en plus pixélisée*/

void mosaiqueMiroir(sil::Image image, int repetition = 5);
/*Fait
Grande difficulté à gérer l'alternance entre les portions miroirs et le sens de leur inversion
*/

void glitch(sil::Image image, int intensite = 75);
/*Fait
Difficulté à gérer les nombreuses opérandes simultanément
Création d'une boucle, chaque itération correspondant à un glitch, 
glitch représenté par l'échange de deux rectangles dont les positions (gérées par un struct)
et dimmensions sont définies aléatoirement à chaque itération
*/

void fractaleMandelbrot();

enum forme {ciculaire, losange};

void vortex(sil::Image image, forme forme = forme::losange, unsigned int intensite = 20);
/*Fait
Difficulté à définir l'angle de rotation par point
*/

void tramage(sil::Image image);

void normalisationHistogramme(sil::Image image);
/*Fait
Difficulté à trouver la formule correcte de normalisation*/

void convolutions(sil::Image image);
/*Fait
Difficulté à trouver les bonnes conditions des boucles
*/

void netteteContoursEtc(sil::Image image);

void filtresSeparables(sil::Image image);

void differencesGaussiennes(sil::Image image);

float brightness(glm::vec3 v);

void triPixel(sil::Image image);

glm::vec3 moyenneLuminosite(std::vector<glm::vec3> ensembleCouleurs);

float ecarType(std::vector<glm::vec3> ensembleCouleurs);

void filtreKuwahara(sil::Image image, int taille = 5);

void Kmeans(sil::Image image);

sil::Image diamondSquare();

void heightMap();


//Bonus

void caleidoscope(sil::Image image);

void reflet(sil::Image image);

void croix(int taille);

void mariniere(sil::Image image);
/*Fait
Erreur en expérimentant le modulo de la mosaïque
Mais qui peut flex d'avoir une marinière     /
                                            /_/\_
*/

void symetrie(sil::Image image);