CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MD = mandatory
SRC = $(MD)/main.c\
		$(MD)/ft_error.c \
		$(MD)/parser.c \
		$(MD)/minilibft.c \
		$(MD)/ft_init.c \
		$(MD)/simulation.c \


INC = inc/philo.h
OBJ = $(SRC:.c=.o)


all: $(OBJ)
	$(CC) $(CFLAGS) -o philo $(OBJ)

$(OBJ): $(INC)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f philo
	rm -rf .vscode

re: fclean all

.PHONY: clean