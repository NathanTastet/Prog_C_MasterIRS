/* tp_checklist.h
 *
 * Portable library that offers simple calls to manage unitary tests
 * 
 * This library offers one to interact with a set of unitary tests, defining
 * them, running them and print a report to the user.
 */

#ifndef H_TPCHECKLIST
# define H_TPCHECKLIST

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* strdup() */

/* ********************** */
/* STRUCTURES DEFINITIONS */
/* ********************** */

/* Public definitions */

/**
 * Basic enumeration to indicate the result of a unitary test.
 */
enum tpc_test_result {
    TPC_TR_UNCHECKED,      /* Test is not checked yet */
    TPC_TR_FAILURE,        /* Test failed */
    TPC_TR_SKIPPED,        /* Test is skipped, will not fail testsuite */
    TPC_TR_SUCCESS,        /* Test succeed */
    TPC_TR_TOTAL           /* Undefined value, use for loops over enum */
};

/**
 * Structure which defines a unitary test.
 */
struct tpc_t {
    char* name;                 /* Test name */
    bool (*check)(void *arg);   /* Test function */
    void *check_arg;            /* Argument of test function */
};

/* **************** */
/* STATIC VARIABLES */
/* **************** */

/* Boolean used to verify the library was correctly initialized */
static bool _tpc_is_init = false;

/* String representation of the enum `tpc_test_result` */
static const char *_TPC_TR_LABELS[] = {
    "unchecked",
    "failure",
    "skipped",
    "succeed",
    "undefined"
};

/* Library storage of the unitary tests, composed of the public definition
 * of the test and the result (if available) of the test run
 */
static struct _tpc_internal {
    struct tpc_t tpc;
    enum tpc_test_result result;
} *_tpc_tests = NULL;

/* Number of tests in `_tpc_tests` */
static unsigned _tpc_tests_count;


/* ****** */
/* MACROS */
/* ****** */

/* Verify the library was correctly initialized, exit the function if not */
#define CHECK_INIT do { \
    if (!_tpc_is_init)  \
        return -1;      \
} while (0)

/* ******************** */
/* FUNCTION DEFINITIONS */
/* ******************** */

/**
 * Library finalizer
 * 
 * Consists in releasing library memory, and setting `_tpc_is_init` to false.
 */
void
tpc_fini(
    void
) {
    int i;

    for (i = 0; i < _tpc_tests_count; ++i)
        free(_tpc_tests[i].tpc.name);
    free(_tpc_tests);
    _tpc_tests_count = 0;

    _tpc_is_init = false;
}


/**
 * Library initializer
 * 
 * Initialize the internal variables of the library, setting `_tpc_is_init`
 * to true.
 * 
 * \param[in] items     Unitary tests to handle with the library
 * \param[in] count     Number of unitary tests to handle
 * 
 * \return              0 on success, -1 on error (allocation failed)
 */
int
tpc_init(
    struct tpc_t *items,
    int count
) {
    int i;

    _tpc_tests = calloc(count, sizeof(*_tpc_tests));
    if (_tpc_tests == NULL)
        return -1;

    _tpc_tests_count = count;
    for (i = 0; i < count; ++i) {
        _tpc_tests[i].tpc.name = strdup(items[i].name);
        if (_tpc_tests[i].tpc.name == NULL)
            goto err;
        _tpc_tests[i].tpc.check = items[i].check;
        _tpc_tests[i].tpc.check_arg = items[i].check_arg;
        _tpc_tests[i].result = TPC_TR_UNCHECKED;
    }

    _tpc_is_init = true;

    return 0;

err:
    tpc_fini();

    return -1;
}

/**
 * List all tests, with their last run results
 * 
 * \return  0 on success, -1 on error (library not initialized)
 */
int
tpc_list_all(
    void
) {
    int i;

    CHECK_INIT;
    for (i = 0; i < _tpc_tests_count; ++i) {
        printf(
            "Test '%s' -> %s\n",
            _tpc_tests[i].tpc.name,
            _TPC_TR_LABELS[_tpc_tests[i].result]);
    }

    return 0;
}

/**
 * Summarize the last test run
 * 
 * Count the results of the different tests, and print those counts.
 * 
 * \return  0 on success, -1 on error (library not initialized)
 */
int
tpc_summary(
    void
) {
    int count[TPC_TR_TOTAL] = { 0 };
    int i;

    CHECK_INIT;
    for (i = 0; i < _tpc_tests_count; ++i)
        count[_tpc_tests[i].result]++;

    for (i = 0; i < TPC_TR_TOTAL; ++i)
        printf("  %7s: %d\n", _TPC_TR_LABELS[i], count[i]);

    return 0;
}

int
tpc_run(
    const char *prefix
) {
    int i;

    CHECK_INIT;
    for (i = 0; i < _tpc_tests_count; ++i) {
        struct _tpc_internal *t;
        bool res;

        t = &_tpc_tests[i];
        if (strncmp(prefix, t->tpc.name, strlen(prefix))) {
            t->result = TPC_TR_SKIPPED;
            continue;
        }

        res = t->tpc.check(t->tpc.check_arg);

        t->result = res ? TPC_TR_SUCCESS : TPC_TR_FAILURE;
        if (!res)
            printf(
                "Check '%s' > done(%s)\n",
                t->tpc.name,
                _TPC_TR_LABELS[t->result]
            );
    }

    return 0;
}

/**
 * Run the test suite
 * 
 * All tests given to the initializer function will be run, and the results
 * are stored in an internal structure.
 * 
 * \return  0 on success, -1 on error (library not initialized)
 */
int
tpc_run_all(
    void
) {
    int i;

    CHECK_INIT;
    for (i = 0; i < _tpc_tests_count; ++i) {
        struct _tpc_internal *t;
        bool res;
        
        t = &_tpc_tests[i];
        // printf("Check '%s' > running\n", t->tpc.name);
        res = t->tpc.check(t->tpc.check_arg);

        t->result = res ? TPC_TR_SUCCESS : TPC_TR_FAILURE;
        if (!res)
            printf(
                "Check '%s' > done(%s)\n", 
                t->tpc.name,
                _TPC_TR_LABELS[t->result]
            );
    }

    return 0;
}

#endif
