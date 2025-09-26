#include <math.h>
#include <stdbool.h>

#include "tp_checklist.h"
#include "serie-macro.h"
#include "seriec-test.h"

#define PI 3.14

/**
 * Pour l'ensemble des exercices `excXY()`, ne touchez pas aux macros
 * i.e. les instructions en majuscule `INIT_XYZ()`, `CHCK_XYZ()` et
 * `FREE_PTR()`. Attention toutefois à changer correctement les noms des
 * variables présentes dans les macros, afin qu'elles correspondent aux
 * noms que vous allez utiliser.
 * 
 * Vous devez définir l'ensemble des variables avant la macro `INIT_XYZ()`,
 * et écrire le code correspondant à l'exercice avant `CHCK_XYZ()`.
 */

bool exc03(void *arg) {

    INIT_2COR(arg, point_x, point_y, vecteur_x, vecteur_y);


    CHCK_COR(arg, point_x, point_y);
    return false;
}

bool exc05(void *arg) {

    INIT_CIR(arg, rayon, centre_x, centre_y);


    CHCK_2FLT(arg, perimetre, aire);
    return false;
}

bool exc06(void *arg) {

    INIT_REC(arg, point1_x, point1_y, point2_x, point2_y);


    CHCK_2FLT(arg, perimetre, aire);
    return false;
}

bool exc07(void *arg) {

    INIT_CIRWCOR(arg, rayon, centre_x, centre_y, vecteur_x, vecteur_y);


    CHCK_CIR(arg, rayon, centre_x, centre_y);
    return false;
}

bool exc08(void *arg) {

    INIT_RECWCOR(arg, point1_x, point1_y, point2_x, point2_y, vecteur_x, vecteur_y);


    CHCK_REC(arg, point1_x, point1_y, point2_x, point2_y);
    return false;
}

bool exc09(void *arg) {

    INIT_CIRWCOR(arg, rayon, centre_x, centre_y, point_x, point_y);


    CHCK_BOL(arg, test);
    return false;
}

bool exc10(void *arg) {

    INIT_RECWCOR(arg, point1_x, point1_y, point2_x, point2_y, point_x, point_y);
    

    CHCK_BOL(arg, test);
    return false;
}

bool exc13(void *arg) {

    INIT_TIM(arg, temps_heure, temps_minute, temps_seconde);


    CHCK_INT(arg, seconde);
    return false;
}

bool exc14(void *arg) {

    INIT_INT(arg, seconde);


    CHCK_TIM(arg, temps_heure, temps_minute, temps_seconde);
    return false;
}

bool exc15(void *arg) {

    INIT_2TIM(arg, temps_heure, temps_minute, temps_seconde, t2_heure, t2_minute, t2_seconde);


    CHCK_TIM(arg, temps_heure, temps_minute, temps_seconde);
    return false;
}

bool exc16(void *arg) {

    INIT_2TIM(arg, temps_heure, temps_minute, temps_seconde, t2_heure, t2_minute, t2_seconde);


    CHCK_TIM(arg, temps_heure, temps_minute, temps_seconde);
    return false;
}

/**
 * Ne pas toucher au code suivant, exception faite de l'argument de l'appel
 * `tpc_run("exb01")`, où vous devez le remplacer par l'exercice que vous
 * souhaitez tester.
 */

int main(void) {
    int rc;

    rc = tpc_init(tests, sizeof(tests)/sizeof(*tests));
    CHECK_RC(rc);

    rc = tpc_run("exc03");
    CHECK_RC(rc);

    tpc_summary();
    tpc_fini();

    return 0;
}