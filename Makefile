# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 20:51:28 by migarci2          #+#    #+#              #
#    Updated: 2024/02/28 21:59:16 by migarci2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = cub3d


CC       = gcc
CFLAGS   = -Wall -Wextra -Werror

ifeq ($(DEBUG),1)
    DEBUG = -DDEBUG=1
endif

LIBMLX   = lib/MLX42
LIBFT    = lib/libft

SRC_DIR  = src
SRCs     =  $(SRC_DIR)/main.c \
            $(SRC_DIR)/misc/management.c \
            $(SRC_DIR)/misc/misc.c \
            $(SRC_DIR)/misc/sanitize_line.c \
			$(SRC_DIR)/misc/floodfill.c \
            $(SRC_DIR)/parsing/checker.c \
            $(SRC_DIR)/parsing/color.c \
            $(SRC_DIR)/parsing/debug.c \
            $(SRC_DIR)/parsing/map_size.c \
            $(SRC_DIR)/parsing/parser.c \
			$(SRC_DIR)/game/init.c \
			$(SRC_DIR)/game/hooks.c \
			$(SRC_DIR)/game/render.c \
			$(SRC_DIR)/game/move.c \
			$(SRC_DIR)/game/rotate.c \
			$(SRC_DIR)/game/raycast.c \
			$(SRC_DIR)/game/texture.c \
			$(SRC_DIR)/game/sliding.c \
			$(SRC_DIR)/game/valid_move.c \
			$(SRC_DIR)/game/draw.c \

OBJ_DIR  = obj
OBJs     = $(SRCs:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDE  = -I./include -I$(LIBMLX)/include/MLX42 -I$(LIBFT)/include

# Detección de sistema operativo para ajustar LIBGL
UNAME_S := $(shell uname -s)
LIBGL    = -lglfw
ifeq ($(UNAME_S),Darwin) # macOS
	LIBGL    = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
else ifeq ($(UNAME_S),Linux)
	LIBGL    = -lglfw 
endif

LIBMATH  = -lm

LIBS = -L$(LIBMLX)/build -lmlx42 -L$(LIBFT) -lft -ldl $(LIBGL) -lm -pthread

all: $(NAME)

$(LIBFT)/libft.a:
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT) > /dev/null

$(LIBMLX)/build/libmlx42.a:
	@echo "Compiling MLX42..."
	@rm -rf $(LIBMLX)/build
	@cd $(LIBMLX) && cmake -B build -DDEBUG=$(DEBUG) && cmake --build build -j4 > /dev/null

libraries: $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME): libraries $(OBJs)
	@echo "Linking $@..."
	@$(CC) $(OBJs) $(LIBS) -o $(NAME)
	@echo "$@ compilation complete."

norminette:
	@echo "Checking norminette..."
	@norminette $(SRC_DIR)
	@norminette include

clean:
	@echo "Cleaning up object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT) clean > /dev/null
	@$(MAKE) -C $(LIBMLX)/build clean > /dev/null

fclean: clean
	@echo "Cleaning up executable and libraries..."
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re libraries