NAMEP = push_swap

NAMEC = checker

INC_DIR = ./inc/push_swap.h

LIB_DIR = ./lib/ft_printf/libftprintf.a

SRC_DIR = ./src/push_swap/*.c

SRC_CHECK = ./src/push_swap/check_valid.c \
			./src/checker/*.c \
			./src/push_swap/swap_rules.c \
			./src/push_swap/swap_rules_2.c \
			./src/push_swap/swap_rules_3.c \
			./lib/get_next_line/get_next_line.c \

OBJ_DIR = ./obj

OBJ = *.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

FT_PRINTF = ./lib/ft_printf

LOG_GREEN = \033[32m

LOG_RED	= \033[1;31m

END = \033[0m

all: $(NAMEP) $(NAMEC)

push_swap:
	@make -C lib/ft_printf
	@$(CC) $(CFLAGS) $(SRC_DIR) -I$(INC_DIR)
	@$(CC) $(OBJ) -L. $(LIB_DIR) -I$(INC_DIR) -o $(NAMEP)
	@echo "$(LOG_GREEN)PUSH_SWAP CREATED SUCCESSFULLY$(END)"
	@make clean

checker:
	@$(CC) $(CFLAGS) $(SRC_CHECK) -I$(INC_DIR)
	@$(CC) $(OBJ) -L. $(LIB_DIR) -I$(INC_DIR) -o $(NAMEC)
	@echo "$(LOG_RED)CHECKER CREATED SUCCESSFULLY$(END)"
	@make clean

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm $(NAMEP)
	@rm $(NAMEC)

re: fclean all
