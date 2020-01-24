/*
** EPITECH PROJECT, 2024
** my_get_file_content.c
** File description:
** Created by Thomas Meurice
*/

#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *my_getfiles(char const *filepath)
{
    int size = 0;
    int fd = open(filepath, O_RDONLY);
    int readbytes = 0;
    char *res = NULL;
    struct stat structst;

    if (fd == -1)
        return (NULL);
    stat(filepath, &structst);
    size = structst.st_size;
    res = malloc(sizeof(char) * (size + 1));
    readbytes = read(fd, res, size);
    res[readbytes] = '\0';
    return (res);
}