NAME = libftprintf.a

SRCS = ft_printf.c	\
	   ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(CFLAGS) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re:	clean all

.PHONY: all clean fclean re
