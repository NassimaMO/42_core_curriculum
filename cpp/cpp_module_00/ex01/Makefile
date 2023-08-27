NAME			=	phonebook

CC				=	g++

EXTENSION		=	.cpp

CFLAGS			=	-Wall -Wextra -Werror -g -std=c++98

SRCS			=	Phonebook$(EXTENSION), Contact$(EXTENSION)

OBJ_DIR			=	obj

OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRCS:%$(EXTENSION)=%.o))

HEADER			= 	Phonebook.hpp

RM				=	rm -f

all:				${NAME}

$(OBJ_DIR)/%.o:		%.cpp
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

${NAME}:			${OBJ} ${HEADER}
					$(CC) $(CFLAGS) $^ -o $@

clean:
				${RM} -r ${OBJ_DIR}
				${RM} *.o

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re
