CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBFT_DIR = libft
NAME = push_swap

MSRC = main.c parse.c sort.c operations.c execute.c


all : $(LIBFT) $(NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(NAME) : $(MSRC)
	$(CC) $(CFLAGS) -o $(NAME) $(MSRC) -L$(LIBFT_DIR) -lft -fPIE

clean :
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)

re : fclean all
