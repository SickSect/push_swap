NAME		=	push_swap

BONUS_NAME 	=	checker

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O0 -g

SRC			=	mandatory/main.c mandatory/swap.c mandatory/rotate.c mandatory/lst_func.c mandatory/irrotate.c mandatory/push.c mandatory/indexing.c\
				mandatory/check_argv.c mandatory/base_func.c mandatory/half_sort.c mandatory/sort.c mandatory/quick_sort.c mandatory/sort_node.c mandatory/make_simple_argv.c\
				mandatory/quick_sort_func.c mandatory/split.c
SRC_BONUS	= 	bonus/main_bonus.c bonus/console_bonus.c bonus/get_next_line_bonus.c \
				bonus/get_next_line_utils.c bonus/irrotate_bonus.c bonus/rotate_bonus.c \
				bonus/swap_bonus.c 

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(RM) $(OBJ_BONUS)
			$(CC) $(FLAGS) -o $(NAME) $^

$(BONUS_NAME): $(OBJ_BONUS)
			@$(RM) $(OBJ)
			$(CC) $(FLAGS) -o $(BONUS_NAME) $^

bonus: $(BONUS_NAME)

%.o:	%.c
			$(CC) $(FLAGS) -o $@ -c $<

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re