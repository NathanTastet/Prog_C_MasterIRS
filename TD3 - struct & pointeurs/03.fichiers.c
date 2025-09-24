// Écrire une fonction qui écrit une chaîne de caractères dans un fichier.

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f = fopen("monfichier.txt", "w"); // ouvrir en écriture
    if (f == NULL) { // toujours vérifier !
        printf("Erreur : impossible d'ouvrir le fichier\n");
        return 1;
    }

    fprintf(f, "Bonchour hein !\n"); 
    fclose(f);

    // Écrire une fonction qui lit une chaîne de caractères à partir d'un fichier.
    FILE *f2 = fopen("fichier2.txt","r");
    if (f2 == NULL) { // toujours vérifier !
        printf("Erreur : impossible d'ouvrir le fichier\n");
        return 1;
    }

    char s[100], s2[100];
    fscanf(f2, "%99s%99s", s, s2);
    printf("%s : %s\n",s,s2);
    fclose(f2);
}
