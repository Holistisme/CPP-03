/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-03/ex02/FragTrap/FragTrap.cpp                 *
*                    Creation Date: January 29, 2025 12:36 PM                    *
*                    Last Updated: January 29, 2025 03:23 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      Robot functions that love highfives                       *
*********************************************************************************/

#include "./FragTrap.hpp"
#include "./../output.hpp"

/********************************************************************************/

FragTrap::FragTrap(const std::string &name, const std::string &color) : ClapTrap(name, color), _highFivesRequest(false) {
	std::cout << getColoredName() << RESET << ": \"BOOM! I'm here, and I'm ready to HIGH FIVE EVERYONE!\" (" << CYAN << this << RESET << ")" << std::endl;
	setHitPoints(100); setEnergyPoints(100); setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &original)						  : ClapTrap(original), _highFivesRequest(false) {
	std::cout << getColoredName() << RESET << ": \"WAIT. I HAVE A TWIN?! Double the fun, double the high fives!\" (" << CYAN << this << RESET << ")" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << getColoredName() << RESET << ": \"NOOO! My high fives... unfinished... Tell them... I was awesome...!\" (" << CYAN << this << RESET << ")" << std::endl;
}

/********************************************************************************/

void FragTrap::_switchHighFivesRequest(void)	{ _highFivesRequest = !_highFivesRequest; }
bool FragTrap::_getHighFivesRequest(void) const { return _highFivesRequest; }

void FragTrap::highFivesGuys(void) {
	const std::string request[5] = {
		"Hey guys, let's celebrate with a HIGH FIVE! 🖐️",
		"Come on, someone give me a high five! I deserve it! 🖐️",
		"This is your lucky day! You get to high five a superior FragTrap! 🖐️",
		"Warning: High five requested! Immediate compliance required! 🖐️",
		"A high five a day keeps the sadness away! Who’s first? 🖐️"
	};

	std::cout << getColoredName() << RESET << ": \"" << request[std::rand() % 5] << "\"" << std::endl;
	if (!_getHighFivesRequest())
		_switchHighFivesRequest();
}

void FragTrap::highFivesSended(const std::string &input) {
	std::string responses[6] = {
		"YEAH! That was the best high five ever!",
		"Oh. My. God. You ACTUALLY high-fived me?! I'm not crying, you're crying!",
		"Wait… You gave me a high five? That… never happens. I think I love you.",
		"A HIGH FIVE! FINALLY! I HAVE ACHIEVED MY LIFE'S PURPOSE!",
		"That was so good! Again! Again! MORE HIGH FIVES!",
		"A high five from you?! Wow, I must be the luckiest robot alive!"
	};

	if (input.find("🖐️") != std::string::npos and _getHighFivesRequest()) {
		std::cout << getColoredName() << RESET << ": \"" << responses[std::rand() % 6] << "\"\n" << std::endl;
		_switchHighFivesRequest();
	}
}