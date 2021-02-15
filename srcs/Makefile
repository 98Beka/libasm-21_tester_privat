NAME =  tester.a
LIBFT = libft.a
SRCS =	ch_read.c dop.c test.c main.c longstr.c get_next_line.c
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	@gcc $(CFLAGS) -c $(SRCS) $(H)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm 	-f $(OBJ)

re: fclean all

fclean: clean
	rm -rf $(NAME)

.PHONY: clean fclean all re