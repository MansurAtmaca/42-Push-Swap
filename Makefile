NAME = push_swap
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
CFILES = ft_split.c \
		ft_atoi.c \
		utils_funcs.c \
		ft_error.c \
		ft_quicksort.c \
		mini_sorts.c \
		push_swap.c \
		rules_a.c \
		rules_b.c \
		rules_double.c \
		sort_funcs.c \

OBJS = $(CFILES:.c=.o)

$(NAME): $(OBJS)

	@cc $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:

	@rm -rf $(OBJS)

fclean: clean

	@rm -f $(NAME)


re: fclean all