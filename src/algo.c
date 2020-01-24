/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int my_tab_height(char **tab)
{
    unsigned int nb = 2;

    while (tab[nb] != NULL)
        nb++;
    nb += -2;
    return (nb);
}

unsigned int my_tab_width(char **tab)
{
    unsigned int i = 0;

    while (tab[1][i] != '\0')
        i++;
    return (i);
}

int value_for_int(char c)
{
    if (c == 'o')
        return (0);
    if (c == '.')
        return (1);
    return (0);
}

unsigned int **char_to_int_tab(char **tab)
{
    unsigned int nb = my_tab_height(tab);
    unsigned int nb1 = my_tab_width(tab);
    unsigned int **tab_i = malloc(sizeof(int *) * nb);

    if (tab_i == NULL)
        return (NULL);
    for (unsigned int i = 0; i < nb; i++) {
        tab_i[i] = malloc(sizeof(int) * nb1);
        if (tab_i[i] == NULL)
            return (NULL);
    }
    for (unsigned int i = 0; i < nb; i++)
        for (unsigned int j = 0; j < nb1; j++)
            tab_i[i][j] = value_for_int(tab[i + 1][j]);
    return (tab_i);
}