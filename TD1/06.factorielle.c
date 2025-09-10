#include <stdio.h>

int factorielle(int n){
    long int fact = 1;
    if(n==0){
        return 1;
    }
    else{
        if(n<0){
            return -1;
        }
        else{
            for(int i=1;i<=n;i++){
                fact = fact * i; 
            }
        }
    return fact;
    }
}

int main(){
    int n;
    printf("Factorielle de n- Choisissez n : ");
    scanf(" %d",&n);
    printf("%d\n",factorielle(n));
}