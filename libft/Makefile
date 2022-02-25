CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -g
NAME = libft.a

src =\
	./ft_strnstr.c \
	./ft_isdigit.c \
	./ft_lstadd_back.c \
	./ft_putstr_fd.c \
	./ft_lstnew.c \
	./ft_strlcpy.c \
	./ft_strlen.c \
	./ft_lstlast.c \
	./ft_memcmp.c \
	./ft_putnbr_fd.c \
	./ft_lstclear.c \
	./ft_lstiter.c \
	./ft_strchr.c \
	./ft_bzero.c \
	./ft_strjoin.c \
	./ft_isascii.c \
	./ft_memcpy.c \
	./ft_memccpy.c \
	./ft_isprint.c \
	./ft_putendl_fd.c \
	./ft_lstmap.c \
	./ft_lstsize.c \
	./ft_toupper.c \
	./ft_split.c \
	./ft_lstadd_front.c \
	./ft_strrchr.c \
	./ft_isalpha.c \
	./ft_memchr.c \
	./ft_putchar_fd.c \
	./ft_memset.c \
	./ft_substr.c \
	./ft_strncmp.c \
	./ft_strmapi.c \
	./ft_strtrim.c \
	./ft_memmove.c \
	./ft_strlcat.c \
	./ft_calloc.c \
	./ft_strdup.c \
	./ft_atoi.c \
	./ft_isalnum.c \
	./ft_lstdelone.c \
	./ft_itoa.c \
	./ft_tolower.c \

.PHONY: all clean fclean re

all: $(NAME)

obj = $(src:%.c=%.o)

$(NAME): $(obj)
	$(AR) -rc $(NAME) $(obj)
	ranlib $(NAME)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all
