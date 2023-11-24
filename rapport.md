#Rapport du Workshop de programmation
#####Jacquelin Marie
#####Poties Guilhem

<br/>

###Ne garder que le vert ★
</br>

Nous n'avons rencontré aucune difficulté pour ce code.</br>
Pour implémenter cet effet, nous avons mis les canaux bleu et rouge à 0.
</br>

Résultat : 
![image](./output/neGarderQueLeVert.png)

</br>
</br>

###Echanger les canaux ★

Nous n'avons rencontré aucune difficulté après avoir lu l'indice indiquant d'utiliser la fonction swap</br>
Pour implémenter cet effet, nous avons échanger les couleurs rouge et bleue.
</br>
<details><summary>Code de swap</summary>

```cpp
std::swap(image.pixel(x, y).r, image.pixel(x, y).b);
```
</details>
</br>

Résultat : 
![image](./output/echangerLesCanaux.png)
</br>
</br>

###Noir et Blanc ★

Nous avons eu du mal à trouver la formule .</br>
Finalement, on a fait la moyenne des couleurs d'un pixel et on a donné à chacun des canaux la valeur de cette moyenne.
</br>
<details><summary>Code de la moyenne</summary>

```cpp
float moyenneCouleurs = (image.pixel(x,y).r + image.pixel(x,y).g + image.pixel(x,y).b) / 3;
            image.pixel(x,y) = {moyenneCouleurs, moyenneCouleurs, moyenneCouleurs};
```
</details>
</br>

Résultat : 
![image](./output/noirEtBlanc.png)
</br>
</br>

###Négatif ★

Nous n'avons eu aucune difficulté après avoir implémenter l'effet noir et blanc. </br>
Pour chacune des couleurs on a fait 1 - la valeur de cette couleur
</br>

Résultat : 
![image](./output/negatif.png)
</br>
</br>

###Miroir ★★

Nous n'avons pas rencontré de difficultés.
Nous avons échanger tous les pixels avec leurs pixels opposés sur l'axe horizontal.

Résultat : 
![image](./output/miroir.png)
</br>
</br>

###Image bruitée ★★

Nous n'avons pas rencontré de difficultés.
Nous avons utiliser la fonction random pour que chaque pixel ait une certaine chance d'être changé en une couleur aléatoire.

Résultat : 
![image](./output/imageBruitee.png)
</br>
</br>

###Rotation à 90° ★★

Nous avons eu du mal à comprendre qu'il fallait créer une nouvelle image et à comprendre le mécanisme à utiliser pour retourner les pixels (réalisation d'une symétrie avant réussite).
On a aussi dû faire attention à ajouter un -1 pour ne pas dépasser le cadre.
On a donc donner de nouvelles coordonnées à la nouvelle image (qui a des dimensions inversées) à partir des coordonnées de l'image de départ. 

Résultat : 
![image](./output/rotation.png)
</br>
</br>

###Split RGB ★★

Nous avons eu des difficultés à comprendre qu'il fallait créer une nouvelle image et comment décaler les pixels sans sortir du cadre.
Dans notre code, chaque pixel sur la nouvelle image regarde, s'il le peut, le rouge sur un pixel qui le précède, le bleu sur un qui le devance et le vert à ses coordonnées actuelles.

Résultat : 
![image](./output/splitRGB.png)
</br>
</br>

###Luminosité ★★

Nous avons eu des difficultés à comprendre sur quoi appliquer la puissance.
On créé deux nouvelles images: sur une on applique une puissance 1/2 sur les paramètre rgb de l'image de départ pour l'éclaicir et sur l'autre une puissance 2 pour l'assombrir.

Résultat : 
![image](./output/luminositeClair.png)
![image](./output/luminositeSombre.png)
</br>
</br>

###Disque ★★

Nous avons eu du mal à trouver la bonne formule pour le cercle.
On colore en blanc les pixels se trouvant à l'intérieur du cercle de rayon r.

Résultat : 
![image](./output/disque.png)
</br>
</br>