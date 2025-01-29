/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-03/ex02/FragTrap/createFrag.cpp                *
*                    Creation Date: January 29, 2025 11:18 AM                    *
*                    Last Updated: January 29, 2025 03:21 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           Functions to test FragTrap                           *
*********************************************************************************/

#include	"./../main.hpp"

/********************************************************************************/

static inline std::string askName(void);
static inline std::string askColor(void);
static void				  changeFragTrap(FragTrap &current);

/********************************************************************************/

/**
 * @brief Create a New FragTrap object.
 * 
 * @return FragTrap The new FragTrap.
 */
FragTrap createNewFragTrap(void) {
	std::cout << "Let's create a " << BG_YELLOW << "FragTrap" << RESET << "!\n" << std::endl;
	FragTrap newFragTrap(askName(), askColor()); changeFragTrap(newFragTrap);
	return newFragTrap;
}

/**
 * @brief Asks for a new name for FragTrap.
 * 
 * @return std::string The name entered by the user.
 */
static inline std::string askName(void) {
	std::cout << "What is the name given to this magnificent " << BG_YELLOW << "FragTrap" << RESET << "?" << std::endl;
	std::string input = getInputLine();
	return !input.empty() ? input : "An unknown robot";
}

/**
 * @brief Asks for a new color for FragTrap.
 * 
 * @return std::string The color entered by the user.
 */
static inline std::string askColor(void) {
	const std::string colors[] = {"BLACK", "RED", "GREEN", "YELLOW", "BLUE", "MAGENTA",	"CYAN",	"WHITE"};
	const std::string ansii[]  = { BLACK, 	RED,   GREEN,	YELLOW,	  BLUE,	  MAGENTA,	 CYAN,	 WHITE};

	std::cout << "Do you want to assign a " << ansii[rand() % 8] << "color" << RESET << " to it?" << std::endl;
	std::string	input = getInputLine();
	for (index i = 0 ; i < 8 ; i++)
		if (sameString(input, colors[i]))
			return ansii[i];
	std::cout << std::endl;

	return ansii[rand() % 8];
}

/**
 * @brief Offers the user to test constructors and operators.
 * 
 * @param current The original FragTrap.
 */
static void changeFragTrap(FragTrap &current) {
	std::cout << std::endl;
	std::cout << BG_RED	   << "Maybe this FragTrap was an error?" << RESET														 << std::endl;
	std::cout << BG_GREEN  << "CONFIRM   "						  << RESET << " - To keep this FragTrap!"						 << std::endl;
	std::cout << BG_BLUE   << "COPY      "						  << RESET << " - To copy this FragTrap before abandoning it!"   << std::endl;
	std::cout << BG_YELLOW << "ASSIGNMENT"						  << RESET << " - To assign this FragTrap before abandoning it!" << std::endl;
	
	std::string	input = getInputLine();
	if (sameString(input, "COPY"))
		current = FragTrap(current);
	else if (sameString(input, "ASSIGNMENT"))
		current = FragTrap("New high-end FragTrap", YELLOW);
	else if (!sameString(input, "CONFIRM"))
		changeFragTrap(current);
}