NAME		=	push_swap

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O0 -g

SRC			=	main.c swap.c rotate.c lst_func.c irrotate.c push.c indexing.c\
				check_argv.c base_func.c half_sort.c sort.c quick_sort.c sort_node.c make_simple_argv.c\
				quick_sort_func.c split.c

OBJ			=	$(SRC:.c=.o)

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)

%.o:	%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re