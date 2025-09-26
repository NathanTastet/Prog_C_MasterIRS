#include <stdlib.h>
#include <stdio.h>

// 11. Définir une structure de donnée qui permet de représenter un temps 
// en heures, minutes et secondes.

struct temps{
    int heures; 
    int minutes; 
    int secondes;
};

// 12. Écrire une fonction qui convertit un temps h/m/s en secondes.
void afficheTemps(struct temps t){
    printf("%02dh : %02dm : %02ds\n",t.heures,t.minutes,t.secondes);
}

// 14. Écrire une fonction qui convertit un temps secondes en h/m/s.

struct temps secVersTemps(int secondes){
    int heures = 0, minutes = 0;

    while(secondes>=3600){
        secondes-=3600;
        heures++;
    }
    while(secondes>=60){
        secondes-=60;
        minutes++;
    }

    struct temps retour = {heures,minutes,secondes};
    return(retour);
}

// 15. Écrire une fonction qui additionne deux temps.
struct temps add2temps(struct temps t1, struct temps t2){

    struct temps retour = {t1.heures+t2.heures,t1.minutes+t2.minutes,t1.secondes+t2.secondes};
    while(retour.secondes>=60){
        retour.secondes-=60;
        retour.minutes++;
    }
    while(retour.minutes>=60){
        retour.minutes-=60;
        retour.heures++;
    }
    return retour;
}

// Écrire une fonction qui lit un temps à partir d'un fichier.
struct temps lireTempsFichier(FILE *f){
    struct temps retour;
    fscanf(f,"%d:%d:%d",&retour.heures,&retour.minutes,&retour.secondes);
    return retour;
}

int main(){
    int secondes = 82842;
    struct temps t1 = secVersTemps(secondes);
    afficheTemps(t1);
    struct temps t2 = {2,59,53};
    struct temps t3 = add2temps(t1,t2);
    afficheTemps(t3);

    FILE *f = fopen("heure.txt","r");
    struct temps t4 = lireTempsFichier(f);
    fclose(f);
    afficheTemps(t4);
}
