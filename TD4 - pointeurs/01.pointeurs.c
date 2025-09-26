#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Écrire une fonction qui prend un pointeur sur un entier en argument, 
//retourne son carré et incrémente de 1 l'entier contenu à l'adresse du pointeur.

int fonctionExo1(int *i){
    int temp = (*i); 
    (*i)++;
    return temp * temp;
}

/*
ex 2 : Définir une structure de donnée représentant un nombre complexe. 
Puis écrire une fonction qui permet de récupérer un nombre complexe sur l'entrée 
standard, et de retourner le nombre complexe ainsi que son module i.e. 
la distance qui le sépare du point origine.
*/

struct complexe{
    float reel;
    float img;
    float module;
};

int recupComplexe(struct complexe *c1){
    printf("Entrez la partie réelle : ");
    scanf(" %f", &c1->reel);
    printf("Entrez la partie imaginaire : ");
    scanf(" %f", &c1->img);
    c1->module = sqrt(pow(c1->reel,2)+pow(c1->img,2));
}


int main(){
    /* exo 1
    int entier;
    printf("Donnez un nombre : ",entier);
    scanf(" %d",&entier);
    printf("Carré de %d\n",entier);
    printf("%d\n",fonctionExo1(&entier),entier);
    printf("On rajoute 1 au nombre : %d\n",entier);
    */

    /*exo 2
    struct complexe c1;
    recupComplexe(&c1);
    printf("%f %f %f",c1.reel,c1.img,c1.module);
    */

    // exo 3
 
    int taille, *tablo; 
    printf("Donnez la taille du tableau svp : ");
    scanf(" %d",&taille);
    
    tablo = malloc(taille * sizeof(int));

    for(int i = 0; i<taille;i++){
        switch(i){
            case 0 : 
                *(tablo + i) = 0;
                break;
            case 1 :
                *(tablo + i) = 1;
                break;
            default :
                *(tablo + i) = *(tablo + i - 1) + *(tablo + i - 2);
                break;
        }
        printf("tablo[%d] : %d \n",i,tablo[i]);
    }

    /* exo 4 Écrire une fonction qui réalloue un tableau d'entiers de taille n pour qu'il
    soit d'une taille m, plus grande. Le contenu du tableau doit être copié dans le nouveau
     tableau, et l'ancien tableau doit être libéré. Ceci sans utiliser la fonction realloc(). */

    int *tablo2;
    tablo2 = malloc((taille+10) * sizeof(int));
    for(int j = 0; j<taille; j++){
        *(tablo2+j) = *(tablo+j);
    }
    free(tablo);

    for(int k = 0; k<taille; k++){
        printf("tablo2[%d] : %d \n",k,tablo2[k]);    
    }
    free(tablo2);
}