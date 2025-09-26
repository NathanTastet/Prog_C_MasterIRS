struct matrix {
    int **values;
    int nb_rows;
    int nb_cols;
};
struct coord {int i, j;};
struct matrix _mt_init(int, int);
void _mt_release(struct matrix);
void _mt_fill_random(struct matrix, int);
void _mt_fill_diag(struct matrix, int);
void _mt_print(struct matrix);
int _mt_seek_min(struct matrix, struct coord**, int *);
void _mt_apply_coeff(struct matrix, int);
int *_mt_matvec(struct matrix, int *, int);
struct matrix _mt_matmult(struct matrix, struct matrix);