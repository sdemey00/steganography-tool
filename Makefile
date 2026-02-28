NAME	= stegano

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++17

BLDD	= build

SRCS	= srcs/main.cpp
OBJS	= $(patsubst %.cpp, $(BLDD)/%.o, $(SRCS))
INCS	= -I .
DEPS	= $(OBJS:.o=.d)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $@

$(BLDD)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(BLDD)

fclean: clean
	rm -rf $(NAME)

re: fclean all
