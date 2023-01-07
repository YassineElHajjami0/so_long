NAME = so_long
BONS = so_long_bonus
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
CC = cc


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
	strput_destroy.c \

BNS = the_bonus.c \
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
	strput_destroy.c \

all : $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(BONS): $(BNS)
	$(CC) $(CFLAGS) $(BNS) -o $(BONS)

bonus: $(BONS)

clean :
	rm -rf $(NAME)

fclean : clean
	rm -rf $(BONS)

re : fclean all