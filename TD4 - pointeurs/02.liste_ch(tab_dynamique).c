#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Exo 5 : Écrire une structure de données représentant un élément de liste chaînée. 
Une liste chaînée est une structure utilisée pour stocker des informations, 
généralement de même type, de manière dynamique : 
à chaque fois qu'une nouvelle donnée est ajoutée, 
un élément de liste est alloué et ajouté à la chaîne. 
On considère que la liste va contenir des entiers.*/

struct chainedList{
    int *elems;
    int size;
};

// exo 6 :
void initChainedList(struct chainedList *list){
    list->size = 0;
    list->elems = malloc(0);
}

void freeChainedList(struct chainedList *list){
    free(list->elems);
}

// exo 7 :
void addChainedList(struct chainedList *list, int n){
    list->size++;
    realloc(list->elems, list->size * sizeof(int));
    *(list->elems + list->size - 1) = n;
}

// exo 8 :
void printChainedList(struct chainedList *list){
    for(int i = 0; i<list->size;i++){
        printf("list[%d]=%d\n",i,*(list->elems + i));
    }

}

// exo 9 :

int isPresentCL(struct chainedList *list, int n){
    for(int i = 0; i<list->size;i++){
        if(*(list->elems+i) == n){
            return 1;
        }
    }
    return 0;
}



int removeFromChainedList(struct chainedList *list, int n){
    int onremplace = 0;
    for(int i = 0; i<list->size;i++){
        if(*(list->elems+i) == n){
            onremplace = 1;
        }
        if(onremplace){
            if((i+1)< list->size ){
                *(list->elems+i) = *(list->elems+i+1);
            }
        }
    }

    if(onremplace){
        realloc(list->elems, (list->size - 1) * sizeof(int));
        list->size--;
    }
}

// exo 11 : Écrire une fonction qui trie les éléments d'une liste chaînée.
int triCL(struct chainedList *list){
    int temp, indMini;
    for(int i = 0; i<list->size;i++){
        indMini = i;
        for(int j = i;j<list->size;j++){
            if(*(list->elems+j)<=*(list->elems + indMini)){
                indMini = j;
            }
        }
        temp = *(list->elems+i);
        *(list->elems+i) = *(list->elems+indMini);
        *(list->elems+indMini) = temp;
    }
}

int main(){
    struct chainedList li;
    initChainedList(&li);
    for(int i = 10;i>0;i--){
        addChainedList(&li,i);
    }
    printChainedList(&li);
    int recherche = 2;
    printf("%d est présent dans la liste : %d",recherche,isPresentCL(&li,recherche));
    removeFromChainedList(&li,recherche);
    printChainedList(&li);
    printf("On trie la liste :\n");
    triCL(&li);
    printChainedList(&li);

}


// struct noeud * chaine ) = malloc(sizeof(struct noeud))