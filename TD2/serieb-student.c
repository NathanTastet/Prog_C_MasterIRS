#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "tp_checklist.h"
#include "serieb-macro.h"

/**
 * Pour l'ensemble des exercices `exbXY()`, ne touchez pas aux macros
 * i.e. les instructions en majuscule `INIT_XYZ()`, `CHCK_XYZ()` et
 * `FREE_PTR()`),.
 * 
 * Vous devez définir l'ensemble des variables avant la macro `INIT_XYZ()`,
 * et écrire le code correspondant à l'exercice avant `CHECK_XYZ()`.
 */

bool exb01(void *arg) {
    
    INIT_EXB_TAB(arg, tab, taille);

    
    FREE_PTR(tab);
    CHCK_EXB_2INT(arg, nb_pos, nb_neg);
    return false;
}

bool exb02(void *arg) {

    INIT_EXB_TAB(arg, tab, taille);


    FREE_PTR(tab);
    CHCK_EXB_INT(arg, somme);
    return false;
}

bool exb03(void *arg) {

    INIT_EXB_TAB(arg, tab, taille);

    
    FREE_PTR(tab);
    CHCK_EXB_INT(arg, moyenne);
    return false;
}

bool exb04(void *arg) {

    INIT_EXB_TAB(arg, tab, taille);


    FREE_PTR(tab);
    CHCK_EXB_2INT(arg, min, max);
    return false;
}

bool exb05(void *arg) {

    INIT_EXB_TABWI(arg, tab, taille, n);


    CHCK_EXB_TAB(arg, tab, true);
    return false;
}

bool exb06(void *arg) {

    INIT_EXB_TAB(arg, tab, taille);


    CHCK_EXB_TAB(arg, tab, true);
    return false;
}


bool exb07(void *arg) {

    INIT_EXB_TAB(arg, tab, taille);


    CHCK_EXB_TAB(arg, tab, true);
    return false;
}

bool exb08(void *arg) {

    INIT_EXB_TAB(arg, tab, taille);


    FREE_PTR(tab);
    CHCK_EXB_INT(arg, mediane);
    return false;
}

bool exb09(void *arg) {

    INIT_EXB_TAB(arg, tab, taille);


    FREE_PTR(tab);
    CHCK_EXB_TAB(arg, denombrement, false);
    return false;
}

bool exb10(void *arg) {

    INIT_EXB_2TAB(arg, tab_a, tab_b, taille);


    FREE_PTR(tab_a);
    FREE_PTR(tab_b);
    CHCK_EXB_INT(arg, produit_scalaire);
    return false;
}


bool exb11(void *arg) {

    INIT_EXB_TAB(arg, str, taille);


    FREE_PTR(str);
    CHCK_EXB_2INT(arg, nb_voyelles, nb_consonnes);
    return false;
}

bool exb12(void *arg) {

    INIT_EXB_TAB(arg, str, taille);


    CHCK_EXB_TAB(arg, str, true);
    return false;
}

bool exb13(void *arg) {

    INIT_EXB_TAB(arg, str, taille);


    CHCK_EXB_TAB(arg, str, true);
    return false;
}


bool exb15(void *arg) {

    INIT_EXB_INT(arg, a);


    CHCK_EXB_INT(arg, a);
    return false;
}


bool exb16(void *arg) {

    INIT_EXB_INT(arg, a);


    CHCK_EXB_INT(arg, a);
    return false;
}


bool exb17(void *arg) {

    INIT_EXB_2FLT(arg, a, b);


    CHCK_EXB_FLT(arg, x);
    return false;
}


bool exb18(void *arg) {

    INIT_EXB_3FLT(arg, a, b, c);


    CHCK_EXB_INT(arg, nb_racines);
    return false;
}


bool exb19(void *arg) {

    INIT_EXB_TABWC(arg, str, taille, d);


    FREE_PTR(str);
    CHCK_EXB_INT(arg, idx);
    return false;
}


bool exb20(void *arg) {

    INIT_EXB_TABWI(arg, tab, taille, n);


    FREE_PTR(tab);
    CHCK_EXB_INT(arg, nb);
    return false;
}

#include "serieb-test.h"

/**
 * Ne pas toucher au code suivant, exception faite de l'argument de l'appel
 * `tpc_run("exb01")`, où vous devez le remplacer par l'exercice que vous
 * souhaitez tester.
 */

int main(void) {
    int rc;

    rc = tpc_init(tests, sizeof(tests)/sizeof(*tests));
    CHECK_RC(rc);

    rc = tpc_run("exb01");

    CHECK_RC(rc);

    tpc_summary();

    tpc_fini();

    return 0;
}
