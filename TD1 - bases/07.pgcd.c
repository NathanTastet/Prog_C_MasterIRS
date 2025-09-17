// vérification entier premier
// Principe : Un nombre premier est un nombre dont ses seuls diviseurs sont 1 et lui-même.

#include <stdio.h>

// plus grand commun diviseur de m/n
int pgcd(int m, int n){
    int choix = (m>n) ? m : n ;
    while(1){
        if( (n%choix == 0) && (m%choix ==0) ){
            return choix;
        }
        choix--;
    }
}

int main(){
    int m,n; 
    printf("Choisissez deux nombres pour faire le pgcd \n");
    scanf(" %d", &m);
    scanf(" %d", &n);
    printf("\nPGCD : %d",pgcd(m,n));
}



