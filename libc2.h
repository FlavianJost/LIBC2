#ifndef LIBC2_H
#define LIBC2_H

#include <stddef.h>

void *malloc2(size_t size);
void  free2(void *ptr);
void *realloc2(void *ptr, size_t size);
void *calloc2(size_t n, size_t size);
int   libc2_init(size_t total_cells, size_t max_cell_size);
void  libc2_destroy(void);

#endif