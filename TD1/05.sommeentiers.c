#include <stdio.h>

int sommefor(int n){
    int somme = 0;
    for(int i = 0; i<= n;i++){
        somme += i;
    }
    return somme;
}

int sommewhile(int n){
    int somme = 0;
    while(n>0){
        somme += n;
        n--;
    }
    return somme;
}

int sommedowhile(int n){
    int somme = 0;
    do{
        somme += n;
        n--;
    }
    while(n>0);
    return somme;
}

int main(){
    int n;
    printf("Somme de 1 à n inclus - Choisissez n : ");
    scanf(" %d",&n);
    printf("%d\n",sommefor(n));
    printf("%d\n",sommewhile(n));
    printf("%d",sommedowhile(n));
}