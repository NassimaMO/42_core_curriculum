NAME		=	philosophers

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS_DIR	=	srcs

SRCS		=	main.c philo_verif.c philo_init.c \
				philo_free.c philo_utils.c philo_doing_things.c

OBJ_DIR		=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

RM			=	rm -f

all:			${NAME}

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} includes/philosophers.h
				$(CC) $(CFLAGS) $^ -o $@ -lpthread
#-fsanitize=thread

clean:
				${RM} -r ${OBJ_DIR}
				${RM} *.o

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re
