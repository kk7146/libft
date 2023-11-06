SRCS = get_next_line.c get_next_line_utils.c
OBJC = $(SRCS:.c=.o)
NAME = a.out
FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJC)
	gcc -g $(OBJC)

clean:
			rm -f $(OBJC)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
