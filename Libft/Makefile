SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
NAME	= libft.a

all_m: $(NAME) $(OBJS)

all: all_m

make bonus_m: $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)
	touch $@

bonus: bonus_m all_m

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	touch $@

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I includes

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -f bonus_m all_m

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re