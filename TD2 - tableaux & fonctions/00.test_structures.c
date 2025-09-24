#include <stdio.h>

int main(){

    struct Personne {
        char nom[50];
        int age;
        float taille;
    };

    struct Personne pers1;

    printf("Comment t'appelles tu?\n");
    scanf(" %s",&pers1.nom);

    printf("Tu as quel age mon poulain\n");
    scanf(" %d",&pers1.age);

    printf("Tu mesures combien ;)\n");
    scanf(" %f",&pers1.taille);


    printf("Bonjour %s tu as %d ans et tu mesures %f",pers1.nom,pers1.age,pers1.taille);

}