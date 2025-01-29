/*********************************************************************************
*                              Author: Alexy Heitz                               *
*              File Name: /CPP-03/ex03/DiamondTrap/createDiamond.cpp             *
*                    Creation Date: January 29, 2025 03:27 PM                    *
*                    Last Updated: January 29, 2025 06:48 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                       Tests to verify that horror works                        *
*********************************************************************************/

#include	"./../main.hpp"

/********************************************************************************/

static inline std::string askName(void);
static inline std::string askColor(void);
static void				  changeDiamondTrap(DiamondTrap &current);

/********************************************************************************/

/**
 * @brief Create a New DiamondTrap object.
 * 
 * @return DiamondTrap The new DiamondTrap.
 */
DiamondTrap createNewDiamondTrap(void) {
	std::cout << "Let's create a " << BG_YELLOW << "DiamondTrap" << RESET << "!\n" << std::endl;
	DiamondTrap newDiamondTrap(askName(), askColor()); changeDiamondTrap(newDiamondTrap);
	return newDiamondTrap;
}

/**
 * @brief Asks for a new name for DiamondTrap.
 * 
 * @return std::string The name entered by the user.
 */
static inline std::string askName(void) {
	std::cout << "What is the name given to this magnificent " << BG_YELLOW << "DiamondTrap" << RESET << "?" << std::endl;
	std::string input = getInputLine();
	return !input.empty() ? input : "An unknown robot";
}

/**
 * @brief Asks for a new color for DiamondTrap.
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
 * @param current The original DiamondTrap.
 */
static void changeDiamondTrap(DiamondTrap &current) {
	std::cout << std::endl;
	std::cout << BG_RED	   << "Maybe this DiamondTrap was an error?" << RESET														<< std::endl;
	std::cout << BG_GREEN  << "CONFIRM   "						  << RESET << " - To keep this DiamondTrap!"						<< std::endl;
	std::cout << BG_BLUE   << "COPY      "						  << RESET << " - To copy this DiamondTrap before abandoning it!"   << std::endl;
	std::cout << BG_YELLOW << "ASSIGNMENT"						  << RESET << " - To assign this DiamondTrap before abandoning it!" << std::endl;
	
	std::string	input = getInputLine();
	if (sameString(input, "COPY"))
		current = DiamondTrap(current);
	else if (sameString(input, "ASSIGNMENT"))
		current = DiamondTrap("New high-end DiamondTrap", YELLOW);
	else if (!sameString(input, "CONFIRM"))
		changeDiamondTrap(current);
}