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
NAME		=	philosopher
INCL		=	-I include

SRC_DIR		=	./src/core
SRC			=	philos.c error_check.c get_arguments.c

UTIL_DIR	=	./src/utils
UTILS		=	ft_isdigit.c ft_memset.c philos_atoi.c

SIM_DIR =	./src/simulation
SIMULATION	=	init_simulation.c

OBJ			=	./obj

# Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror #-g -fsanitize=address #-lpthread
RM		=	rm -rf

all:	libfilo bin

libfilo:
	$(CC) -c $(SRC_DIR)/error_check.c $(INCL) -o $(OBJ)/error_check.o
	$(CC) -c $(SRC_DIR)/get_arguments.c $(INCL) -o $(OBJ)/get_arguments.o
	$(CC) -c $(UTIL_DIR)/ft_isdigit.c $(INCL) -o $(OBJ)/ft_isdigit.o
	$(CC) -c $(UTIL_DIR)/ft_memset.c $(INCL) -o $(OBJ)/ft_memset.o
	$(CC) -c $(UTIL_DIR)/philos_atoi.c $(INCL) -o $(OBJ)/philos_atoi.o
	$(CC) -c $(SIM_DIR)/init_simulation.c $(INCL) -o $(OBJ)/init_simulation.o

bin:
	$(CC) $(SRC_DIR)/philos.c $(OBJ)/*.o $(INCL) -o philosophers


# Compile and Assemble C Source Files into Object Files


# Link all Object Files with external Libraries into Binaries


# Clean Up Objects, Exectuables, Dumps out of source directory
clean: 
	$(RM) $(OBJ)/*.o philosophers

re: clean all

.PHONY: all clean fclean re bonus