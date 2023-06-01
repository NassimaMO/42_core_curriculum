NAME		=	philo_bonus

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS_DIR	=	srcs

SRCS		=	main.c verif.c data_init.c routine.c \
				utils.c event.c

OBJ_DIR		=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

RM			=	rm -f

all:			${NAME}

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} includes/philo_lib.h
				$(CC) $(CFLAGS) $^ -o $@ -lpthread
#-fsanitize=thread

clean:
				${RM} -r ${OBJ_DIR}
				${RM} *.o

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY: 		all clean fclean re
