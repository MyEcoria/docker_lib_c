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

SRC	=	$(SRC_DIR)/docker_api.c \
		$(SRC_DIR)/docker_config.c \
		$(SRC_DIR)/docker_functions.c \
		$(SRC_DIR)/docker_utils.c

OBJ	=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Wextra -Iinclude/ -lcurl -ljson-c -lgc

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME).a $(OBJ_LIB) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	-rmdir $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests

test: re
	$(CC) -o docker examples/create.c $(NAME).a $(CFLAGS) -g

re: fclean all
