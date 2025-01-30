/*********************************************************************************
*                              Author: Alexy Heitz                               *
*               File Name: /CPP-03/ex03/DiamondTrap/DiamondTrap.cpp              *
*                    Creation Date: January 29, 2025 03:47 PM                    *
*                    Last Updated: January 29, 2025 06:47 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The internal functions of this horror                      *
*********************************************************************************/

#include "./DiamondTrap.hpp"
#include "./../output.hpp"

/********************************************************************************/

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), _name("An unknown DiamondTrap") {
	std::cout << "Call for the constructor of a DiamondTrap named " << getColoredName() << RESET << " (" << CYAN << this << RESET << ")" << std::endl;
	ClapTrap::setName("An unknown DiamondTrap_clap_name");
	setHitPoints(FragTrap::_personalHitPoints);
	setEnergyPoints(ScavTrap::_personalEnergyPoints);
	setAttackDamage(FragTrap::_personalAttackDamage);
}

DiamondTrap::DiamondTrap(const std::string &name, const std::string &color) : ClapTrap(name + "_clap_name", color), ScavTrap(name, color), FragTrap(name, color), _name(name) {
	std::cout << "Call for the constructor on a DiamondTrap named " << getColoredName() << " (" << CYAN << this << RESET << ")" << std::endl;
	setHitPoints(FragTrap::_personalHitPoints);
	setEnergyPoints(ScavTrap::_personalEnergyPoints);
	setAttackDamage(FragTrap::_personalAttackDamage);
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original), ScavTrap(original), FragTrap(original), _name(original.getName()) {
	std::cout << "Call for the copy constructor on a DiamondTrap named " << getColoredName() << " (" << CYAN << this << RESET << ")" << std::endl;
	ClapTrap::setName(_name + "_clap_name");
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &original) {
	std::cout << "Call for the assignment operator of a DiamondTrap named " << getColoredName() << RESET << " (" << CYAN << this << RESET << ")" << std::endl;
	if (this != &original) {
		_name = original._name;
		setColor(original.getColor());
		setHitPoints(original.getHitPoints());
		setEnergyPoints(original.getEnergyPoints());
		setAttackDamage(original.getAttackDamage());
		ClapTrap::setName(_name + "_clap_name");
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Call for the destructor on a DiamondTrap named " << getColoredName() << " (" << CYAN << this << RESET << ")" << std::endl;
}

void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI(void) {
	std::cout << "I'm " << getColoredName() << ", but... but... am I also " << ClapTrap::getColoredName() << RESET
		<< "?! WHO AM I?! AM I REAL?! Is this a simulation?!" << std::endl;
}

std::string	DiamondTrap::getName(void)		  const { return _name;							 }
std::string	DiamondTrap::getColoredName(void) const { return getColor() + getName() + RESET; }