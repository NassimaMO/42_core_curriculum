NAME			=	array

CC				=	c++

CFLAGS			=	-Wall -Wextra -Werror -g -std=c++98

SRCS			=	main.cpp

OBJ_DIR			=	obj

OBJ				=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.cpp=%.o))

RM				=	rm -f

all:				${NAME}

$(OBJ_DIR)/%.o:		%.cpp
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

${NAME}:			${OBJ}
					$(CC) $(CFLAGS) $^ -o $@

clean:
				${RM} -r ${OBJ_DIR}
				${RM} ${OBJ}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re