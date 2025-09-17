#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 50
#define MAX 10

/*
On considère pour les exercices 1 à 9, un tableau d'entiers tab de taille TAILLE de -MAX à MAX
    5) Écrire un programme qui applique un coefficient entier a aux éléments du tableau.
    8 ) Écrire un programme qui calcule la médiane du tableau.
*/


// 1) Écrire un programme qui dénombre les nombres positifs et négatifs. On considère 0 comme étant un nombre positif.
int denombre(int tab[],int size, int signe){
    int count = 0;
    for(int i = 0; i < size - 1;i++){
        if(tab[i]>=0){
            count++;
        }
    }

    if(signe>= 0){
        return count;
    }
    else{
        return size - count;
    }
}

// 2) Écrire un programme qui calcule la somme du tableau.

int sommetab(int tab[],int size){
    int somme = 0;
    for(int i = 0; i < size - 1;i++){
        somme += tab[i];
    }
    return somme;
}

// 3) Écrire un programme qui calcule la moyenne du tableau.
float moyennetab(int tab[],int size){
    int somme = sommetab(tab,size);
    float moyenne = (float) somme/size;
    return moyenne;
}

// 4) Écrire un programme qui récupère les valeurs minimales et maximales du tableau.

int minmaxtab(int tab[], int size,int signe){
    int min = tab[0], max = tab[0];
    for(int i = 1; i < size - 1;i++){
        if(tab[i]<min){
            min = tab[i];
        }
        if(tab[i]>max){
            max = tab[i];
        }
    }
    if(signe>=0){
        return max;
    }else{
        return min;
    }
}

// 6) Écrire un programme qui décale tous les éléments du tableau d'une case vers la droite (vers la fin du tableau).

int decalagedroite(int* tab,int size){
    int temp = *(tab +size - 1);
    for(int i = size - 1 ; i >=1;i--){
        *(tab+i) = *(tab + i - 1);
    }
    *(tab) = temp; 
        
    return 0;

}

// 7) Écrire un programme qui trie le tableau. L'algorithme est au choix de l'étudiant.

int indicemin(int* tab, int size, int signe) {
    int indmin = 0;
    for (int i = 1; i < size; i++) {            // commence à 1
        if (*(tab + i) <= *(tab + indmin)) {    // cherche le min
            indmin = i;
        }
    }
    return indmin;
}

void tri(int* tab, int size) {
    int temp, min;
    for (int i = 0; i < size; i++) {
        // calcul de l'indice du min à partir de tab[i...size-1]
        min = indicemin(tab + i, size - i, -1);

        // échange tab[i] et tab[min+i] avec *(tab+i) = tab[i]
        temp = *(tab + i);
        *(tab + i) = *(tab + min + i);
        *(tab + min + i) = temp;
    }
}


// 9 ) Écrire un programme qui dénombre les éléments du tableau. On considère que les éléments ne peuvent prendre des valeurs qu'entre 0 et 9.
int denombretab(int tab[], int size) {
    int compte[10] = {0}; // initialisation à 0

    for (int i = 0; i < size; i++) {
        if (tab[i] >= 0 && tab[i] <= 9) {
            compte[tab[i]]++;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("compte[%2d] = %4d\n", i, compte[i]);
    }

    return 0;
}


// affichage

void affichetab(int tab[],int size){
     for(int i = 0; i < size ;i++){
        printf(" tab[%2d] = %4d |",i, tab[i]);
        if((i+1)%5 ==0){
            printf("\n");
        }
    }
    printf("\n");

}



int main(){
    srand(time(NULL));
    int tab[TAILLE];
    //création du tableau tab
    for(int i = 0; i < TAILLE ;i++){
        tab[i] = rand()%(2*MAX +1 ) - MAX;
    }
    affichetab(tab,TAILLE);
    printf("1) Il y a %d nombres positifs et %d nombres négatifs\n",denombre(tab,TAILLE,1),denombre(tab,TAILLE,-1));
    printf("2) La somme de tous les éléments du tableau est %d\n",sommetab(tab,TAILLE));
    printf("3) La moyenne de tous les éléments du tableau est %.2f\n",moyennetab(tab,TAILLE));
    printf("4) Le minimum est %d et le maximum est %d\n", minmaxtab(tab,TAILLE,-1), minmaxtab(tab,TAILLE,1));
    printf("6) On décale le tableau vers la droite\n");
    decalagedroite(tab,TAILLE);
    printf("7) On trie le tableau\n");
    tri(tab,TAILLE);
    affichetab(tab,TAILLE);
    printf("9) On compte les occurences entre 0 et 9\n");
    denombretab(tab,TAILLE);
}