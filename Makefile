NAME			=	phIlosophers

SOURCE_FILES	= 	tread.c
SOURCE_DIR		=	src

INCLUDES		= 	INCLUDES
INCLUDES 		:= 	${addfrefix -I, $(INCLUDES)}

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -lpthread -fsanitize=address

RM				=	rm -fr

OBJS_DIR		= 	obj
OBJS			=	$(subst $(SOURCE_DIR,$(OBJS_DIR),$(SOURCE_FILES:.c=.o)))

all: $(NAME)

$(NAME) $(OBJS)
@-$(CC) $(CFLAGS) $(OBJS)

clean:

fclean: