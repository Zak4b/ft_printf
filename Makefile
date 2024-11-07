NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c

OBJS = $(SOURCES:.c=.o)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all