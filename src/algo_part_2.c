/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int verif_long(unsigned int **tab, unsigned int i, unsigned int j)
{
    unsigned int nb = tab[i - 1][j];

    if (nb > tab[i - 1][j - 1])
        nb = tab[i - 1][j - 1];
    if (nb > tab[i][j - 1])
        nb = tab[i][j - 1];
    return (nb);
}

int verif(unsigned int **tab, unsigned int i, unsigned int j)
{
    if (tab[i - 1][j] == '0' || tab[i - 1][j - 1] == '0' ||
        tab[i][j - 1] == '0')
        return (1);
    return (0);
}

unsigned int change_int_array(unsigned int count, unsigned int **tab,
    unsigned int i, unsigned int j)
{
    if (count == 0)
        return (0);
    if (verif(tab, i, j) == 1)
        return (1);
    count = verif_long(tab, i, j);
    count++;
    return (count);
}

unsigned int verif_pos(unsigned int nb, unsigned int count)
{
    if (nb > count)
        return (nb);
    return (count);
}

char **algo(unsigned int **tab_i, char **tab)
{
    unsigned int nb = my_tab_height(tab);
    unsigned int nb1 = my_tab_width(tab);
    unsigned int count = 1;
    unsigned int *pos;

    for (unsigned int i = 1; i < nb; i++)
        for (unsigned int j = 1; j < nb1; j++) {
            tab_i[i][j] = change_int_array(tab_i[i][j], tab_i, i, j);
            count = verif_pos(tab_i[i][j], count);
        }
    pos = get_pos_int(tab_i, nb, nb1, count);
    tab = file_tab(tab, pos, count);
    return (tab);
}