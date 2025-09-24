
#include <stdio.h>
#include <stdlib.h>

// 1. Définir une structure de données représentant les coordonnées réeles 2D d'un point.
struct point {
    float x;
    float y;
};

// 4. Définir deux structures de données représentant un cercle et un rectangle. 
// Le cercle contient un point et un rayon, réel.
// Le rectangle contient deux points, qui sont les deux points de l'une de ses diagonales.

struct cercle {
    struct point centre;
    float rayon;
};

struct rectangle {
    struct point point1;
    struct point point2;
};


// 2. Écrire une fonction qui affiche les coordonnées d'un point 
// sous la forme : (x, y).
void affpoint(struct point point){
    printf("(%.2f, %.2f)\n",point.x,point.y);
}

struct point translation(struct point point, struct point vecTrans){
    struct point resultat = {point.x + vecTrans.x , point.y + vecTrans.y };
    return resultat;
}

// 5. Écrire une fonction qui calcule le périmètre et l'aire d'un cercle.
void perimetre_aireCercle(struct cercle cercle1){
    float perimetre = 2 * 3.14 * cercle1.rayon ;
    float aire = 3.14 * cercle1.rayon * cercle1.rayon;

    printf("Le périmètre est de %.2f et l'aire est de %.2f\n",perimetre,aire);
}

// 6. Écrire une fonction qui calcule le périmètre et l'aire d'un rectangle.
void perimetre_aireRect(struct rectangle r1){
    float coteX = abs(r1.point1.x - r1.point2.x);
    float coteY = abs(r1.point1.y - r1.point2.y);
    float perimetre = 2*coteX + 2*coteY;
    float aire = coteX * coteY;

    printf("Le périmètre est de %.2f et l'aire est de %.2f\n",perimetre,aire);
}

// 9. Écrire une fonction qui indique si un point est présent dans un cercle.
int pointEstDansCercle(struct point p, struct cercle c){
    // calculer la distance entre le point et le centre
    float distX = abs(p.x - c.centre.x);
    float distY = abs(p.y - c.centre.y);
    float dist2 = distX * distX + distY * distY;
    // il faut que la distance au carré soit plus petite que le rayon au carré pour etre dans le cercle
    if(dist2< (c.rayon * c.rayon)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    struct point point1 = {0,0};
    struct point vecTr = {1,1};
    affpoint(point1);
    affpoint(translation(point1,vecTr));
    
    struct cercle cercle1 = {point1,10};
    perimetre_aireCercle(cercle1);

    struct point point2 = {-2, 6};
    affpoint(point1);
    affpoint(point2);

    struct rectangle rect1 = {point1, point2};
    perimetre_aireRect(rect1);

    printf("Le point 2 est dans le cercle : %d\n", pointEstDansCercle(point2,cercle1));
    struct point point3 = {9, 9};
    printf("Le point 3 est dans le cercle : %d\n", pointEstDansCercle(point3,cercle1));

    return 0;
}