/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-03/ex01/main.cpp                        *
*                    Creation Date: January 29, 2025 11:18 AM                    *
*                    Last Updated: January 29, 2025 12:20 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                    The main program to test the inheritance                    *
*********************************************************************************/


#include	"./main.hpp"

/********************************************************************************/

static void	playWithScavTrap(ScavTrap &ScavTrap);

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

		ScavTrap	ScavTrap = createNewScavTrap();
		playWithScavTrap(ScavTrap);
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
 * @param ScavTrap The Clap to play with.
 */
static void playWithScavTrap(ScavTrap &ScavTrap) {
	std::string input = "";
	std::string ennemies[] = {"Loader Bot", "EXP Loader",	   "GUN Loader",   "Badass Loader",
							  "ION Loader", "Constructor Bot", "Power Loader", "Surveyor",
							  "CL4P-TP",	"Mega Interplanetary Ninja Assassin ScavTrap"};

	std::cout << '\n' << BG_YELLOW << "It's time to play!" << RESET << std::endl;
	do {
		std::cout << BG_BLUE	<< "ATTACK" << RESET << " - To make some people undergo!" << std::endl;
		std::cout << BG_CYAN	<< "DAMAGE" << RESET << " - To take damage itself!"		  << std::endl;
		std::cout << BG_GREEN	<< "REPAIR" << RESET << " - To recover health!" 		  << std::endl;
		std::cout << BG_MAGENTA	<< "GUARD " << RESET << " - To enter Guardgate mode!" 	  << std::endl;
		std::cout << BG_RED		<< "EXIT  " << RESET << " - To end the test!"			  << std::endl;
		input = getInputLine();
		std::cout << std::endl;
		if (sameString(input, "ATTACK"))
			ScavTrap.attack(ennemies[rand() % 10]);
		else if (sameString(input, "DAMAGE"))
			ScavTrap.takeDamage(rand() % 10);
		else if (sameString(input, "REPAIR"))
			ScavTrap.beRepaired(rand() % 10);
		else if (sameString(input, "GUARD"))
			ScavTrap.guardGate();
		std::cout << std::endl;
		ScavTrap.displayStatus();
	} while (!sameString(input, "EXIT") and ScavTrap.getHitPoints() > 0);
}