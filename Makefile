NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS= -I libft/src -I minilibx-linux/ # -I : include 
CC = cc
SRC = \
	  begin.c 

OBJ = $(SRC:.c=.o)

LIBFT= libft/libft.a

LIBMlX = minilibx/libmlx.a

MLXFLAGS = -Lminilibx-linux/ -lmlx -lX11 -lXext

all : $(NAME)
	
%.o : %.c pipex.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)
	make fclean -C libft #appel le make de libft

clean :
	rm -rf $(OBJ)

sanitize:
	make CFLAGS="-Wall -Wextra -Werror -g3 -fsanitize=address"

debug:
	make CFLAGS="-Wall -Wextra -Werror -g3"

FORCE : 

$(LIBMLX) : FORCE
	make -C minilibx-linux
 
$(LIBFT) : FORCE #commande vide pour qu'il execute a chaque fois make
	make -C libft # -C : make dans un autre dossier.

.PHONY : all clean fclean re

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(MLXFLAGS)

