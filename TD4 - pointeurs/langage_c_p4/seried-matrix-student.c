#include <stdlib.h>
#include <stdio.h>

#include "seried-matrix.h"

/**
 * Ne pas toucher au contenu de ce fichier, si ce n'est pour définir les
 * fonctions déclarées.
 * 
 * Pour exécuter les tests unitaires, vous devez lancer la commande de
 * compilation suivante :
 *     gcc seried-matrix-test.c seried-matrix-student.c
 */

struct matrix _mt_init(int nb_rows, int nb_cols) {
    struct matrix r = {0};
    return r;
}

void _mt_release(struct matrix m) {
}

void _mt_fill_random(struct matrix m, int n) {
}

void _mt_fill_diag(struct matrix m, int n) {
}

void _mt_print(struct matrix m) {
}

int _mt_seek_min(struct matrix m, struct coord **idx_min, int *nb_min) {
    return -1;
}

void _mt_apply_coeff(struct matrix m, int a) {
}

int *_mt_matvec(struct matrix m, int *v, int s) {
    return NULL;
}

struct matrix _mt_matmult(struct matrix m, struct matrix n) {
    struct matrix r = {0};
    return r;
}