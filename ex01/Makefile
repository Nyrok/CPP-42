CX = c++
CXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp utils.cpp Contact.cpp PhoneBook.cpp 
OBJS = $(SRCS:.cpp=.o)

NAME = phonebook

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