NAME				= FragTrap

CC					= c++

CFLAGS				= -Wall -Wextra -Werror -g -std=c++98

EXTENSION			= .cpp

SRCS				= main$(EXTENSION) ClapTrap$(EXTENSION) ScavTrap$(EXTENSION) FragTrap$(EXTENSION)

OBJ_DIR				= objs

OBJ					= $(addprefix $(OBJ_DIR)/,$(SRCS:%$(EXTENSION)=%.o))

RM					=	rm -f

all:				${NAME}

$(OBJ_DIR)/%.o:		%.cpp
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

${NAME}:			${OBJ}
					$(CC) $(CFLAGS) $^ -o $@

clean:
					${RM} -r ${OBJ_DIR}
#${RM} *.o

fclean:				clean
					${RM} ${NAME}

re:					fclean all

.PHONY: 			all clean fclean re 