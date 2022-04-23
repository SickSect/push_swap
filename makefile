NAME		=	push_swap

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC			=	main.c ft_atoi.c is_digit.c swap.c rotate.c lst_func.c\
				irrotate.c pre_sort.c printer.c push.c indexing.c\
				check_argv.c ft_putstr.c half_sort.c pre_sort.c\
				sort.c quick_sort.c\
				quick_sort_func.c

OBJ			=	$(SRC:.c=.o)

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $^ $(LIB)

%.o:	%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re