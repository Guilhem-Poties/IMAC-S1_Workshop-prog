#Rapport du Workshop de programmation
#####Jacquelin Marie
#####Poties Guilhem

<br/>

###Ne garder que le vert ★
<details><summary>Code complet</summary>
```cpp
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
```
</details>
</br>
Nous n'avons rencontré aucune difficulté pour ce code.</br>
Pour implémenter cet effet, nous avons mis les canaux bleu et rouge à 0.
</br>
</br>
Résultat : 
![image](./output/neGarderQueLeVert.png)
</br>
</br>

