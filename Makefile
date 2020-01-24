##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Thomas Meurice <thomas.meurice@epitech.eu>
##


SRC	=	src/main.c					\
		src/my_getfiles.c			\
		src/algo.c					\
		src/algo_part_2.c			\
		src/get_pos.c				\
		src/file_tab.c				\

NAME	=	bsq

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-Llib/my -lmy

CFLAGS	=	-W -Wall -Werror -Wextra -I include/

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)
		make clean
clean:
		rm -f $(OBJ)
		rm -rf *~ src/*~ vg*

fclean: clean
		make fclean -C lib/my
		rm -f $(NAME)

debug:		CFLAGS += -ggdb3

debug:		re

re:		fclean all

.PHONY:		all debug clean fclean
