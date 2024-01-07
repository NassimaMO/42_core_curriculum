NAME			=	Interns

CC				=	c++

CFLAGS			=	-Wall -Wextra -Werror -g -std=c++98

SRCS			=	Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp main.cpp

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
				${RM} *.o
				${RM} *_shrubbery

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re