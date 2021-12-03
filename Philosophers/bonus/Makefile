NAME	=	philo_bonus
SRCS	=	main.c from_libft.c start_life.c utilus.c
HEADER	=	philo_bonus.h
OBJ		=	$(SRCS:%.c=%.o)
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all