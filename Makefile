# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 20:51:28 by migarci2          #+#    #+#              #
#    Updated: 2024/02/19 21:17:37 by migarci2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = cub3d

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -g

LIBMLX   = lib/MLX42
LIBFT    = lib/libft

SRC_DIR  = src
SRCs     = $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR  = obj
OBJs     = $(SRCs:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDE  = -I./include -I$(LIBMLX)/include -I$(LIBFT)

ifeq ($(UNAME_S),Darwin) # macOS
	LIBGL    = -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib"
else ifeq ($(UNAME_S),Linux)
	LIBGL    =
endif

LIBS     = $(LIBGL) -L$(LIBMLX)/build -lmlx42 -L$(LIBFT) -lft

all: $(NAME)

$(LIBFT)/libft.a:
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT)

$(LIBMLX)/build/libmlx42.a:
	@echo "Compiling MLX42..."
	@rm -rf $(LIBMLX)/build
	@cd $(LIBMLX) && mkdir -p build && cd build && cmake .. && make

libraries: $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(NAME): libraries $(OBJs)
	@echo "Linking $@..."
	@$(CC) $(OBJs) $(LIBS) -o $(NAME)
	@echo "$@ compilation complete."

clean:
	@echo "Cleaning up object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX)/build clean

fclean: clean
	@echo "Cleaning up executable and libraries..."
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libraries