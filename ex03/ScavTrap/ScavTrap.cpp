/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-03/ex03/ScavTrap/ScavTrap.cpp                 *
*                    Creation Date: January 29, 2025 11:18 AM                    *
*                    Last Updated: January 29, 2025 18:49 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      The functions of the ScavTrap class                       *
*********************************************************************************/

#include	"./ScavTrap.hpp"
#include	"./../output.hpp"

/********************************************************************************/

ScavTrap::ScavTrap(const std::string &name, const std::string &color) : ClapTrap(name, color), _gatekeeperMode(false) {
	setHitPoints(100); setEnergyPoints(50); setAttackDamage(20);
	std::cout << getColoredName() << RESET << ": \"Fortress mode: ONLINE. Nobody gets past me!\" (" << CYAN << this << RESET << ")" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original)						  : ClapTrap(original), _gatekeeperMode(false) {
	std::cout << getColoredName() << RESET << ": \"Copying initiated... Wait, does this mean I have a twin? Oh, this is gonna be good!\" (" << CYAN << this << RESET << ")" << std::endl;
}

void ScavTrap::attack(const std::string	&target) {
	if (!checkEnergy())	return;

	editEnergyPoints(-1);
	if (getGateKeeperMode()) {
		std::cout << getColoredName() << RESET << ": \"INTRUDER ALERT! " << target 
			<< ", you shall not pass! Prepare for a reinforced attack!\"" << std::endl;
		std::cout << getColoredName() << RESET << ": [🛡️ ] \"Deploying enhanced security protocol... BOOM! " 
			<< getAttackDamage() << " damage delivered!\" [🛡️ ]" << std::endl;
	}
	else
		std::cout << getColoredName() << RESET << ": \"" << target << ", take this! That's "
			<< getAttackDamage() << " points of pure ScavTrap awesomeness!\"" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << getColoredName() << RESET << ": \"Noooo! Tell ClapTrap I... was... better... than him...!\" (" << CYAN << this << RESET << ")" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (!getGateKeeperMode()) {
		_setGateKeeperMode();
        std::cout << getColoredName() << RESET << ": \"Gatekeeper mode activated! Nobody gets through!\"" << std::endl;
	}
	else
		std::cout << getColoredName() << RESET << ": \"I'm already in Gatekeeper mode. No double guarding needed!\"" << std::endl;
}

void ScavTrap::_setGateKeeperMode()	   { _gatekeeperMode = true; }
bool ScavTrap::getGateKeeperMode(void) { return _gatekeeperMode; }