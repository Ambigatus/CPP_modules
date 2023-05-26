NAME = zombie

SRC =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

HEADER = Zombie.hpp

OBJ = $(SRC:.cpp=.o)

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

GRN	=	"\033[32m"
END	=	"\033[00m"

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(CC) $(FLAGS) $(OBJ) -I. -o $(NAME)
			@echo $(GRN) "\tCompiled "$(NAME)" successfully!" $(END)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re test