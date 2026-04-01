
NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft/
PRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/gnl_bonus/
OTHER_DIR = other/

SRC = \
$(wildcard $(LIBFT_DIR)*.c) \
$(wildcard $(PRINTF_DIR)*.c) \
$(wildcard $(GNL_DIR)*.c) \
$(wildcard $(OTHER_DIR)*.c)

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar r $@ $^

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
