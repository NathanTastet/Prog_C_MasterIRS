#ifndef H_SERIE_MACRO
# define H_SERIE_MACRO

#include <stdbool.h>
#include <stdlib.h>

#define CHECK_RC(_rc) do {                         \
    if (_rc != 0) {                                \
        printf("ERR on l%d: %d\n", __LINE__, _rc); \
        return _rc;                                \
    }                                              \
} while (0)

typedef struct {void *t; int m;} __tab_t;
typedef struct {float x, y;} __cor_t;
typedef struct {float r; __cor_t c;} __cir_t;
typedef struct {__cor_t p, q;} __rec_t;
typedef struct {int h, m, s;} __tim_t;

struct __ex_a {
    union {
        int _m;
        struct {float a, b;} _2flt;
        struct {float a, b, c;} _3flt;
        __tab_t _t;
        struct {__tab_t t; int n;} _tabWi;
        struct {__tab_t t; char c;} _tabWc;
        struct {__tab_t t, u;} _2tab;
        struct {__cor_t p, q;} _2cor;
        __cir_t _cir;
        struct {__cir_t c; __cor_t p;} _cirWcor;
        __rec_t _rec;
        struct {__rec_t r; __cor_t p;} _recWcor;
        __tim_t _tim;
        struct {__tim_t t, u;} _2tim;
    } i;
    union {
        int _m;
        bool _b;
        struct {int m, n;} _2int;
        float _a;
        struct {float a, b;} _2flt;
        __tab_t _t;
        __cor_t _p;
        __cir_t _cir;
        __rec_t _rec;
        __tim_t _tim;
    } o;
};

#define __CAST_ARGC(_x, _a) struct __ex_a *_x = (struct __ex_a *) _a
#define __I(_f) _->i._f
#define __O(_f) _->o._f

#define INIT_INT(__, _m_) do { \
    __CAST_ARGC(_, __);        \
    _m_ = __I(_m);             \
} while (0)

#define INIT_2COR(__, _x1_, _y1_, _x2_, _y2_) do { \
    __CAST_ARGC(_, __);                            \
    _x1_ = __I(_2cor.p.x);                         \
    _y1_ = __I(_2cor.p.y);                         \
    _x2_ = __I(_2cor.q.x);                         \
    _y2_ = __I(_2cor.q.y);                         \
} while (0)

#define INIT_CIR(__, _r_, _x_, _y_) do { \
    __CAST_ARGC(_, __);                  \
    _x_ = __I(_cir.c.x);                 \
    _y_ = __I(_cir.c.y);                 \
    _r_ = __I(_cir.r);                   \
} while (0)

#define INIT_CIRWCOR(__, _r_, _x1_, _y1_, _x2_, _y2_) do { \
    __CAST_ARGC(_, __);                                    \
    _x1_ = __I(_cirWcor.c.c.x);                            \
    _y1_ = __I(_cirWcor.c.c.y);                            \
    _r_ = __I(_cirWcor.c.r);                               \
    _x2_ = __I(_cirWcor.p.x);                              \
    _y2_ = __I(_cirWcor.p.y);                              \
} while (0)

#define INIT_REC(__, _x1_, _y1_, _x2_, _y2_) do { \
    __CAST_ARGC(_, __);                           \
    _x1_ = __I(_rec.p.x);                         \
    _y1_ = __I(_rec.p.y);                         \
    _x2_ = __I(_rec.q.x);                         \
    _y2_ = __I(_rec.q.y);                         \
} while (0)

#define INIT_RECWCOR(__, _x1_, _y1_, _x2_, _y2_, _x3_, _y3_) do { \
    __CAST_ARGC(_, __);                                           \
    _x1_ = __I(_recWcor.r.p.x);                                   \
    _y1_ = __I(_recWcor.r.p.y);                                   \
    _x2_ = __I(_recWcor.r.q.x);                                   \
    _y2_ = __I(_recWcor.r.q.y);                                   \
    _x3_ = __I(_recWcor.p.x);                                     \
    _y3_ = __I(_recWcor.p.y);                                     \
} while (0)

#define INIT_REC(__, _x1_, _y1_, _x2_, _y2_) do { \
    __CAST_ARGC(_, __);                           \
    _x1_ = __I(_rec.p.x);                         \
    _y1_ = __I(_rec.p.y);                         \
    _x2_ = __I(_rec.q.x);                         \
    _y2_ = __I(_rec.q.y);                         \
} while (0)

#define INIT_TIM(__, _h_, _m_, _s_) do { \
    __CAST_ARGC(_, __);                  \
    _h_ = __I(_tim.h);                   \
    _m_ = __I(_tim.m);                   \
    _s_ = __I(_tim.s);                   \
} while (0)

#define INIT_2TIM(__, _h1_, _m1_, _s1_, _h2_, _m2_, _s2_) do { \
    __CAST_ARGC(_, __);                                        \
    _h1_ = __I(_2tim.t.h);                                     \
    _m1_ = __I(_2tim.t.m);                                     \
    _s1_ = __I(_2tim.t.s);                                     \
    _h2_ = __I(_2tim.u.h);                                     \
    _m2_ = __I(_2tim.u.m);                                     \
    _s2_ = __I(_2tim.u.s);                                     \
} while (0)

#define CHCK_INT(__, _m_) do { \
    __CAST_ARGC(_, __);        \
    return _m_ == __O(_m);     \
} while (0)

#define CHCK_BOL(__, _b_) do { \
    __CAST_ARGC(_, __);        \
    return _b_ == __O(_b);     \
} while (0)

#define CHCK_2FLT(__, _a_, _b_) do {        \
    __CAST_ARGC(_, __);                     \
    return (                                \
        fabs(_a_ - __O(_2flt.a)) < 1e-6f && \
        fabs(_b_ - __O(_2flt.b)) < 1e-6f    \
    );                                      \
} while (0)

#define CHCK_COR(__, _x_, _y_) do {      \
    __CAST_ARGC(_, __);                  \
    return (                             \
        fabs(_x_ - __O(_p.x)) < 1e-6f && \
        fabs(_y_ - __O(_p.y)) < 1e-6f    \
    );                                   \
} while (0)

#define CHCK_CIR(__, _r_, _x_, _y_) do {     \
    __CAST_ARGC(_, __);                      \
    return (                                 \
        fabs(_r_ - __O(_cir.r)) < 1e-6f &&   \
        fabs(_x_ - __O(_cir.c.x)) < 1e-6f && \
        fabs(_y_ - __O(_cir.c.y)) < 1e-6f    \
    );                                       \
} while (0)

#define CHCK_REC(__, _x1_, _y1_, _x2_, _y2_) do { \
    __CAST_ARGC(_, __);                           \
    return (                                      \
        fabs(_x1_ - __O(_rec.p.x)) < 1e-6f &&     \
        fabs(_y1_ - __O(_rec.p.y)) < 1e-6f &&     \
        fabs(_x2_ - __O(_rec.q.x)) < 1e-6f &&     \
        fabs(_y2_ - __O(_rec.q.y)) < 1e-6f        \
    );                                            \
} while (0)

#define CHCK_TIM(__, _h_, _m_, _s_) do {                                   \
    __CAST_ARGC(_, __);                                                    \
    return _h_ == __O(_tim.h) && _m_ == __O(_tim.m) && _s_ == __O(_tim.s); \
} while (0)

#endif