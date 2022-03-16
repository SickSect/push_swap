NAME		=	push_swap

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC			=	main.c ft_atoi.c is_digit.c lst_new.c swap.c rotate.c \
				ft_lstdel.c irrotate.c quick_sort.c printer.c push.c \
				lstlast.c lst_issort.c lst_copier.c

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