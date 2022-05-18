CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

NAME	= m_pipex/mandatory.a

BONUS	= b_pipex/bonus.a

LIBFT 	= libft/libft.a

SRC 	= 	m_pipex/pipex.c \
			m_pipex/utils.c \
			m_pipex/processes.c

OBG 	= $(SRC:.c=.o)

B_SRC	=	b_pipex/pipex_bonus.c \
			b_pipex/utils_bonus.c \
			b_pipex/processes_utils.c \

B_OBG	=  $(B_SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBG)
	rm -rf $(BONUS)
	ar rcs $(NAME) $(OBG)
	$(CC) $(CFLAGS) $(NAME) $(LIBFT) -o pipex

bonus:	$(BONUS)

$(BONUS):	$(LIBFT) $(B_OBG)
	rm -rf $(NAME)
	ar rcs $(BONUS) $(B_OBG)
	$(CC) $(CFLAGS) $(BONUS) $(LIBFT) -o pipex


$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -rf $(OBG)
	rm -rf $(B_OBG)

fclean: clean
	rm -rf libft/libft.a
	rm -f pipex
	rm -rf $(NAME)
	rm -rf $(BONUS)

re:	fclean all

.PHONY: all clean fclean re