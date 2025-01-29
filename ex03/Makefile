##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-03/ex03/Makefile                         #
#                   Creation Date: January 25, 2025 12:49 PM                     #
#                    Last Updated: January 29, 2025 18:49 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= Now_it’s_weird!

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wshadow

CLAPTRAP	= ./ClapTrap
DIAMONDTRAP	= ./DiamondTrap
FRAGTRAP	= ./FragTrap
SCAVTRAP	= ./ScavTrap
UTILITIES	= ./utilities

SOURCE		= main.cpp						 \
			$(CLAPTRAP)/ClapTrap.cpp		 \
			$(DIAMONDTRAP)/DiamondTrap.cpp	 \
			$(DIAMONDTRAP)/createDiamond.cpp \
			$(FRAGTRAP)/FragTrap.cpp		 \
			$(SCAVTRAP)/ScavTrap.cpp		 \
			$(UTILITIES)/getInputLine.cpp 	 \
			$(UTILITIES)/sameString.cpp		 \
			$(UTILITIES)/trimSpaces.cpp		 \

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