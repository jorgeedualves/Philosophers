# Source, Executable, Includes, Library Defines
NAME		=		philosophers


INCLUDE_DIR	=	./include
INCLUDE 	:=	$(addprefix -I, $(INCLUDE_DIR)) 
HEADERS 	:= 	$(INCLUDE)/philosophers.h

SRC_DIR		= 	./src/core
SRC_FILES	=	philos.c error_check.c
SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

UTIL_DIR 	= 	./src/utils 
UTIL_FILES	=	ft_atoi.c ft_isdigit.c ft_memset.c philos_atoi.c
UTIL		=	$(addprefix $(UTIL_DIR)/, $(UTIL_FILES))

OBJ_DIR		=	./obj
OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_UTILS	=	$(UTIL:$(UTIL_DIR)/%.c=$(OBJ_DIR)%.o)

RM			=	rm -f

CC			=	gcc
CFLAGS		=	-Wall -Wextra - Werror
VALGRIND	= 	valgrind -q --leak-check=full --show-leak-kinds=all - s --track-origins=yes

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_UTILS) $(OBJ)
	@echo "\033[32mEXECUTANDO ARQUIVOS...\033[0m"
	$(CC) $(OBJ) $(CFLAGS) $(OBJ_UTILS) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(UTIL_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: clean all

.PHONY: all clean re