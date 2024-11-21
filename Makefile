NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c ft_printf_conversions.c ft_lltoa.c ft_ulltoa.c

OBJS = $(SOURCES:.c=.o)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) libft/libft.a
	cp libft/libft.a $(NAME)
	ar -rs $(NAME) $(OBJS)

all: $(NAME)

libft/libft.a:
	make -C libft bonus

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all