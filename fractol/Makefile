NAME	=	fraktol
SRCS	=   src/main.c			src/hook.c		src/color.c\
			src/mandelbrot.c	src/utilus.c	src/julia.c\
			src/burning_ship.c

HEADER	=	includes/fractol.h
OBJ		=	$(SRCS:%.c=%.o)
CC		=	gcc
LIB		=	-L./includes -lft -lmlx -framework OpenGL -framework AppKit
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(LIB) $(CFLAGS) $(OBJ)  -o $(NAME)

checker	:	$(NAME2)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all