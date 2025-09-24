#include <stdio.h>
#include <ctype.h>   // pour isupper, islower, toupper, tolower

#define TAILLE 100

int main() {
    char str[TAILLE];
    printf("Donne nous une chaine de caractères pour laquelle tu auras des informations\n");
    fgets(str, TAILLE, stdin); // lit toute la ligne, espaces inclus

    // calcul du nombre de voyelles et consonnes
    int nbvoy = 0, nbcons = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        switch (tolower(str[i])) {   // uniformiser pour le test minuscule / majuscule
            case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
                nbvoy++;
                break;
            default:
                if (isalpha(str[i])) {
                    nbcons++;
                }
        }
    }

    printf("Nombre voyelle : %d & Nombre consonne : %d\n", nbvoy, nbcons);

    // inversion de la casse
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);   // min -> maj
        } else if (isupper(str[i])) {
            str[i] = tolower(str[i]);   // maj -> min
        }
    }
    printf("Inversion de la casse...\n");
    printf("%s\n\n", str);

    return 0;
}
