NAME = mutantStack

SRC =		main.cpp \
		
HEADER = 	MutantStack.hpp \
			MutantStack.tpp \
			

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

GRN	=	"\033[32m"
END	=	"\033[00m"

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
			$(CXX) $(CXXFLAGS) $(OBJ) -I. -o $(NAME)
			@echo $(GRN) "\tCompiled "$(NAME)" successfully!" $(END)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re test