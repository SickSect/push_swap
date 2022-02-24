NAME		=	push_swap

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRC			=	main.c ft_atoi.c

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