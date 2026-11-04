NAME	= RPN

CX		= c++
CXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp RPN.cpp
HEADERS	= RPN.hpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CX) $(CXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CX) $(CXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
