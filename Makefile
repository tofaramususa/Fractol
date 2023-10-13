NAME:= fractol 
SRCS =  main.c man_handler.c Mandelbrot.c julia.c julia_handlers.c utils.c 
OBJ = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
LDFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
HEADER = fractol.h

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean