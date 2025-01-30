/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-03/ex02/ClapTrap/ClapTrap.cpp                  *
*                    Creation Date: January 25, 2025 12:51 PM                    *
*                    Last Updated: January 29, 2025 12:17 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                       All the functions of the ClapTrap                        *
*********************************************************************************/

#include	"./ClapTrap.hpp"
#include	"./../output.hpp"

/********************************************************************************/

ClapTrap::ClapTrap(void) :  _name("An unknown ClapTrap"), _color(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Call for the constructor of a ClapTrap named " << getColoredName() << RESET << " (" << CYAN << this << RESET << ")" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const std::string &color) : _name(name), _color(color), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << getColoredName() << RESET << ": \"Look out everybody! Things are about to get awesome!\" (" << CYAN << this << RESET << ")" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)						  : _name(original.getName()), _color(original.getColor()), _hitPoints(original.getHitPoints()), _energyPoints(original.getEnergyPoints()), _attackDamage(original.getAttackDamage()) {
	std::cout << getColoredName() << RESET << ": \"A copy of me? Oh, great! Twice the fun!\" (" << CYAN << this << RESET << ")" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &original) {
	if (this != &original) {
		std::cout << getColoredName() << RESET << ": \"Wait, I'm turning into " << original.getName() << "? This is... exciting!\" (" << CYAN << this << RESET << ")" << std::endl;
		setName(original.getName());
		setColor(original.getColor());
		setHitPoints(original.getHitPoints());
		setEnergyPoints(original.getEnergyPoints());
		setAttackDamage(original.getAttackDamage());
	}
	else
		std::cout << getColoredName() << RESET << ": \"Wait... I'm assigning myself to myself? That's... weird, but okay!\" (" << CYAN << this << RESET << ")" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << getColoredName() << RESET << ": \"Oh no! I'm dying... but I regret nothing!\" (" << CYAN << this << RESET << ")" << std::endl;
}

bool	ClapTrap::checkEnergy(void) const { return (getEnergyPoints() <= 0 ? std::cout << getColoredName() << RESET << ": \"No energy?! This is the end... Tell my motherboard I love her!\"" << std::endl, false : true); }

/********************************************************************************/

void ClapTrap::setName(const std::string &name)			   { _name		   = name;	 }
void ClapTrap::setColor(const std::string &color)		   { _color		   = color;	 }
void ClapTrap::setHitPoints(const unsigned int &amount)	   { _hitPoints	   = amount; }
void ClapTrap::setEnergyPoints(const unsigned int &amount) { _energyPoints = amount; }
void ClapTrap::setAttackDamage(const unsigned int &amount) { _attackDamage = amount; }

std::string	ClapTrap::getName(void)			const { return  _name;				   }
std::string	ClapTrap::getColor(void)		const { return _color;				   }
std::string	ClapTrap::getColoredName(void)	const { return getColor() + getName(); }
int			ClapTrap::getHitPoints(void)	const { return _hitPoints;			   }
int			ClapTrap::getEnergyPoints(void) const { return _energyPoints;		   }
int			ClapTrap::getAttackDamage(void) const { return _attackDamage;		   }

void ClapTrap::editHitPoints(const int &amount)	   { setHitPoints(getHitPoints()	   + amount); }
void ClapTrap::editEnergyPoints(const int &amount) { setEnergyPoints(getEnergyPoints() + amount); }
void ClapTrap::editAttackDamage(const int &amount) { setAttackDamage(getAttackDamage() + amount); }

/********************************************************************************/

void	ClapTrap::attack(const std::string &name) {
	if (!checkEnergy())	return;

	editEnergyPoints(-1);
	std::cout << getColoredName() << RESET << ": \"Take this, " << name << "! Boom! " << getAttackDamage() << " damage delivered!\"" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	editHitPoints(-amount);
	std::cout << getColoredName() << RESET << ": \"Ow! I just took " << amount		   << " damage! This is not what I signed up for!\"" << std::endl;
	std::cout << getColoredName() << RESET << ": \"Current health: " << getHitPoints() << " HP. Someone call a medic!\""				 << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!checkEnergy())	return;

	editHitPoints(amount);
	editEnergyPoints(-1);
	std::cout << getColoredName() << RESET << ": \"Ahh, much better! Restored "	<< amount		  << " hit points. Who's awesome? I'm awesome!\"" << std::endl;
	std::cout << getColoredName() << RESET << ": \"Current health: "			<< getHitPoints() << " HP. I'm back in the game, baby!\""		  << std::endl;
}

void ClapTrap::displayStatus(void) {
	std::cout << getColoredName() 					   << RESET <<	" is currently to:"	<< std::endl;
	std::cout << " ♥ - " << GREEN << getHitPoints()	   << RESET << " Hit Points."		<< std::endl;
	std::cout << "🔋 - " << BLUE  << getEnergyPoints() << RESET << " Energy Points."	<< std::endl;
	std::cout << " ⚔ - " << RED   << getAttackDamage() << RESET << " Attack Damage.\n"	<< std::endl;
}