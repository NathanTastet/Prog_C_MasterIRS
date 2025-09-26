#include "tp_checklist.h"
#include "seried-matrix.h"

#define CHECK_RC(_rc) do {                         \
    if (_rc != 0) {                                \
        printf("ERR on l%d: %d\n", __LINE__, _rc); \
        return _rc;                                \
    }                                              \
} while (0)

struct _mfr_t {int r, c, n;};
struct _mfr_t _mfr_1 = {5, 10, 49};

bool check_mfr(void *_arg) {
    struct _mfr_t *arg = (struct _mfr_t *) _arg; 
    struct matrix m = _mt_init(arg->r, arg->c);
    bool r = false;
    int i, j;

    _mt_fill_random(m, arg->n);

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < m.nb_cols; ++j)
            if (m.values[i][j] < 0 || m.values[i][j] > arg->n)
                goto err;

    r = true;
err:
    _mt_release(m);

    return r;
}

bool check_mfd(void *_arg) {
    struct _mfr_t *arg = (struct _mfr_t *) _arg;
    struct matrix m = _mt_init(arg->r, arg->c);
    bool r = false;
    int i, j;

    _mt_fill_diag(m, arg->n);

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < m.nb_cols; ++j)
            if ((i == j && m.values[i][j] != arg->n) ||
                (i != j && m.values[i][j]))
                goto err;

    r = true;
err:
    _mt_release(m);

    return r;
}

struct _msm_t {int r, c, *m, v, s; struct coord *p;};
int __msm_1[] = {3, 2, 1, 6, 5, 6, 0, 2, 3};
struct coord __msm_p1[] = {{2, 0}};
struct _msm_t _msm_1 = {3, 3, __msm_1, 0, 1, __msm_p1};
int __msm_2[] = {5, 5, 5, 5, 5, 5};
struct coord __msm_p2[] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}, {2, 1}};
struct _msm_t _msm_2 = {3, 2, __msm_2, 5, 6, __msm_p2};

bool check_msm(void *_arg) {
    struct _msm_t *arg = (struct _msm_t *) _arg;
    struct matrix m = _mt_init(arg->r, arg->c);
    struct coord *idx_min;
    int nb_min, min;
    bool r = false;
    int i, j;

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < m.nb_cols; ++j)
            m.values[i][j] = arg->m[i * m.nb_cols + j];
    
    min = _mt_seek_min(m, &idx_min, &nb_min);

    if (min != arg->v || nb_min != arg->s)
        goto err;

    for (i = 0; i < nb_min; ++i)
        if (idx_min[i].i != arg->p[i].i || idx_min[i].j != arg->p[i].j)
            goto err;

    r = true;
err:
    free(idx_min);
    _mt_release(m);

    return r;
}

struct _mac_t {int r, c, *m, a, *t;};
int __mac_1[] = {0, 0, 0, 0, 0, 0};
struct _mac_t _mac_1 = {3, 2, __msm_2, 0, __mac_1};
int __mac_2[] = {-9, -6, -3, -18, -15, -18, 0, -6, -9};
struct _mac_t _mac_2 = {3, 3, __msm_1, -3, __mac_2};


bool check_mac(void *_arg) {
    struct _mac_t *arg = (struct _mac_t *) _arg;
    struct matrix m = _mt_init(arg->r, arg->c);
    bool r = false;
    int i, j;

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < m.nb_cols; ++j)
            m.values[i][j] = arg->m[i * m.nb_cols + j];

    _mt_apply_coeff(m, arg->a);

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < m.nb_cols; ++j)
            if (m.values[i][j] != arg->t[i * m.nb_cols + j])
                goto err;
    
    r = true;
err:
    _mt_release(m);

    return r;
}

struct _mmv_t {int r, c, *m, s, *v, *t;};
int __mmv_1[] = {3, 4, 2, 5};
struct _mmv_t _mmv_1 = {3, 3, __msm_1, 4, __mmv_1, NULL};
int __mmv_2[] = {3, 0, -2};
int __mmv_3[] = {7, 6, -6};
struct _mmv_t _mmv_2 = {3, 3, __msm_1, 3, __mmv_2, __mmv_3};

bool check_mmv(void *_arg) {
    struct _mmv_t *arg = (struct _mmv_t *) _arg;
    struct matrix m = _mt_init(arg->r, arg->c);
    bool r = false;
    int *rv;
    int i, j;

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < m.nb_cols; ++j)
            m.values[i][j] = arg->m[i * m.nb_cols + j];

    rv = _mt_matvec(m, arg->v, arg->s);

    if (!arg->t && !rv) {
        r = true;
        goto err;
    }

    if (!arg->t && rv) {
        free(rv);
        goto err;
    }

    if (!rv)
        goto err;

    for (i = 0; i < m.nb_rows; ++i)
        if (arg->t[i] != rv[i]) {
            free(rv);
            goto err;
        }

    free(rv);
    r = true;
err:
    _mt_release(m);

    return r;
}

struct _mmm_t {int r, c, *m, vr, vc, *v, *t;};
int __mmm_1[] = {5, 8, 2, 0, 4, 3};
struct _mmm_t _mmm_1 = {3, 3, __msm_1, 2, 3, __mmm_1, NULL};
int __mmm_2[] = {3, 0, -2, 1, -4, -1};
int __mmm_3[] = {1, 1, -16, -1, -16, -1};
struct _mmm_t _mmm_2 = {3, 3, __msm_1, 3, 2, __mmm_2, __mmm_3};

bool check_mmm(void *_arg) {
    struct _mmm_t *arg = (struct _mmm_t *) _arg;
    struct matrix m = _mt_init(arg->r, arg->c);
    struct matrix n = _mt_init(arg->vr, arg->vc);
    struct matrix p;
    bool r = false;
    int i, j;

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < m.nb_cols; ++j)
            m.values[i][j] = arg->m[i * m.nb_cols + j];
    
    for (i = 0; i < n.nb_rows; ++i)
        for (j = 0; j < n.nb_cols; ++j)
            n.values[i][j] = arg->v[i * n.nb_cols + j];

    p = _mt_matmult(m, n);

    if (!arg->t && !p.values) {
        r = true;
        goto err;
    }

    if (!arg->t && p.values) {
        _mt_release(p);
        goto err;
    }

    if (!p.values)
        goto err;

    for (i = 0; i < m.nb_rows; ++i)
        for (j = 0; j < n.nb_cols; ++j)
            if (arg->t[i * n.nb_cols + j] != p.values[i][j]) {
                _mt_release(p);
                goto err;
            }

    _mt_release(p);
    r = true;
err:
    _mt_release(m);
    _mt_release(n);

    return r;
}

struct tpc_t tests[] = {
    {"mfr try1", check_mfr, &_mfr_1}, {"mfd try1", check_mfd, &_mfr_1},
    {"msm try1", check_msm, &_msm_1}, {"msm try2", check_msm, &_msm_2},
    {"mac try1", check_mac, &_mac_1}, {"mac try2", check_mac, &_mac_2},
    {"mmv try1", check_mmv, &_mmv_1}, {"mmv try2", check_mmv, &_mmv_2},
    {"mmm try1", check_mmm, &_mmm_1}, {"mmm try2", check_mmm, &_mmm_2},
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