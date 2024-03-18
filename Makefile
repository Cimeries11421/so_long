NAME = so_long
CFLAGS = -Wall -Wextra -g3 #-Werror
CPPFLAGS= -I libft/src -I minilibx-linux/ # -I : include 
CC = cc
SRC = \
	  begin.c store_textures.c display_and_move_around.c get_map.c check_map.c \
	  check_path.c so_long_utils.c

OBJ = $(SRC:.c=.o)

LIBFT= libft/libft.a

LIBMlX = minilibx/libmlx.a

MLXFLAGS = -Lminilibx-linux/ -lmlx -lX11 -lXext

all : $(NAME)
	
%.o : %.c so_long.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

re: fclean all

fclean: clean
	rm -f $(NAME)
	make fclean -C libft #appel le make de libft

clean :
	rm -rf $(OBJ)

sanitize:
	make CFLAGS="-Wall -Wextra -g3 -fsanitize=address"

debug:
	make CFLAGS="-Wall -Wextra -g3"

FORCE : 

$(LIBMLX) : FORCE
	make -C minilibx-linux
 
$(LIBFT) : FORCE #commande vide pour qu'il execute a chaque fois make
	make -C libft # -C : make dans un autre dossier.

.PHONY : all clean fclean re

$(NAME) : $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) -o $(NAME) $(MLXFLAGS)

