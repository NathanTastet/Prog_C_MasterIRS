#include <stdio.h>

// Écrire une fonction qui retourne la valeur d'un entier donné en paramètre incrémenté de 1.
int ajoute1(int nbr){
    return ++nbr;
}

// 17 ) résultat d'une équation ax+b = 0
float equation1erdegre(int a, int b){
    return -(float)b/a;
}

// 18 ) Écrire une fonction qui donne le nombre de racines réelles
// à une équation du second degré : ax² + bx + c = 0
int equation2nddegre(float a,float b, float c){
    float delta = (b*b) - (4*a*c);
    if (delta < 0) {
        return 0; // pas de racine réelle
    }
    if (delta == 0) {
        return 1; // une racine double
    }
    return 2; // deux racines réelles
}

// 20 ) Écrire une fonction qui donne le nombre d'occurences
// d'un nombre n dans un tableau tab de taille donnée.
int occurencesn(int tab[], int n, int taille){
    int compteur = 0;
    for(int i = 0; i < taille; i++){
        if(tab[i] == n){
            ++compteur;
        }
    }
    return compteur;
}

int main(){
    int tab[10] = {2,2,3,3,3,4,4,7,5,5};

    printf("On ajoute 1 à %d : %d\n", tab[9], ajoute1(tab[9]));
    printf("On résout l'équation 4x+7=0 ; x = %.2f\n", equation1erdegre(4,7));
    printf("On trouve le nombre de racines réelles de 2x²+3x-2=0 : %d\n", equation2nddegre(2,3,-2));
    printf("On trouve le nombre de 3 dans le tableau : %d\n", occurencesn(tab, 3, 10));

    // Affichage direct du tableau
    printf("Tableau : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}
