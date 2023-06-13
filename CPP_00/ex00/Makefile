NAME = megaphone

CC = c++

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
YELLOW='\033[33m'
CURSIVE='\033[3m'

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	@echo $(GREEN)"- Compiled -"$(NONE)

clean:
	$(RM) $(OBJS) 
	@echo $(YELLOW)"- Removed object files -"$(NONE)

fclean: 
	$(RM) $(NAME) 
	@echo $(YELLOW)"- Removed megaphone's file -"$(NONE)

check_leaks: 
	leaks --atExit -- ./megaphone

re: fclean all

.PHONY: check_leaks all clean fclean re