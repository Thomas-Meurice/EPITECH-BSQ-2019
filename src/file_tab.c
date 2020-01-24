/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char **file_tab(char **tab, unsigned int *pos, unsigned int count)
{
    int i = pos[0] - count + 1;
    int j = pos[1] - count + 1;

    for (unsigned int nb = 0; nb < count; nb++) {
        for (unsigned int nb2 = 0; nb2 < count; nb2++) {
            tab[i][j] = 'x';
            j++;
        }
        j = pos[1] - count + 1;
        i++;
    }
    return (tab);
}