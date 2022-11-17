NAME		=	philosophers

NAME_BONUS	=	philosophers_bonus

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS		=	philosophers.c philo_init.c philo_free.c \
				printing_philos.c philo_doing_things.c

SRCS_BONUS	=	philosophers_bonus.c

OBJ_DIR		=	obj

OBJ_DIR_B	=	obj_b

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_B)/,$(SRCS_BONUS:philosophers_bonus/%.c=%.o))

RM			=	rm -f

all:			${NAME}

bonus:			${NAME_BONUS}

$(OBJ_DIR)/%.o: %.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)/%.o: philosophers_bonus/%.c
				@mkdir -p $(OBJ_DIR_B)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} ${OBJ_CHANGES} philosophers.h
				$(CC) $(CFLAGS) $^ -o $@ -lpthread

${NAME_BONUS}:	${OBJ_BONUS} ${OBJ_CK_CHANGES} philosophers_bonus/philosophers_bonus.h
				$(CC) $(CFLAGS) $^ -o $@

clean:
				${RM} -r ${OBJ_DIR}
				${RM} -r ${OBJ_DIR_B}
				${RM} philosophers_bonus/*.o
				${RM} *.o

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY: 		all clean fclean re
