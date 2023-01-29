NAME		=	philosophers

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS		=	main.c philo_verif.c philo_init.c \
				philo_free.c philo_utils.c philo_doing_things.c

OBJ_DIR		=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

RM			=	rm -f

all:			${NAME}

$(OBJ_DIR)/%.o: %.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} ${OBJ_CHANGES} philosophers.h
				$(CC) $(CFLAGS) $^ -o $@ -lpthread
#-fsanitize=thread

clean:
				${RM} -r ${OBJ_DIR}
				${RM} -r ${OBJ_DIR_B}
				${RM} philosophers_bonus/*.o
				${RM} *.o

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY: 		all clean fclean re
