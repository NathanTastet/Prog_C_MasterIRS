// vérification entier premier
// Principe : Un nombre premier est un nombre dont ses seuls diviseurs sont 1 et lui-même.

#include <stdio.h>

int nbpremier(int nombre){
    for(int i = 2; i<nombre;i++){
        if( nombre%i == 0){
            return -1;
        }
    }
    return 1;
}

int main(){
    int nombre; 
    printf("Choisissez un nombre, pour lequel vous voulez savoir s'il est premier\n");
    scanf(" %d", &nombre);
    int premier = nbpremier(nombre);
    if(premier == 1){
        printf("\nCe nombre est premier");
    }
    else{
        printf("\nCe nombre n'est pas premier");
    }
}



