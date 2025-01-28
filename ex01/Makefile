NAME		= Serenade

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

CLAPTRAP	= ./ClapTrap
SCAVTRAP	= ./ScavTrap
UTILITIES	= ./utilities

SOURCE		= main.cpp					  \
			$(CLAPTRAP)/ClapTrap.cpp	  \
			$(SCAVTRAP)/ScavTrap.cpp	  \
			$(SCAVTRAP)/createScav.cpp	  \
			$(UTILITIES)/getInputLine.cpp \
			$(UTILITIES)/sameString.cpp	  \
			$(UTILITIES)/trimSpaces.cpp	  \

OBJECTS		= $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re