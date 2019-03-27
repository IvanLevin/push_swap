NAMEP = push_swap

NAMEC = checker

INC_DIR = ./inc/push_swap.h

LIB_DIR = ./lib/ft_printf/libftprintf.a

SRC_DIR = ./src/push_swap/*.c

SRC_CHECK = ./src/push_swap/check_valid.c \
			./src/checker/*.c \
			./src/push_swap/swap_rules.c \
			./lib/get_next_line/get_next_line.c \
			./src/push_swap/helpers2.c \
			./src/push_swap/check_valid.c \
			./src/push_swap/helpers1.c \
			./src/push_swap/helpers3.c \
			./src/push_swap/sort_algorithm.c \
			./src/push_swap/swap_quick_sort.c

OBJ_DIR = ./obj

OBJ = *.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

FT_PRINTF = ./lib/ft_printf

GREEN = \033[31m

RED = \033[31m

END = \033[0m

all: $(NAMEP) $(NAMEC)

push_swap:
	@make -C lib/ft_printf
	$(CC) $(CFLAGS) $(SRC_DIR) -I$(INC_DIR)
	$(CC) $(OBJ) -L. $(LIB_DIR) -I$(INC_DIR) -o $(NAMEP)
	@make clean

checker:
	$(CC) $(CFLAGS) $(SRC_CHECK) -I$(INC_DIR)
	$(CC) $(OBJ) -L. $(LIB_DIR) -I$(INC_DIR) -o $(NAMEC)
	@make clean

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm $(NAMEP)
	@rm $(NAMEC)

re: fclean all
