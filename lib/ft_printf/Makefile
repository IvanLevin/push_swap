C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

LIBFT = libft

HEADER = include

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES =	ft_printf.c	print_free.c data_types.c ft_parsing.c ft_printf.c \
			ft_check_valid.c ft_d_i_pars.c ft_itoa_base.c ft_itoa_long.c \
			ft_percent.c ft_precision_d_or_i.c ft_print_x.c ft_printf_c.c \
			ft_printf_cs.c	ft_printf_d_i_u.c ft_printf_d.c ft_printf_f.c \
			ft_printf_p.c ft_printf.c print_free.c x_amount.c x_filler.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
