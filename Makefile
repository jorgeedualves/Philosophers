NAME			=	philo
SOURCES_FILES	=	philosophers.c
SOURCES_FILES	+=	error_check.c print_status.c utils_dinner.c utils.c

SOURCES_DIR		=	src

OBJ_DIR			=	obj

HEADER			=	$(SOURCES_DIR)/philosophers.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				=	gcc
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS			=	-pthread

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(RM) $(OBJ_DIR)

fclean:	clean
					$(RM) $(NAME)

re:	fclean all

.PHONY:all clean fclean re bonus