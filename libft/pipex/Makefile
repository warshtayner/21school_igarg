NAME	=	pipex
SRCS	=	main.c	utilus.c
HEADER	=	pipex.h
OBJ		=	$(SRCS:%.c=%.o)
CC		=	gcc
LIB		=	-L./libft/ -lft
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	@make -C ./libft/
	$(CC) $(LIB) $(CFLAGS) $(OBJ)  -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean	:	clean
	@make fclean -C ./libft
	@$(RM) $(NAME)

re		:	fclean all
