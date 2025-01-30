/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-03/ex00/main.cpp                        *
*                    Creation Date: January 25, 2025 12:51 PM                    *
*                    Last Updated: January 27, 2025 02:02 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                             The main test program                              *
*********************************************************************************/

#include	"./main.hpp"

/********************************************************************************/

static void	playWithClapTrap(ClapTrap &clapTrap);

/********************************************************************************/

/**
 * @brief The project test program.
 * 
 * @return int The exit code.
 */
int	main(void) {
	try {
		ClapTrap some;
		std::cout << "\n🤖 Welcome to " << PROGRAM << RESET << "! 🤖\n" << std::endl;
		std::srand(std::time(0));

		ClapTrap	clapTrap = createNewClapTrap();
		playWithClapTrap(clapTrap);
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
 * @param clapTrap The Clap to play with.
 */
static void	playWithClapTrap(ClapTrap &clapTrap) {
	std::string	input = "";
	std::string	ennemies[] = {"Loader Bot", "EXP Loader",	   "GUN Loader",   "Badass Loader",
							  "ION Loader", "Constructor Bot", "Power Loader", "Surveyor",
							  "CL4P-TP",	"Mega Interplanetary Ninja Assassin Claptrap"};

	std::cout << '\n' << BG_YELLOW << "It's time to play!" << RESET << std::endl;
	do {
		std::cout << BG_BLUE  << "ATTACK" << RESET << " - To make some people undergo!"	<< std::endl;
		std::cout << BG_CYAN  << "DAMAGE" << RESET << " - To take damage itself!"		<< std::endl;
		std::cout << BG_GREEN << "REPAIR" << RESET << " - To recover health!" 			<< std::endl;
		std::cout << BG_RED   << "EXIT  " << RESET << " - To end the test!"				<< std::endl;
		input = getInputLine();
		std::cout << std::endl;
		if (sameString(input, "ATTACK"))
			clapTrap.attack(ennemies[rand() % 10]);
		else if (sameString(input, "DAMAGE"))
			clapTrap.takeDamage(rand() % 10);
		else if (sameString(input, "REPAIR"))
			clapTrap.beRepaired(rand() % 10);
		std::cout << std::endl;
		clapTrap.displayStatus();
	} while (!sameString(input, "EXIT") and clapTrap.getHitPoints() > 0);
}