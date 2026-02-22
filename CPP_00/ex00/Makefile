CX = c++
CXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp
OBJS = $(SRCS:.c=.o)

NAME = megaphone

%.o: %.c
	$(CX) $(CXFLAGS) -c $< -o $@

all: $(NAME)
	$(CX) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re