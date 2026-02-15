NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	parsing.c \
	free.c \
	swap.c \
	push.c \
	rotations.c \
	reverse_rotations.c \
	utils.c \
	indexing.c \
	small.c \
	sort_chunk.c \
       split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
