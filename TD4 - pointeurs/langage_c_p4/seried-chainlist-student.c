#include <stdlib.h>
#include <stdio.h>

#include "seried-chainlist.h"

/**
 * Ne pas toucher au contenu de ce fichier, si ce n'est pour définir les
 * fonctions déclarées suivantes :
 * - _ce_init()
 * - _ce_release()
 * - _ce_add()
 * - _ce_print()
 * - _ce_check()
 * - _ce_remove()
 * - _ce_sort()
 * 
 * Pour exécuter les tests unitaires, vous devez lancer la commande de
 * compilation suivante :
 *     gcc seried-chainlist-test.c seried-chainlist-student.c
 */
struct chain_elt {
    int value;
    struct chain_elt *next;
};

struct chain_elt *_ce_get_next(struct chain_elt *c) {return c->next;}
int _ce_get_value(struct chain_elt *c) {return c->value;}

/** Remplir le fichier à partir de ce point */

struct chain_elt *_ce_init() {
    return NULL;
}

void _ce_release(struct chain_elt *list) {
}

struct chain_elt *_ce_add(struct chain_elt *list, int val) {
    return NULL;
}

void _ce_print(struct chain_elt *list) {
}

bool _ce_check(struct chain_elt *list, int val) {
    return false;
}

struct chain_elt *_ce_remove(struct chain_elt *list, int val) {
    return NULL;
}

struct chain_elt *_ce_sort(struct chain_elt *list) {
    return NULL;
}