NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf

# Directorios
INC_DIR = include
OBJ_DIR = obj
SRC_DIR = src

# Fuentes y objetos
SRCS_FT = $(wildcard $(SRC_DIR)/ft/*.c)
SRCS_GNL = $(wildcard $(SRC_DIR)/gnl/*.c)

OBJS_FT = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_FT))
OBJS_GNL = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS_GNL))

# Colores
WHITE	:= \033[37;1m
RESET	:= \033[0m
U_LINE	:= \033[4m
BLUE	:= \033[1;38;5;27m

# Compilación
$(NAME): $(OBJS_FT) $(OBJS_GNL)
	@$(AR) $@ $(OBJS_FT) $(OBJS_GNL)

# Creación de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling:$(RESET) $(notdir $<)"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)


clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(BLUE)Cleaning up object files$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)Removing library$(RESET)"

re: fclean all

.PHONY: all show clean fclean re
