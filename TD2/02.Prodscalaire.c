// Écrire un programme qui calcule le produit scalaire de deux tableaux tab1 et tab2 de taille TAILLE.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 50
#define MAX 100

void affichetab(int tab[],int size,const char *nom){
     for(int i = 0; i < size ;i++){
        printf(" %s[%2d] = %4d |",nom,i, tab[i]);
        if((i+1)%5 ==0){
            printf("\n");
        }
    }
    printf("\n");

}



int main(){
    srand(time(NULL));
    int tab[TAILLE], tab2[TAILLE];
    //création du tableau tab1 et tab2
    for(int i = 0; i < TAILLE ;i++){
        tab[i] = rand()%(2*MAX +1 ) - MAX;
        tab2[i] = rand()%(2*MAX +1 ) - MAX;
    }

    affichetab(tab,TAILLE,"tab");
    affichetab(tab2,TAILLE,"tab2");

    int prodscal = 0;
    for(int i = 0; i<TAILLE;i++){
        prodscal += tab[i]*tab2[i];
    }
    printf("Produit scalaire %d\n", prodscal);
}
