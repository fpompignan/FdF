
NAME = fdf

SRC = 	src/main.c						\
		src/utils.c						\
		src/utils2.c					\
		src/get_next_line.c				\
		src/get_next_line_utils.c		\
		src/map.c						\
		src/matrix.c					\
		src/ft_split.c


OBJ = $(SRC:.c=.o)

HEADER = fdf.h

WWW = -Wall -Werror -Wextra

FLAG1 = -I X11/include -g 

FLAG2 = -L lib -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

.c.o:
	gcc $(WWW)  -c $< -o $(<:.c=.o)


$(NAME): $(OBJ)	
		gcc $(WWW) $(FLAG2) -o $(NAME) $(OBJ)


clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
