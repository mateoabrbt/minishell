##
## EPITECH PROJECT, 2021
## Minishell2
## File description:
## Makefile
##

SRC	=	$(shell find -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS	=	-I./../includes/ -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean
	rm -f ../$(NAME)

re: fclean all

.PHONY:	all $(NAME) clean fclean re