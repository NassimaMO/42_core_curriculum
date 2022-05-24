NAME			= libftprintf.a

CFLAGS			= -Wall -Wextra -Werror -c

CC				= gcc

SRCS			= ft_printf.c ft_putnbr_base.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c

OBJS			= $(SRCS:.c=.o)



all:			$(NAME)

$(NAME):		$(OBJS)
	ar crs $@ $(OBJS)

%.o:			%.c
	$(CC) $(CFLAGS) $< -o $@

bonus:			$(NAME)

clean:
	rm -rf $(OBJS) libft/$(OBJS)

fclean:			clean
	rm -f $(NAME)

re:				fclean all