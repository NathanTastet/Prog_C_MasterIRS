#include "tp_checklist.h"
#include "seried-chainlist.h"

#define CHECK_RC(_rc) do {                         \
    if (_rc != 0) {                                \
        printf("ERR on l%d: %d\n", __LINE__, _rc); \
        return _rc;                                \
    }                                              \
} while (0)

bool check_ci(void *arg) {
    struct chain_elt *c;
    (void) arg;

    c = _ce_init();

    if (c != NULL)
        return false;
    return true;
}

struct _ca_t {int *t, s;};
int __ca_1[] = {2};
struct _ca_t _ca_1 = {__ca_1, 1};
int __ca_2[] = {3, 47, 8, 3, 0, 3};
struct _ca_t _ca_2 = {__ca_2, 6};

bool check_ca(void *_arg) {
    struct chain_elt *c = _ce_init();
    struct chain_elt *t;
    struct _ca_t *arg = (struct _ca_t*) _arg;
    bool r = false;
    int i;

    for (i = 0; i < arg->s; ++i)
        c = _ce_add(c, arg->t[i]);

    for (i = arg->s - 1, t = c; i >= 0 && t; --i, t = _ce_get_next(t)) {
        if (_ce_get_value(t) != arg->t[i]) 
            goto err;
    }

    if (i != -1 || t)
        goto err;

    r = true;

err:
    _ce_release(c);

    return r;
}

struct _cc_t {int *t, s, v; bool c;};
struct _cc_t _cc_1 = {__ca_2, 6, 0, true};
struct _cc_t _cc_2 = {__ca_2, 6, -1, false};
struct _cc_t _cc_3 = {__ca_2, 6, 3, true};
struct _cc_t _cc_4 = {__ca_2, 6, 47, true};

bool check_cc(void *_arg) {
    struct chain_elt *c = _ce_init();
    struct _cc_t *arg = (struct _cc_t*) _arg;
    bool r = false;
    int i;

    for (i = 0; i < arg->s; ++i)
        c = _ce_add(c, arg->t[i]);

    r = _ce_check(c, arg->v) == arg->c;

    _ce_release(c);
    
    return r;
}

struct _cr_t {int *t, s, v, *rt, rs;};
struct _cr_t _cr_1 = {__ca_1, 1, 2, NULL, 0};
struct _cr_t _cr_2 = {__ca_1, 1, 3, __ca_1, 1};
int __cr_1[] = {0, 3, 8, 47, 3};
int __cr_2[] = {3, 0, 3, 8, 3};
struct _cr_t _cr_3 = {__ca_2, 6, 3, __cr_1, 5};
struct _cr_t _cr_4 = {__ca_2, 6, 47, __cr_2, 5};

bool check_cr(void *_arg) {
    struct chain_elt *c = _ce_init();
    struct chain_elt *t;
    struct _cr_t *arg = (struct _cr_t*) _arg;
    bool r = false;
    int i;

    for (i = 0; i < arg->s; ++i)
        c = _ce_add(c, arg->t[i]);

    c = _ce_remove(c, arg->v);

    for (i = 0, t = c; i < arg->rs && t; ++i, t = _ce_get_next(t)) {
        if (_ce_get_value(t) != arg->rt[i]) 
            goto err;
    }

    if (i != arg->rs || t)
        goto err;

    r = true;

err:
    _ce_release(c);

    return r;
}

struct _cs_t {int *t, s, *rt, rs;};
struct _cs_t _cs_1 = {__ca_1, 1, __ca_1, 1};
int __cs_1[] = {0, 3, 3, 3, 8, 47};
struct _cs_t _cs_2 = {__ca_2, 6, __cs_1, 6};

bool check_cs(void *_arg) {
    struct chain_elt *c = _ce_init();
    struct chain_elt *t;
    struct _cr_t *arg = (struct _cr_t*) _arg;
    bool r = false;
    int i;

    for (i = 0; i < arg->s; ++i)
        c = _ce_add(c, arg->t[i]);

    c = _ce_sort(c);

    for (i = 0, t = c; i < arg->rs && t; ++i, t = _ce_get_next(t)) {
        if (_ce_get_value(t) != arg->rt[i]) 
            goto err;
    }

    if (i != arg->rs || t)
        goto err;

    r = true;

err:
    _ce_release(c);

    return r;
}

struct tpc_t tests[] = {
    {"ci try1", check_ci, NULL},
    {"ca try1", check_ca, &_ca_1}, {"ca try2", check_ca, &_ca_2},
    {"cc try1", check_cc, &_cc_1}, {"cc try2", check_cc, &_cc_2},
    {"cc try3", check_cc, &_cc_3}, {"cc try4", check_cc, &_cc_4},
    {"cr try1", check_cr, &_cr_1}, {"cr try2", check_cr, &_cr_2},
    {"cr try3", check_cr, &_cr_3}, {"cr try4", check_cr, &_cr_4},
    {"cs try1", check_cs, &_cs_1}, {"cs try2", check_cs, &_cs_2},
};

int main(void) {
    int rc;

    rc = tpc_init(tests, sizeof(tests)/sizeof(*tests));
    CHECK_RC(rc);

    rc = tpc_run_all();
    CHECK_RC(rc);

    tpc_summary();
    tpc_fini();

    return 0;
}