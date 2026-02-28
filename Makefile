NAME	= stegano

CC	= cc
FLAGS	= -Wall -Wextra -Werror

BLDD	= build

SRCS	= srcs/main.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))
INCS	= -I .
DEPS	= $(OBJS:.o=.d)

.PHONY: clean fclean re san

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(BLDD)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCS) -MMD -c $< -o $@

-include $(DEPS)

san: FLAGS += -g -fsanitize=address,undefined,leak
san: all

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean:
	rm -rf $(BLDD)

fclean: clean
	rm -rf $(NAME)

re: fclean all
