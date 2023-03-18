NAME		=	philo

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS_DIR	=	.

SRCS		=	new_philo.c new_philo_check.c new_philo_init.c new_philo_threads.c \
				new_philo_free.c new_philo_utils.c new_philo_doing_things.c

OBJ_DIR		=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

RM			=	rm -f

all:			${NAME}

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} new_philo.h
				$(CC) $(CFLAGS) $^ -o $@ -lpthread -fsanitize=thread

clean:
				${RM} -r ${OBJ_DIR}
				${RM} *.o

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re
