NAME			=	accounts

CC				=	c++

EXTENSION		=	.cpp

CFLAGS			=	-Wall -Wextra -Werror -std=c++98

SRCS			=	Account$(EXTENSION) tests$(EXTENSION)

OBJ_DIR			=	obj

OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRCS:%$(EXTENSION)=%.o))

RM				=	rm -f

all:				${NAME}

$(OBJ_DIR)/%.o:		%.cpp
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

${NAME}:			${OBJ}
					$(CC) $(CFLAGS) $^ -o $@

clean:
					${RM} -r ${OBJ_DIR}
					${RM} *.o

fclean:				clean
					${RM} ${NAME}

re:					fclean all

.PHONY: 			all clean fclean re
