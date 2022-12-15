# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS =	main.c

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~ PARSING ~~~~~~ */
PARSING_DIR = ./srcs/parsing/
PARSING =	ft_fill_map.c \
			ft_check_wall.c \
			ft_map_has_all_needed.c \
			ft_check_position.c \
			ft_find_position.c \
			ft_print_map.c \
			ft_check_around.c \
			ft_check_map.c \

OBJS_PARSING = ${addprefix ${PARSING_DIR}, ${PARSING:.c=.o}}

# /* ~~~~~~ DISPLAY_MAP ~~~~~~ */
DISPLAY_MAP_DIR = ./srcs/display_map/
DISPLAY_MAP =	display_game.c \
			handle_event.c \
			utils_display_map.c 

OBJS_DISPLAY_MAP = ${addprefix ${DISPLAY_MAP_DIR}, ${DISPLAY_MAP:.c=.o}}

# /* ~~~~~~ MOVE_MAP ~~~~~~ */
MOVE_DIR = ./srcs/move_perso/
MOVE =	move.c \
		update_item_on_move.c


OBJS_MOVE = ${addprefix ${MOVE_DIR}, ${MOVE:.c=.o}}

# /* ~~~~~~~ INCLUDING GNL ~~~~~~~ */
GNL_DIR = ./get_next_line/
GNL = get_next_line.c \
	get_next_line_utils.c \

GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = libft
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING PRINTF ~~~~~~~ */
FT_PRINTF_DIR = ft_printf
FT_PRINTF_MAKE = Makefile
FT_PRINTF_PATH = ${FT_PRINTF_DIR}/libftprintf.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = minilibx-linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = clang
CFLAGS = -Wall -Werror -Wextra -g # -MMD
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH)
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft
LPRINTF_FLAGS:= -L $(FT_PRINTF_DIR) -lftprintf 

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = so_long
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}

$(NAME): $(OBJS) $(GNL_OBJS) $(OBJS_PARSING) $(OBJS_MOVE) $(OBJS_DISPLAY_MAP)
	@make -C ${MLX_DIR}
	@cd $(LIBFT_DIR) && $(MAKE)
	@cd $(FT_PRINTF_DIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(OBJS_PARSING) $(OBJS_MOVE) $(OBJS_DISPLAY_MAP) $(IFLAGS) $(LFLAGS) $(LPRINTF_FLAGS) -o $(NAME) $(MFLAGS) 
	@echo $(GREEN) "[OK COMPILED]" $(EOC)
	@echo $(GREEN) "[LAUNCH PROGRAMM]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS} $(OBJS_PARSING) $(GNL_OBJS) $(OBJS_DISPLAY_MAP) $(OBJS_MOVE) ${NAME}
		@${RM} -r ${OBJ_DIR}
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} $(OBJS_PARSING) $(GNL_OBJS) $(OBJS_DISPLAY_MAP) $(OBJS_MOVE) ${NAME}
		@make -C $(FT_PRINTF_DIR) -f $(FT_PRINTF_MAKE)  
		@cd $(LIBFT_DIR) && $(MAKE) fclean
		
re: 	fclean all

.PHONY: all clean fclean re