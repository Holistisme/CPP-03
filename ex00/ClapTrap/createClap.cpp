/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-03/ex00/ClapTrap/createClap.cpp                 *
*                    Creation Date: January 27, 2025 12:15 PM                    *
*                    Last Updated: January 27, 2025 12:22 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                 Allows user to dynamically create a ClapTrap                   *
*********************************************************************************/

#include	"./../main.hpp"

/********************************************************************************/

static inline std::string	askName(void);
static inline std::string	askColor(void);
static void					changeClapTrap(ClapTrap &current);

/********************************************************************************/

/**
 * @brief Create a New Clap Trap object.
 * 
 * @return ClapTrap The new ClapTrap.
 */
ClapTrap	createNewClapTrap(void) {
	std::cout << "Let's create a " << BG_YELLOW << "ClapTrap" << RESET << "!\n" << std::endl;

	ClapTrap	newClapTrap(askName(), askColor()); changeClapTrap(newClapTrap);
	return newClapTrap;
}

/**
 * @brief Asks for a new name for ClapTrap.
 * 
 * @return std::string The name entered by the user.
 */
static inline std::string	askName(void) {
	std::cout << "What is the name given to this magnificent " << BG_YELLOW << "ClapTrap" << RESET << "?" << std::endl;

	std::string	input = getInputLine();
	return !input.empty() ? input : "An unknown ClapTrap";
}

/**
 * @brief Asks for a new color for ClapTrap.
 * 
 * @return std::string The color entered by the user.
 */
static inline std::string	askColor(void) {
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
 * @param current The original ClapTrap.
 */
static void	changeClapTrap(ClapTrap &current) {
	std::cout << std::endl;
	std::cout << BG_RED	   << "Maybe this claptrap was an error?" << RESET														 << std::endl;
	std::cout << BG_GREEN  << "CONFIRM   "						  << RESET << " - To keep this ClapTrap!"						 << std::endl;
	std::cout << BG_BLUE   << "COPY      "						  << RESET << " - To copy this ClapTrap before abandoning it!"   << std::endl;
	std::cout << BG_YELLOW << "ASSIGNMENT"						  << RESET << " - To assign this Claptrap before abandoning it!" << std::endl;
	std::string	input = getInputLine();

	if (sameString(input, "COPY"))
		current = ClapTrap(current);
	else if (sameString(input, "ASSIGNMENT"))
		current = ClapTrap("New high-end ClapTrap", YELLOW);
	else if (!sameString(input, "CONFIRM"))
		changeClapTrap(current);
}