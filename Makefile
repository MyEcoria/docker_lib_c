##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC	=	gcc
MAKE	=	make
NAME	=	docker
SRC_DIR	=	src
OBJ_DIR	=	obj

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
RESET = \033[0m

SRC	=	$(SRC_DIR)/docker_api.c \
		$(SRC_DIR)/docker_config.c \
		$(SRC_DIR)/docker_image.c \
		$(SRC_DIR)/docker_utils.c \
		$(SRC_DIR)/docker_containers.c \
		$(SRC_DIR)/docker_process.c

OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Wextra -Iinclude/ -lcurl -ljson-c -lgc

define print_percentage
	@printf "$(BLUE)[INFO]$(RESET) $(1): $(YELLOW)%d%%$(RESET)\n" $(2)
endef

all: title $(NAME)
	@printf "$(YELLOW)[STATUS]$(RESET)" $(2)
	@printf " Compilation du module terminé: $(BLUE)$(NAME).a$(RESET)\n" $(2)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME).a $(OBJ_LIB) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: title_clean
	-rm -f $(OBJ)
	-rmdir $(OBJ_DIR)

fclean: clean
	-rm -f $(NAME)
	-rm -f $(NAME).a
	-rm -f *.log
	-rm -f unit_tests

test: re
	$(CC) -o docker examples/create.c $(NAME).a $(CFLAGS) -g
	@printf "$(YELLOW)[STATUS]$(RESET)" $(2)
	@printf " Compilation du test terminé: $(BLUE)$(NAME)$(RESET)\n" $(2)

re: fclean all

title:
	@echo "$(GREEN)===== Compilation de Docker API =====$(RESET)"

title_clean:
	@echo "$(RED)===== Nettoyage de Docker API =====$(RESET)"
