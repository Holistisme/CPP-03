##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-03/ex00/Makefile                         #
#                   Creation Date: January 25, 2025 12:49 PM                     #
#                    Last Updated: January 27, 2025 16:52 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= OPEN!

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

CLAPTRAP	= ./ClapTrap
UTILITIES	= ./utilities

SOURCE		= main.cpp					  \
			$(CLAPTRAP)/ClapTrap.cpp	  \
			$(CLAPTRAP)/createClap.cpp	  \
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