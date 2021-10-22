NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			utils/put_str.c	utils/put_char.c\
			utils/put_int.c	utils/put_p.c\
			utils/put_uns.c	utils/put_x.c


HEADER	=	ft_printf.h
OBJ		=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all