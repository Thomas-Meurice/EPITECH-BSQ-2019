/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int *get_pos_int(unsigned int **tab, unsigned int nb, unsigned int nb1,
    unsigned int count)
{
    unsigned int x;
    unsigned int y;
    unsigned int *pos = malloc(sizeof(int) * 2);

    for (unsigned int i = 0; i < nb; i++)
        for (unsigned int j = 0; j < nb1; j++) {
            x = i;
            y = j;
            if (tab[i][j] == count) {
                pos[0] = x + 1;
                pos[1] = y;
                return (pos);
            }
        }
    pos[0] = 0;
    pos[1] = 0;
    return (pos);
}