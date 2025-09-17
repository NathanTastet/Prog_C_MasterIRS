#ifndef H_SERIEB_MACRO
# define H_SERIEB_MACRO

#include <stdlib.h>

#define CHECK_RC(_rc) do {                         \
    if (_rc != 0) {                                \
        printf("ERR on l%d: %d\n", __LINE__, _rc); \
        return _rc;                                \
    }                                              \
} while (0)

typedef struct {void *t; int m;} tab_t;

struct exb_a {
    union {
        int _m;
        struct {float a, b;} _2flt;
        struct {float a, b, c;} _3flt;
        tab_t _t;
        struct {tab_t t; int n;} _tabWi;
        struct {tab_t t; char c;} _tabWc;
        struct {tab_t t, u;} _2tab;
    } i;
    union {
        int _m;
        struct {int m, n;} _2int;
        float _a;
        tab_t _t;
    } o;
};

#define CAST_ARGC(_x, _a) struct exb_a *_x = (struct exb_a *) _a;
#define INIT_SIZE(_n, _t) size_t _sz = _n * sizeof(*_t);

int b01t1[] = {0, 1, 2};
struct exb_a exb01_1 = {.i._t = {b01t1, 3}, .o._2int = {3, 0}};
int b01t2[] = {-2, 2, 5, 9, -3};
struct exb_a exb01_2 = {.i._t = {b01t2, 5}, .o._2int = {3, 2}};

struct exb_a exb02_1 = {.i._t = {b01t1, 3}, .o._m = 3};
int b02t2[] = {3, 12, 6, 15, 9};
struct exb_a exb02_2 = {.i._t = {b02t2, 5}, .o._m = 45};
int b02t3[] = {4, 8, 11};
struct exb_a exb02_3 = {.i._t = {b02t3, 3}, .o._m = 23};
int b02t4[] = {-2, 0, 2};
struct exb_a exb02_4 = {.i._t = {b02t4, 3}, .o._m = 0};

struct exb_a exb03_1 = {.i._t = {b01t1, 3}, .o._m = 1};
struct exb_a exb03_2 = {.i._t = {b02t2, 5}, .o._m = 9};
struct exb_a exb03_3 = {.i._t = {b02t3, 3}, .o._m = 7};
struct exb_a exb03_4 = {.i._t = {b02t4, 3}, .o._m = 0};

int b04t1[] = {42};
struct exb_a exb04_1 = {.i._t = {b04t1, 1}, .o._2int = {42, 42}};
struct exb_a exb04_2 = {.i._t = {b01t1, 3}, .o._2int = {0, 2}};
struct exb_a exb04_3 = {.i._t = {b01t2, 5}, .o._2int = {-3, 9}};
struct exb_a exb04_4 = {.i._t = {b02t2, 5}, .o._2int = {3, 15}};

int b05u1[] = {0, 2, 4};
struct exb_a exb05_1 = {.i._tabWi = {{b01t1, 3}, 2}, .o._t = {b05u1, 3}};
int b05u2[] = {-10, 10, 25, 45, -15};
struct exb_a exb05_2 = {.i._tabWi = {{b01t2, 5}, 5}, .o._t = {b05u2, 5}};
int b05u3[] = {-12, -24, -33};
struct exb_a exb05_3 = {.i._tabWi = {{b02t3, 3}, -3}, .o._t = {b05u3, 3}};
int b05u4[] = {0};
struct exb_a exb05_4 = {.i._tabWi = {{b04t1, 1}, 0}, .o._t = {b05u4, 1}};

struct exb_a exb06_1 = {.i._t = {b04t1, 1}, .o._t = {b04t1, 1}};
int b06u2[] = {9, 3, 12, 6, 15};
struct exb_a exb06_2 = {.i._t = {b02t2, 5}, .o._t = {b06u2, 5}};

struct exb_a exb07_1 = {.i._t = {b04t1, 1}, .o._t = {b04t1, 1}};
int b07u2[] = {3, 6, 9, 12, 15};
struct exb_a exb07_2 = {.i._t = {b02t2, 5}, .o._t = {b07u2, 5}};
int b07u3[] = {-3, -2, 2, 5, 9};
struct exb_a exb07_3 = {.i._t = {b01t2, 5}, .o._t = {b07u3, 5}};
int b07t4[] = {5, 4, 4, 2};
int b07u4[] = {2, 4, 4, 5};
struct exb_a exb07_4 = {.i._t = {b07t4, 4}, .o._t = {b07u4, 4}};

struct exb_a exb08_1 = {.i._t = {b01t2, 5}, .o._m = 2};
int b08t2[] = {8, 14, 0, 3, 13, 20};
struct exb_a exb08_2 = {.i._t = {b08t2, 6}, .o._m = 10};

int b09u1[10] = {1, 1, 1, 0};
struct exb_a exb09_1 = {.i._t = {b01t1, 3}, .o._t = {b09u1, 10}};
int b09t2[] = {0, 0, 1, 1, 2, 2, 3, 4, 5, 6, 9, 3, 1, 0, 0};
int b09u2[10] = {4, 3, 2, 2, 1, 1, 1, 0, 0, 1};
struct exb_a exb09_2 = {.i._t = {b09t2, 15}, .o._t = {b09u2, 10}};

struct exb_a exb10_1 = {.i._2tab = {{b04t1, 1}, {b04t1, 1}}, .o._m = 1764};
struct exb_a exb10_2 = {.i._2tab = {{b01t2, 5}, {b02t2, 5}}, .o._m = 156};

char b11t1[] = "abcdefghijklmnopqrstuvwxyz";
struct exb_a exb11_1 = {.i._t = {b11t1, 26}, .o._2int = {6, 20}};
char b11t2[] = "aBCDeFg00HIJkLm  NoPqRs__TUVwXyZ";
struct exb_a exb11_2 = {.i._t = {b11t2, 32}, .o._2int = {6, 20}};

char b12u1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct exb_a exb12_1 = {.i._t = {b11t1, 26}, .o._t = {b12u1, 26}};
char b12u2[] = "AbcdEfG00hijKlM  nOpQrS__tuvWxYz";
struct exb_a exb12_2 = {.i._t = {b11t2, 32}, .o._t = {b12u2, 32}};

char b13t1[] = " ";
struct exb_a exb13_1 = {.i._t = {b13t1, 1}, .o._t = {b13t1, 1}};
char b13t2[] = "test";
char b13u2[] = "estt";
struct exb_a exb13_2 = {.i._t = {b13t2, 4}, .o._t = {b13u2, 4}};
char b13t3[] = "baba au rhum";
char b13u3[] = "aabb au hmru";
struct exb_a exb13_3 = {.i._t = {b13t3, 12}, .o._t = {b13u3, 12}};
char b13t4[] = "lorem_ipsum_dolor0sit_amet";
char b13u4[] = "elmor_impsu_dloor0ist_aemt";
struct exb_a exb13_4 = {.i._t = {b13t4, 26}, .o._t = {b13u4, 26}};

#define I(_f) _->i._f
#define O(_f) _->o._f

struct exb_a exb15_1 = {.i._m = 0, .o._m = 1};
struct exb_a exb15_2 = {.i._m = 42, .o._m = 43};
struct exb_a exb15_3 = {.i._m = -13, .o._m = -12};

struct exb_a exb16_1 = {.i._m = 0, .o._m = 0};
struct exb_a exb16_2 = {.i._m = 13, .o._m = 1};
struct exb_a exb16_3 = {.i._m = 42, .o._m = 0};

struct exb_a exb17_1 = {.i._2flt = {1., 1.}, .o._a = -1.};
struct exb_a exb17_2 = {.i._2flt = {5., -2.5}, .o._a = .5};
struct exb_a exb17_3 = {.i._2flt = {4., 0.}, .o._a = .0};
struct exb_a exb17_4 = {.i._2flt = {0., 10.}, .o._a = .0};

struct exb_a exb18_1 = {.i._3flt = {1., -3., 2.}, .o._m = 2};
struct exb_a exb18_2 = {.i._3flt = {4., -12., 9.}, .o._m = 1};
struct exb_a exb18_3 = {.i._3flt = {2., 2., 3.}, .o._m = 0};

struct exb_a exb19_1 = {.i._tabWc = {b13t2, 4, 'e'}, .o._m = 1};
struct exb_a exb19_2 = {.i._tabWc = {b13t3, 12, 'h'}, .o._m = 9};
struct exb_a exb19_3 = {.i._tabWc = {b13t4, 26, '_'}, .o._m = 5};
struct exb_a exb19_4 = {.i._tabWc = {b13t1, 1, 'a'}, .o._m = -1};

struct exb_a exb20_1 = {.i._tabWi = {b09t2, 15, 1}, .o._m = 3};
struct exb_a exb20_2 = {.i._tabWi = {b09t2, 15, 9}, .o._m = 1};
struct exb_a exb20_3 = {.i._tabWi = {b09t2, 15, 0}, .o._m = 4};
struct exb_a exb20_4 = {.i._tabWi = {b09t2, 15, 7}, .o._m = 0};

#define INIT_EXB_INT(__, m) do { \
    CAST_ARGC(_, __);            \
    m = I(_m);                   \
} while (0)

#define INIT_EXB_2FLT(__, a, b) do { \
    CAST_ARGC(_, __);                \
    a = I(_2flt.a);                  \
    b = I(_2flt.b);                  \
} while (0)

#define INIT_EXB_3FLT(__, a, b, c) do { \
    CAST_ARGC(_, __);                   \
    a = I(_3flt.a);                     \
    b = I(_3flt.b);                     \
    c = I(_3flt.c);                     \
} while (0)

#define _INIT_TAB(_, __t, __m) do { \
    __m = _.m;                      \
    INIT_SIZE(__m, __t);            \
    __t = malloc(_sz);              \
    memcpy(__t, _.t, _sz);          \
} while (0);

#define INIT_EXB_TAB(__, __t, __m) do { \
    CAST_ARGC(_, __);                   \
    _INIT_TAB(I(_t), __t, __m);         \
} while (0)

#define INIT_EXB_TABWI(__, __t, __m, __n) do { \
    CAST_ARGC(_, __);                          \
    _INIT_TAB(I(_tabWi.t), __t, __m);          \
    __n = I(_tabWi.n);                         \
} while (0)

#define INIT_EXB_TABWC(__, __t, __m, __c) do { \
    CAST_ARGC(_, __);                          \
    _INIT_TAB(I(_tabWc.t), __t, __m);          \
    __c = I(_tabWc.c);                         \
} while (0)

#define INIT_EXB_2TAB(__, __t, __u, __m) do { \
    CAST_ARGC(_, __);                         \
    _INIT_TAB(I(_2tab.t), __t, __m);          \
    _INIT_TAB(I(_2tab.u), __u, __m);          \
} while (0)

#define CHCK_EXB_INT(__, __m) do { \
    CAST_ARGC(_, __);              \
    return __m == O(_m);           \
} while (0)

#define CHCK_EXB_2INT(__, __m, __n) do {           \
    CAST_ARGC(_, __);                              \
    return __m == O(_2int.m) && __n == O(_2int.n); \
} while (0)

#define CHCK_EXB_FLT(__, __a) do {    \
    CAST_ARGC(_, __);                 \
    return fabs(__a - O(_a)) < 1e-6f; \
} while (0)

#define CHCK_EXB_TAB(__, __t, __nf) do { \
    CAST_ARGC(_, __);                    \
    INIT_SIZE(O(_t.m), __t);             \
    int _rc = memcmp(__t, O(_t.t), _sz); \
    if (__nf) free(__t);                 \
    return _rc == 0;                     \
} while (0)

#define FREE_PTR(__p) free(__p);

int taille, *tab, nb_pos, nb_neg, somme, moyenne, min, max;
int mediane, *denombrement, produit_scalaire, *tab_a, *tab_b;
int nb_voyelles, nb_consonnes, nb_racines, idx, n, nb;
float a, b, c, x;
char *str, d;

#endif