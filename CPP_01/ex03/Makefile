CX = c++
CXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = violence

all: $(NAME)

%.o: %.cpp
	$(CX) $(CXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CX) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
