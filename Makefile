
.PHONY: all bonus clean fclean re

FLAGS=-Wall -Werror -Wextra
NAME=libftprintf.a
CC=cc

BONUS_DEPS=bonus/ft_atoi.c bonus/ft_char_print_utils.c bonus/ft_number_print_utils.c bonus/ft_printf.c bonus/ft_utilities.c

MUST_DEPS=mandatory/ft_atoi.c mandatory/ft_char_print_utils.c mandatory/ft_number_print_utils.c mandatory/ft_printf.c mandatory/ft_utilities.c

BONUS_OBJS=$(BONUS_DEPS:.c=.o)
MUST_OBJS=$(MUST_DEPS:.c=.o)

$(NAME): $(MUST_OBJS) mandatory/ft_printf.h
	ar -rc $(NAME) $(MUST_OBJS)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

bonus: $(BONUS_OBJS) bonus/ft_printf.h
	ar -rc $(NAME) $(BONUS_OBJS)

all: $(NAME)

clean:
	rm -f $(MUST_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
