##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for secured
##

CFLAGS	=	-W -Wall -Wextra

SRC =	src/my_numb.c \
		src/my_table.c \
		src/my_write.c \
		src/my_str.c \
		src/my_insert.c \
		src/my_search.c \
		src/my_hash.c

NAME	=	libhashtable.a

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
