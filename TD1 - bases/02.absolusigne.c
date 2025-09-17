#include <stdio.h>

int signe(int a){
    if(a==0){
        return 0;
    }else{
        if(a>0){
            return 1;
        }
        else{
            return -1;
        }
    }
}

int main(){
    int a;
    printf("De quel nombre souhaitez vous avoir la valeur absolue?\n");
    scanf("%d",&a);
    int absolu = (a>0) ? a: -a;
    printf("La valeur absolue de %d est %d et son signe est %d", a, absolu,signe(a));
}