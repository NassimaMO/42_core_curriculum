NAME		=	philo

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS_DIR	=	srcs

SRCS		=	main.c valid_args_check.c struct_init.c thread_routine.c \
				thread_utils.c thread_event.c struct_free.c

OBJ_DIR		=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

RM			=	rm -f

all:			${NAME}

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} includes/philo.h
				$(CC) $(CFLAGS) $^ -o $@ -lpthread -fsanitize=thread

clean:
				${RM} -r ${OBJ_DIR}
				${RM} *.o

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re
