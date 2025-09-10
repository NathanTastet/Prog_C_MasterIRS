
#include <stdio.h>

int peri_carre(int cote){
    return cote * 4 ;
}


int main()
{
    int a = 12;
    float d = 3.14;
    char c = 'i';
    char s[] = "Hello world!";
    
    // pour un carré
    int cote, perimetre, surface;
    printf("Entrez le coté du carré : ");
    scanf("%d",&cote);
    perimetre = cote *4;
    surface = cote * cote; 
    printf("Carré : coté '%d' ; périmètre '%d' ; surface '%d'\n",cote,perimetre,surface);
    
    // pour un rectangle
    int cote1, cote2;
    printf("Entrez la longueur : ");
    scanf("%d",&cote1);
    printf("Entrez la largeur : ");
    scanf("%d",&cote2);
    perimetre = cote1 * 2 + cote2 * 2; 
    surface = cote1 * cote2; 
    printf("Rectangle : coté 1 '%d'; coté 2 '%d'; périmètre '%d'; surface '%d'\n",cote1,cote2,perimetre,surface);
    
    // pour un cercle
    int rayon = 12 ;
    float peri_cercle, surf_cercle;
    peri_cercle = 2 * d * rayon;
    surf_cercle = d * rayon * rayon;
    printf("Cercle : rayon '%d'; périmètre '%.2f'; surface '%.2f'\n",rayon,peri_cercle,surf_cercle);

    
    char c_A = 'A', c_B = 'D';
    c_A += 2;
    c_B -= 2;
    printf("c_A : '%c' ; c_B : '%c'\n",c_A ,c_B);
}