CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	ft_mini_ls
SRCS	=	ft_mini_ls.c \
			tools.c
OBJS	=	$(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
			rm -f *.o

fclean		: clean
			rm -f $(NAME)

re			: fclean all