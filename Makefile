##
## EPITECH PROJECT, 2021
## Minishell2
## File description:
## Makefile
##

SRC		=	src/main.c				\
			src/minishell.c			\
			src/minishell_init.c	\
			src/display_minishell.c	\
			src/handle_arg.c		\
			src/test_path.c			\
			src/cd.c				\
			src/env.c				\
			src/setenv.c			\
			src/unsetenv.c			\
			src/exit.c				\
			src/exec_program.c		\
			src/fill_struct.c		\
			src/modify_pwd_oldpwd.c	\
			src/clean_env.c


NAME    =	mysh

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-Wall -Wextra -g

CPPFLAGS	=	-I./includes/

LDFLAGS		= 	-L./lib -lmy

CRITERION	=	-lcriterion

all: $(NAME)

libmy:
	make -C lib/

$(NAME): libmy $(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)

clean:
	make -C lib/ clean
	rm -f $(OBJ)
	rm -f *#
	rm -f *~

fclean:
	make -C lib/ fclean
	rm -f $(NAME) $(OBJ)
	clear

re: fclean all

tests_run: libmy $(OBJ)
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)

.PHONY: re fclean clean all