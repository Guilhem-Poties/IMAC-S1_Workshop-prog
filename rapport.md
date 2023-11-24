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