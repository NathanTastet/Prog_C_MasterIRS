#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct matrice {
    int **valeurs;
    int nb_lignes;
    int nb_colonnes;
};

//ex 12 : créer une fonction pour allouer une matrice

void allouerMatrice(struct matrice *mat,int ligne,int colonne){
    mat->nb_lignes = ligne;
    mat->nb_colonnes = colonne;
    mat->valeurs = malloc(mat->nb_lignes * sizeof(int*));
    for (int i = 0; i < mat->nb_lignes; i++) {
        mat->valeurs[i] = malloc(mat->nb_colonnes * sizeof(int));
    }
}

void libererMatrice(struct matrice *mat){
    for (int i = 0; i < mat->nb_lignes; i++) {
        free(mat->valeurs[i]);
    }
    free(mat->valeurs);
}

//ex 14 : créer une fonction pour créer une matrice diagonale

void initMatriceDiag(struct matrice *mat, int taille,int nbmax){
    allouerMatrice(mat,taille,taille);
    for (int i = 0; i < mat->nb_lignes; i++) {
        for (int j = 0; j < mat->nb_colonnes; j++) {
            if(i==j){
                mat->valeurs[i][j]=rand()%(nbmax+1); 
            }
            else{
                mat->valeurs[i][j] = 0; 
            }
        }
    }

}

void afficherMatrice(struct matrice *mat){
    for (int i = 0; i < mat->nb_lignes; i++) {
        for (int j = 0; j < mat->nb_colonnes; j++) {

            printf("%2d %s",mat->valeurs[i][j],j==(mat->nb_colonnes-1)? "\n": " ");
        }
    }
    printf("\n");
}

/* Ex 13 : Écrire une fonction qui initialise les valeurs de la matrice 
avec des nombres aléatoires contenus entre 0 et n, 
un entier donné en argument de la fonction.
*/

void initMatrice(struct matrice *mat,int nbmax){
    for(int i = 0; i<mat->nb_lignes;i++){
        for(int j = 0; j<mat->nb_colonnes;j++){
            mat->valeurs[i][j]=rand()%(nbmax+1);
        }
    }
}

struct min{
    int mini;
    int* lignesMin;
    int* colonnesMin;
    int size;
};

//exo 15: fonction qui retourne la valeur minimale d'une matrice + les indices des min
void getMinMatrice(struct matrice *mat, struct min *min){
    min->mini = mat->valeurs[0][0];
    for(int i = 0; i<mat->nb_lignes;i++){
        for(int j = 0; j<mat->nb_colonnes;j++){
            if(mat->valeurs[i][j]<=min->mini){
                min->mini = mat->valeurs[i][j];
            }
        }
    }

    int nbDeMin = 0;
    
    for(int i = 0; i<mat->nb_lignes;i++){
        for(int j = 0; j<mat->nb_colonnes;j++){
            if(mat->valeurs[i][j] == min->mini){
                nbDeMin++;
            }
        }
    }

    min->size = nbDeMin;
    min->lignesMin = malloc( nbDeMin * sizeof(int));
    min->colonnesMin = malloc( nbDeMin * sizeof(int));

    int nbActuel = 0;

    for(int i = 0; i<mat->nb_lignes;i++){
        for(int j = 0; j<mat->nb_colonnes;j++){
            if(mat->valeurs[i][j]==min->mini){
                min->lignesMin[nbActuel] = i;
                min->colonnesMin[nbActuel] = j;
                nbActuel++;
            }
        }
    }
}

void printMinMatrice(struct min *m){
    printf("Le minimum de la matrice est %d\nIl est atteint en :\n",m->mini);
    for(int i=0;i< m->size ;i++){
        printf("[%d;%d]\n",m->lignesMin[i],m->colonnesMin[i]);
    }
    printf("\n");
}


void freeMinMatrice(struct min *m){
    free(m->colonnesMin);
    free(m->lignesMin);
}

//16) Écrire une fonction qui applique un coefficient a aux éléments d'une matrice.
void coeffMatrice(struct matrice *m, int a){
    for(int i=0;i< m->nb_lignes ;i++){
        for(int j=0;j < m->nb_colonnes ;j++){
            m->valeurs[i][j]*=a;
        }
    }
}

//17) produit matrice / vecteur (vecteur de meme taille que la matrice)
void prodMatriceVecteur(struct matrice *m, int vecteur[], int resultat[]){
    for(int i = 0; i< m->nb_lignes; i++){
        resultat[i] = 0;
        for(int j = 0; j< m->nb_colonnes;j++){
            resultat[i]+= vecteur[i] * m->valeurs[i][j];
        }
    }
}

void produitMatriciel(struct matrice *A, struct matrice *B,struct matrice *C){
    for (int i = 0; i < A->nb_lignes; i++) {
        for (int j = 0; j < B->nb_colonnes; j++) {
            long long acc = 0;
            for (int k = 0; k < A->nb_colonnes; k++) {
                acc += (long long)A->valeurs[i][k] * B->valeurs[k][j];
            }
            C->valeurs[i][j] = (int)acc;
        }
    }
}

int main(){
    srand(time(NULL));
    struct matrice mat,matdiag;
    allouerMatrice(&mat,5,7);
    initMatrice(&mat,9);
    afficherMatrice(&mat);
    
    /*initMatriceDiag(&matdiag,7,9);
    afficherMatrice(&matdiag);*/
    
    /*
    struct min min;
    getMinMatrice(&mat,&min);
    printMinMatrice(&min);
    freeMinMatrice(&min);

    coeffMatrice(&mat, 2);
    afficherMatrice(&mat);
    */

    
    /* int vecteur[] = {0,1,2,3,4};
    int resultat[5] = {0};
    prodMatriceVecteur(&mat,vecteur,resultat);
    printf("produit matrice vecteur:\n");
    for(int i = 0; i<5;i++){
        printf("{%3d}\n",resultat[i]);
    }*/

    struct matrice mat2,mat3;
    allouerMatrice(&mat2,7,4);
    allouerMatrice(&mat3,5,4);
    initMatrice(&mat2,9);
    afficherMatrice(&mat2);
    produitMatriciel(&mat,&mat2,&mat3);
    afficherMatrice(&mat3);

    libererMatrice(&mat);
    libererMatrice(&matdiag);
    libererMatrice(&mat2);

    return 0;
}