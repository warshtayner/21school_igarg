NAME	=	push_swap
NAME2	=	checker

SRCS	=	utilus/full_int.c	utilus/error_leaks.c	utilus/list.c\
			utilus/list_2.c	sorting/main_sorting.c	sorting/pa_pb.c\
			sorting/ra_rb_rr.c	sorting/rra_rrb_rrr.c	sorting/sa_sb_ss.c\
			utilus/input.c	sorting/hard_sorting.c	utilus/list_3.c\
			sorting/sorting_utilus.c
SRCS3	=	push_swap.c
SRCS2	=	checker_utilus/pa_pb_ch.c	checker_utilus/ra_rb_rr_ch.c\
			checker_utilus/rra_rrb_rrr_ch.c	checker_utilus/sa_sb_ss_ch.c\
			checker_my.c

HEADER	=	push_swap.h
OBJ		=	$(SRCS:%.c=%.o)
OBJ2	=	$(SRCS2:%.c=%.o)
OBJ3	=	$(SRCS3:%.c=%.o)
CC		=	gcc
LIB		=	-L./utilus -lft
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re checker

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(OBJ3) $(HEADER)
	$(CC) $(LIB) $(CFLAGS) $(OBJ) $(OBJ3) -o $(NAME)

checker	:	$(NAME2)

$(NAME2)	:	$(OBJ)	$(OBJ2) $(HEADER)
	$(CC) $(LIB) $(CFLAGS) $(OBJ) $(OBJ2) -o $(NAME2)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ) $(OBJ2) $(OBJ3)

fclean	:	clean
	@$(RM) $(NAME) $(NAME2)

re		:	fclean all