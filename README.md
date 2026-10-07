# LIBC2

LIBC2 est un allocateur mémoire expérimental pour Linux x86_64 distribué sous forme de bibliothèque partagée.

Le projet est principalement destiné à l'expérimentation, aux tests de performance et à l'étude des stratégies d'allocation mémoire.

## Fonctions disponibles

- `malloc2`, `free2`, `realloc2` et `calloc2` pour gérer les allocations
- `libc2_init` pour initialiser la bibliothèque
- `libc2_destroy` pour terminer son utilisation

## Exemple en C

```c
#include "libc2.h"

int main(void)
{
    if (libc2_init(262144, 4096) != 0)
        return 1;

    void *ptr = malloc2(1024);
    if (ptr != NULL) {
        free2(ptr);
    }

    libc2_destroy();
    return 0;
}
```

Compilez le programme avec la bibliothèque :

```sh
gcc -O2 -Wall -Wextra -o exemple exemple.c -L. -lc2 -Wl,-rpath,'$ORIGIN'
```

## Chargement avec `LD_PRELOAD`

```sh
LD_PRELOAD="$PWD/libc2.so" ./mon_application
```

## Quelques résultats

Exemple de résultats obtenus sur un Dell PowerEdge R710.

| Test | glibc | LIBC2 |
|-------|-------:|-------:|
| ALLOC 64B | 72 Mops/s | 89 Mops/s |
| ALLOC+FREE 64B | 68 Mops/s | 132 Mops/s |
| REALLOC 64↔128 | 20 Mops/s | 191 Mops/s |
| ECS / 3D | 20 Mops/s | 53 Mops/s |
| MULTITHREAD 32T | 533 Mops/s | 1211 Mops/s |

Les performances varient selon la machine et la charge de travail.

## Statut et compatibilité

LIBC2 est un projet expérimental : son API et son comportement peuvent évoluer. La compatibilité visée est Linux x86_64.
