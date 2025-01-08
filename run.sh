cc parse.c libft/libft.a &&  valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./a.out 0 1 2 3 4 5 6 7 8 9
