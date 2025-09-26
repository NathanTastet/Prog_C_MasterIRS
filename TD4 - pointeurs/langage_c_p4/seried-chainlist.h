#include <stdbool.h>

struct chain_elt;
struct chain_elt *_ce_get_next(struct chain_elt *);
int _ce_get_value(struct chain_elt *);
struct chain_elt *_ce_init();
void _ce_release(struct chain_elt *);
struct chain_elt *_ce_add(struct chain_elt *, int);
bool _ce_check(struct chain_elt *, int);
struct chain_elt *_ce_remove(struct chain_elt *, int);
struct chain_elt *_ce_sort(struct chain_elt *);