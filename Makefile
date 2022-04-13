CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

NAME	= pipex

LIBFT 	= libft/libft.a

SRC 	= 	pipex.c \
			utils.c \

OBG 	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBG)

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re