NAME_P = push_swap.a

NAME_C = checker.a

FLAGS = -Wall -Wextra -Werror

OBJ = *.o

DIR_S = sources/push_swap

FT_PRINTF = ft_printf

INCLUDE = include

GNL = get_next_line

SOURCES_C = sources/checker/checker.c sources/push_swap/swap_rules.c \
			sources/push_swap/swap_rules_2.c \
			sources/push_swap/swap_rules_3.c ft_printf/libftprintf.a \
			get_next_line/get_next_line.c

OBJ_C = $(SOURCES_C:.c=.o)

SOURCES_P = sources/push_swap/main.c \
			sources/push_swap/check_valid.c \
			sources/push_swap/find_pivot.c \
			sources/push_swap/push_swap.c \
			sources/push_swap/sort_algorithm.c \
			sources/push_swap/sort_print.c \
			sources/push_swap/swap_func.c \
			sources/push_swap/swap_quick_sort.c \
			sources/push_swap/swap_quick_sort_a.c \
			sources/push_swap/swap_rules.c \
			sources/push_swap/swap_rules_2.c \
			sources/push_swap/swap_rules_3.c \

GREEN = \033[31m
RED = \033[31m
END = \033[0m

all: $(NAME_P)
	
$(NAME_P):
	@make -C $(FT_PRINTF)
	gcc $(FLAGS) -c $(SOURCES_P)
	gcc $(FLAGS) -o $(NAME_P) $(OBJS)
	ar rc $(NAME_P) $(OBJ)

%.0: %.c
	gcc -c $(FLAGS) -I libft/ft_printf -o $@ -c $<
# $(NAME_C):
# 	@make -C $(FT_PRINTF)
# 	gcc $(FLAGS) -c $(SOURCES_C)
# 	ar rc $(NAME_C) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME_P)

re: fclean all
