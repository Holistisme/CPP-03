/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-03/ex03/main.cpp                        *
*                    Creation Date: January 29, 2025 11:18 AM                    *
*                    Last Updated: January 29, 2025 18:49 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                    The main program to test the inheritance                    *
*********************************************************************************/


#include	"./main.hpp"

/********************************************************************************/

static void	playWithDiamondTrap(DiamondTrap &DiamondTrap);

/********************************************************************************/

/**
 * @brief The project test program.
 * 
 * @return int The exit code.
 */
int main(void) {
	try {
		std::cout << "\n🤖 Welcome to " << PROGRAM << RESET << "! 🤖\n" << std::endl;
		std::srand(std::time(0));

		DiamondTrap	DiamondTrap = createNewDiamondTrap();
		playWithDiamondTrap(DiamondTrap);
		std::cout << EXIT_MESSAGE << std::endl << std::endl;
		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}

/**
 * @brief Allows you to interact with a CLAP until his death or this of the envy of the user.
 * 
 * @param DiamondTrap The Clap to play with.
 */
static void playWithDiamondTrap(DiamondTrap &diamondTrap) {
	std::string input = "";
	std::string ennemies[] = {"Loader Bot", "EXP Loader",	   "GUN Loader",   "Badass Loader",
							  "ION Loader", "Constructor Bot", "Power Loader", "Surveyor",
							  "CL4P-TP",	"Mega Interplanetary Ninja Assassin ScavTrap"};

	std::cout << '\n' << BG_YELLOW << "It's time to play!" << RESET << std::endl;
	do {
		std::cout << BG_BLUE				  << "ATTACK   " << RESET << " - To make some people undergo!"				  << std::endl;
		std::cout << BG_CYAN				  << "DAMAGE   " << RESET << " - To take damage itself!"					  << std::endl;
		std::cout << BG_GREEN				  << "REPAIR   " << RESET << " - To recover health!" 						  << std::endl;
		std::cout << BG_BLACK				  << "GUARD    " << RESET << " - To enter Guardgate mode!"					  << std::endl;
		std::cout << BG_MAGENTA				  << "HIGHFIVES" << RESET << " - To turn on DiamondTrap on these high fives!" << std::endl;
		std::cout << READABLE_BG_BRIGHT_WHITE << "WHOAMI   " << RESET << " - To find memory!"							  << std::endl;
		std::cout << BG_RED					  << "EXIT     " << RESET << " - To end the test!"							  << std::endl;
		
		input = getInputLine();
		std::cout << std::endl;

		diamondTrap.highFivesSended(input);
		if (sameString(input, "ATTACK"))
			diamondTrap.attack(ennemies[rand() % 10]);
		else if (sameString(input, "DAMAGE"))
			diamondTrap.takeDamage(rand() % 10);
		else if (sameString(input, "REPAIR"))
			diamondTrap.beRepaired(rand() % 10);
		else if (sameString(input, "GUARD"))
			diamondTrap.guardGate();
		else if (sameString(input, "HIGHFIVES"))
			diamondTrap.highFivesGuys();
		else if (sameString(input, "WHOAMI"))
			diamondTrap.whoAmI();
		else
			continue;
		std::cout << std::endl;
		diamondTrap.displayStatus();
	} while (!sameString(input, "EXIT") and diamondTrap.getHitPoints() > 0);
}