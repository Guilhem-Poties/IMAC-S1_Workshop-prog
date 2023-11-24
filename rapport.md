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
<details><summary>Code swap</summary>

```cpp
std::swap(image.pixel(x, y).r, image.pixel(x, y).b);
```
</details>
</br>
Nous n'avons rencontré aucune difficulté après avoir lu l'indice indiquant d'utiliser la fonction swap</br>
Pour implémenter cet effet, nous avons échanger les couleurs rouge et bleue.
</br>
</br>

Résultat : 
![image](./output/echangerLesCanaux.png)
</br>
</br>