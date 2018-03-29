# eval_ep
NAME = eval_expr

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = \
Fixed.class.cpp \
main.cpp \

OBJ = $(SRCS:%.cpp=./%.o)
all: $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "\033[32m$@ done\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)
	@echo "\033[33m$(NAME) done\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[0m\033[35mobject files removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0m\033[32m$(NAME) removed\033[0m"

re: fclean all

.PHONY: all clean fclean re $(NAME)
