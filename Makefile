# Has to use NAME, clean, fclean, re
# objetivo : dependencias
#	instrucciones
NAME = libft
OBJS = *.o
CFLAGS = -Wall -Werror -Wextra
libft : $(OBJS)
	@gcc -o $(NAME) $(OBJS)



clean:
	rm -f *.o