CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
LIBFT = libft.a
LIBFT_DIR = libft
NAME = push_swap
BONUS_NAME = checker

MSRC = main.c parse.c sort.c operations.c execute.c
BSRC = bonus/checker.c bonus/parse.c bonus/operations.c bonus/execute.c


all : $(LIBFT) $(NAME)

bonus : $(LIBFT) $(BONUS_NAME)

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(NAME) : $(MSRC)
	$(CC) $(CFLAGS) -o $(NAME) $(MSRC) -L$(LIBFT_DIR) -lft -fPIE

$(BONUS_NAME) : $(BSRC)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BSRC) -L$(LIBFT_DIR) -lft -fPIE

clean :
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)

re : fclean all
