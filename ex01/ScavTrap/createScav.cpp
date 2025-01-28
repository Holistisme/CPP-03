#include	"./../main.hpp"

/********************************************************************************/

static inline std::string	askName(void);
static inline std::string	askColor(void);
static void					changeScavTrap(ScavTrap &current);

/********************************************************************************/

/**
 * @brief Create a New ScavTrap object.
 * 
 * @return ScavTrap The new ScavTrap.
 */
ScavTrap	createNewScavTrap(void) {
	std::cout << "Let's create a " << BG_YELLOW << "ScavTrap" << RESET << "!\n" << std::endl;

	ScavTrap	newScavTrap(askName(), askColor()); changeScavTrap(newScavTrap);
	return newScavTrap;
}

/**
 * @brief Asks for a new name for ScavTrap.
 * 
 * @return std::string The name entered by the user.
 */
static inline std::string	askName(void) {
	std::cout << "What is the name given to this magnificent " << BG_YELLOW << "ScavTrap" << RESET << "?" << std::endl;

	std::string	input = getInputLine();
	return !input.empty() ? input : "An unknown robot";
}

/**
 * @brief Asks for a new color for ScavTrap.
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
 * @param current The original ScavTrap.
 */
static void	changeScavTrap(ScavTrap &current) {
	std::cout << std::endl;
	std::cout << BG_RED	   << "Maybe this ScavTrap was an error?" << RESET														 << std::endl;
	std::cout << BG_GREEN  << "CONFIRM   "						  << RESET << " - To keep this ScavTrap!"						 << std::endl;
	std::cout << BG_BLUE   << "COPY      "						  << RESET << " - To copy this ScavTrap before abandoning it!"   << std::endl;
	std::cout << BG_YELLOW << "ASSIGNMENT"						  << RESET << " - To assign this ScavTrap before abandoning it!" << std::endl;
	std::string	input = getInputLine();

	if (sameString(input, "COPY"))
		current = ScavTrap(current);
	else if (sameString(input, "ASSIGNMENT"))
		current = ScavTrap("New high-end ScavTrap", YELLOW);
	else if (!sameString(input, "CONFIRM"))
		changeScavTrap(current);
}