NAME		=	pipex

NAME_BONUS	=	pipex_b

LIB			=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

SRCS		=	pipex.c pipex_envp.c pipex_process.c

SRCS_BONUS	=	pipex_bonus/pipex_bonus.c pipex_bonus/pipex_process_bonus.c \
				pipex_bonus/pipex_envp_bonus.c pipex_bonus/pipex_heredoc_bonus.c

OBJ_DIR		=	obj

OBJ_DIR_B	=	obj

OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRCS:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_B)/,$(SRCS_BONUS:pipex_bonus/%.c=%.o))

RM			=	rm -f

all:			${NAME} 

bonus:			${NAME_BONUS}

$(OBJ_DIR)/%.o: %.c
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)/%.o: pipex_bonus/%.c
				@mkdir -p $(OBJ_DIR_B)
				$(CC) $(CFLAGS) -c $< -o $@

${NAME}:		${OBJ} ${LIB} pipex.h
				$(CC) $(CFLAGS) $^ -o $@ -L. -lft

${NAME_BONUS}:	${OBJ_BONUS} ${LIB} pipex_bonus/pipex_bonus.h
				$(CC) $(CFLAGS) $^ -o $@ -L. -lft

${LIB}:
				cd libft && make && mv $@ .. && cd ..
clean:
				cd libft && make fclean && cd ..
				${RM} ${LIB}
				${RM} -r ${OBJ_DIR}
				${RM} pipex_bonus/*.o
				${RM} *.o

fclean:			clean
				${RM} ${NAME} ${NAME_BONUS}

re:				fclean all

.PHONY: 		all clean fclean re
