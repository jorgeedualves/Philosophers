# Source, Executable, Includes, Library Defines
#NAME		=		philosophers

#INCLUDE		=	-I include

#UTIL_DIR 	= 	./src/utils 
#UTIL		=	$(UTIL_DIR)/utils.a
#UTIL_FLAGS	=	-L $(UTIL_DIR) -lft

#RM			=	rm -f

#CC			=	gcc
#CFLAGS		=	-Wall -Wextra - Werror -g -fsanitize=address -pthreads
#VALGRIND	= 	valgrind -q --leak-check=full --show-leak-kinds=all - s --track-origins=yes

#CORE		=	philos.c error_check.c

#SRCS_DIR		=	src

#FILES		=	$(addprefix CORE/, $(CORE))

#SOUCE		=	$(addprefix src/, $(FILES))

#OBJ_DIR		=	obj
#OBJS		=	$(subst $(SRCS_DIR),$(OBJ_DIR),$(SOURCE:.c=.o))))	

#all: $(NAME)

#$(NAME): $(OBJ)
#	make -C $(UTIL_DIR)
#	@echo "\033[32mEXECUTANDO ARQUIVOS...\033[0m"
#	$(CC) $(CFLAGS) $(OBJS) $(UTILS) $(UTIL_FLAGS) -o $@

#$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
#	@mkdir -p obj
#	@mkdir -p obj/CORE
#	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#clean:
#	$(RM) $(OBJ)
#	$(RM) $(NAME)

#re: clean all

#.PHONY: all clean re



# Source, Executable, Includes, Library Defines
NAME		=	philosophers
INCL		=	-I include

SRC_DIR		=	./src
SRC			=	error_check.c

UTIL_DIR	=	./utils
UTILS		=	print_status.c utils_dinner.c utils.c

OBJ			=	./obj

# Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address #-lpthread
RM		=	rm -rf

all:	libfilo bin

libfilo:
	$(CC) -c $(CFLAGS) $(SRC_DIR)/error_check.c $(INCL) -o $(OBJ)/error_check.o

bin:
	$(CC)  $(CFLAGS)$(SRC_DIR)/philosophers.c $(OBJ)/*.o $(INCL) -o philosophers


# Compile and Assemble C Source Files into Object Files


# Link all Object Files with external Libraries into Binaries


# Clean Up Objects, Exectuables, Dumps out of source directory
clean: 
	$(RM) $(OBJ)/*.o philosophers

re: clean all

.PHONY: all clean fclean re bonus