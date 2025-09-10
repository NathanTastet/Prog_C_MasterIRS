#include <stdio.h>

int quotient_reste(int denominateur,int numerateur){
    int quotient = 0, reste;
    while(denominateur >= numerateur){
        denominateur -= numerateur;
        quotient ++;
    }
    reste = denominateur;
    
    printf("Le quotient est %d et le reste est %d",quotient,reste);
    
    return 0;
    
    
}

int main(){
    int denominateur, numerateur;
    printf("Donnez le dénominateur de la division DD/NN.. ");
    scanf(" %d",&denominateur);
    printf("Donnez le numérateur de la division %d/NN.. ",denominateur);
    scanf(" %d",&numerateur);
    quotient_reste(denominateur,numerateur);
    
}