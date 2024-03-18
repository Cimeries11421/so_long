NAME = so_long
CFLAGS = -Wall -Wextra -g3 -Werror
CPPFLAGS= -I libft/src -I minilibx-linux/ # -I : include 
CC = cc
SRC = \
	  main.c store_textures.c display_and_move_around.c get_map.c check_map.c \
	  check_path.c exit.c display_map.c display_movement.c

OBJ = $(SRC:.c=.o)

LIBFT= libft/libft.a

LIBMLX= minilibx-linux/libmlx.a

MLXFLAGS = -lX11 -lXext

HEADERS= so_long.h minilibx-linux/mlx.h libft/src/libft.h 

all : lib
	$(MAKE) $(NAME)


$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(LIBMLX) $(MLXFLAGS)

%.o : %.c $(HEADERS) 	
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

lib :
	$(MAKE) -C libft/
	$(MAKE) -C minilibx-linux/ 2>/dev/null

re: fclean
	$(MAKE) all

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/

clean :
	rm -rf $(OBJ)
	$(MAKE) clean -C libft/
	$(MAKE) clean -C minilibx-linux/


sanitize:
	make CFLAGS="-Wall -Wextra -g3 -fsanitize=address"

debug:
	make CFLAGS="-Wall -Wextra -g3"

.PHONY : all clean fclean re
