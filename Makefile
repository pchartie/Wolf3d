NAME = wolf3d

SRC = ./main.c \
	./color.c \
	./event.c \
	./load_texture.c \
	./wolf_algo.c \
	./bonus.c \
	./texture.c \
	./map.c \
	./event2.c 

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

INC = -I./libft/

CC = gcc -Wall -Wextra -g

RM = rm -f

HD = wolf3d.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/ -j 8
	make -C minilibx_macos/ -j 8
	$(CC) -o $(NAME) $(OBJS) $(LIB)

%.o: %.c $(HD)
	$(CC) -c $< $(INC)

clean:
	$(RM) $(OBJS)
	make clean -C libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all
