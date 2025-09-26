#include "tp_checklist.h"
#include "serie-macro.h"

bool exc03(void *);
struct __ex_a exc03_1 = {.i._2cor = {{.0, .0}, {.4, 3.}}, .o._p = {.4, 3.}};
struct __ex_a exc03_2 = {.i._2cor = {{-5.4, 3.8}, {12.5, -1.1}}, .o._p = {7.1, 2.7}};

bool exc05(void *);
struct __ex_a exc05_1 = {.i._cir = {1., {.0, .0}}, .o._2flt = {6.28, 3.14}};
struct __ex_a exc05_2 = {.i._cir = {5., {-3., 5.7}}, .o._2flt = {31.4, 78.5}};

bool exc06(void *);
struct __ex_a exc06_1 = {.i._rec = {{.0, .0}, {4., 2.}}, .o._2flt = {12., 8.}};
struct __ex_a exc06_2 = {.i._rec = {{.2, -6.3}, {9.4, 2.}}, .o._2flt = {35., 76.36}};

bool exc07(void *);
struct __ex_a exc07_1 = {.i._cirWcor = {{1., {.0, .0}}, {.2, 3.}}, .o._cir = {1., {.2, 3.}}};
struct __ex_a exc07_2 = {.i._cirWcor = {{5.5, {4., .7}}, {.2, 3.}}, .o._cir = {5.5, {4.2, 3.7}}};

bool exc08(void *);
struct __ex_a exc08_1 = {.i._recWcor = {{{.0, .0}, {4., 2.}}, {.2, 3.}}, .o._rec = {{.2, 3.}, {4.2, 5.}}};
struct __ex_a exc08_2 = {.i._recWcor = {{{.2, -6.3}, {9.4, 2.}}, {.2, 3.}}, .o._rec = {{.4, -3.3}, {9.6, 5.}}};

bool exc09(void *);
struct __ex_a exc09_1 = {.i._cirWcor = {{1., {.0, .0}}, {.2, 3.}}, .o._b = false};
struct __ex_a exc09_2 = {.i._cirWcor = {{5.5, {4., .7}}, {1., 1.}}, .o._b = true};

bool exc10(void *);
struct __ex_a exc10_1 = {.i._recWcor = {{{.0, .0}, {4., 2.}}, {.2, 1.7}}, .o._b = true};
struct __ex_a exc10_2 = {.i._recWcor = {{{.2, -6.3}, {9.4, 2.}}, {.2, 3.}}, .o._b = false};

bool exc13(void *);
struct __ex_a exc13_1 = {.i._tim = {1, 2, 3}, .o._m = 3723};
struct __ex_a exc13_2 = {.i._tim = {3, 2, 1}, .o._m = 10921};

bool exc14(void *);
struct __ex_a exc14_1 = {.i._m = 3723, .o._tim = {1, 2, 3}};
struct __ex_a exc14_2 = {.i._m = 10921, .o._tim = {3, 2, 1}};

bool exc15(void *);
struct __ex_a exc15_1 = {.i._2tim = {{1, 2, 3}, {3, 2, 1}}, .o._tim = {4, 4, 4}};
struct __ex_a exc15_2 = {.i._2tim = {{17, 53, 25}, {5, 20, 38}}, .o._tim = {23, 14, 3}};

bool exc16(void *);
struct __ex_a exc16_1 = {.i._2tim = {{19, 25, 12}, {12, 32, 5}}, .o._tim = {6, 53, 7}};
struct __ex_a exc16_2 = {.i._2tim = {{28, 12, 35}, {30, 0, 0}}, .o._tim = {0, 0, 0}};

struct tpc_t tests[] = {
    {"exc03 try1", exc03, &exc03_1}, {"exc03 try2", exc03, &exc03_2},
    {"exc05 try1", exc05, &exc05_1}, {"exc05 try2", exc05, &exc05_2},
    {"exc06 try1", exc06, &exc06_1}, {"exc06 try2", exc06, &exc06_2},
    {"exc07 try1", exc07, &exc07_1}, {"exc07 try2", exc07, &exc07_2},
    {"exc08 try1", exc08, &exc08_1}, {"exc08 try2", exc08, &exc08_2},
    {"exc09 try1", exc09, &exc09_1}, {"exc09 try2", exc09, &exc09_2},
    {"exc10 try1", exc10, &exc10_1}, {"exc10 try2", exc10, &exc10_2},
    {"exc13 try1", exc13, &exc13_1}, {"exc13 try2", exc13, &exc13_2},
    {"exc14 try1", exc14, &exc14_1}, {"exc14 try2", exc14, &exc14_2},
    {"exc15 try1", exc15, &exc15_1}, {"exc15 try2", exc15, &exc15_2},
    {"exc16 try1", exc16, &exc16_1}, {"exc16 try2", exc16, &exc16_2},
};

float point_x, point_y, vecteur_x, vecteur_y;
float rayon, centre_x, centre_y;
float point1_x, point1_y, point2_x, point2_y;
float perimetre, aire;
bool test;
int temps_heure, temps_minute, temps_seconde;
int t2_heure, t2_minute, t2_seconde;
int seconde;