NAME = Zombie
HEADER = Zombie.hpp

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++
RM = rm -rf

SRC = main.cpp randomChump.cpp Zombie.cpp newZombie.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean