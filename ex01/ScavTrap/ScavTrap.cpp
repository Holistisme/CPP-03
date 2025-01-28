#include	"./ScavTrap.hpp"
#include	"./../output.hpp"

ScavTrap::ScavTrap(const std::string &name, const std::string &color) : ClapTrap(name, color) { setHitPoints(100); setEnergyPoints(50); setAttackDamage(20); }

ScavTrap::ScavTrap(const ScavTrap &original)						  : ClapTrap(original) {
	std::cout << getColoredName() << RESET << ": \"Copying initiated... Wait, does this mean I have a twin? Oh, this is gonna be good!\" (" << CYAN << this << RESET << ")" << std::endl;
}

void	ScavTrap::attack(const std::string	&target) {
	if (!checkEnergy())	return;

	editEnergyPoints(-1);
	std::cout << _name << ": \"" << target << ", take this! That's " << getAttackDamage() << " points of pure ScavTrap awesomeness!\" (" << CYAN << this << RESET << ")" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << getColoredName() << RESET << ": \"Noooo! Tell ClapTrap I... was... better... than him...!\" (" << CYAN << this << RESET << ")" << std::endl;
}

void	ScavTrap::guardGate(void) {
	if (!_gatekeeperMode) {
		_gatekeeperMode = true;
        std::cout << _name << ": \"Gatekeeper mode activated! Nobody gets through!\"" << std::endl;
	} else {
		std::cout << _name << ": \"I'm already in Gatekeeper mode. No double guarding needed!\"" << std::endl;
	}
}

void	ScavTrap::_setGateKeeperMode(const bool change) { _gatekeeperMode = change; }
bool	ScavTrap::_getGateKeeperMode(void)				{ return _gatekeeperMode; }