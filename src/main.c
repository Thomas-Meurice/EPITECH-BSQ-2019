/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** {description}
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int count_tab(char **tab, char *str)
{
    int i = my_getnbr(str);
    int j = 0;
    int nb = my_strlen(tab[1]);
    int a = 0;

    for (; tab[a] != NULL; a++);
    a += -2;
    while (j < a) {
        j++;
        if (my_strlen(tab[j]) != nb)
            return (1);
    }
    if (i != j)
        return (1);
    return (0);
}

void display(char **tab)
{
    int x = 0;
    int y = 0;
    char *str = NULL;

    for (; tab[x] != NULL; x++);
    for (; tab[1][y] != '\0'; y++);
    tab[x - 1] = NULL;
    x += -2;
    str = malloc(sizeof(char) * ((x * y) + x + 1));
    x = 0;
    for (int a = 1; tab[a] != NULL; a++) {
        for (int b = 0; tab[a][b] != '\0'; b++) {
            str[x] = tab[a][b];
            x++;
        }
        str[x] = '\n';
        x++;
    }
    str[x] = '\0';
    write(1, str, my_strlen(str));
}

int main(int ac, char **av)
{
    char *str = NULL;
    char **tab = NULL;
    unsigned int **tab_i = NULL;

    if (ac != 2)
        return (84);
    if (av[1] == NULL)
        return (84);
    str = my_getfiles(av[1]);
    if (str == NULL || str[0] == '\0' || str[0] == '\n')
        return (84);
    tab = my_str_to_word_array(str, '\n');
    if (count_tab(tab, str) == 1)
        return (84);
    tab_i = char_to_int_tab(tab);
    tab = algo(tab_i, tab);
    display(tab);
    if (tab_i)
        return (0);
    free(str);
    return (0);
}
