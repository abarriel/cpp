# Contact
NAME = ft_retro

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic-errors -lncurses

SRCS = \
main.cpp \
class/Game.cpp \
class/AEntity.cpp \
class/Bullet.cpp \
class/Enemy.cpp \
class/Player.cpp

OBJ = $(SRCS:%.cpp=./%.o)
all: $(NAME)

# %.o: %.cpp
# 	@$(CC) $(FLAGS) -o $@ -c $<
# 	@echo "\033[32m$@ done\033[0m"

$(NAME): $(SRCS)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I header
	@echo "\033[33m$(NAME) done\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[0m\033[35mobject files removed\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0m\033[32m$(NAME) removed\033[0m"

re: fclean all

.PHONY: all clean fclean re $(NAME)
