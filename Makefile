NAME = so_long
SRC = so_long.c \
	get_next_line.c \
	get_next_line_utils.c \
	split.c \
	check_walls.c \
	fn.c \
	check_chars.c \
	check_key.c \
	backtracking.c \
	check_l_r.c \
	parsing_win.c \
	move_enemy.c \
	display_map.c \
	check_p_d_e.c \

# CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all