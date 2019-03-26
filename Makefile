
NAME_P = push_swap.a

NAMEP = push_swap

NAME_C = checker.a

NAMEC = checker

INC_DIR = ./inc/*.h

LIB_DIR = ./lib/ft_printf/libftprintf.a

SRC_DIR = ./src/push_swap/*.c

OBJ_DIR = ./obj

OBJ = *.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

FT_PRINTF = ./lib/ft_printf

GREEN = \033[31m

RED = \033[31m

END = \033[0m

all: $(NAMEP)

push_swap:
	@make -C lib/ft_printf
	$(CC) $(CFLAGS) $(SRC_DIR) -I$(INC_DIR)
	$(CC) -L. $(LIB_DIR) -I$(INC_DIR) $(OBJ) -o $(NAMEP)
	@make clean

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME_P)
	@rm $(NAMEP)

re: fclean all