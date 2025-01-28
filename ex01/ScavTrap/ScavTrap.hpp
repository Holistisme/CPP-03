#pragma	once

#include	"./../ClapTrap/ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	private:
		bool	_gatekeeperMode;

		void	_setGateKeeperMode(const bool change);
	public:
		ScavTrap(const std::string &name, const std::string &color);
		ScavTrap(const ScavTrap			   &original);

		void attack(const std::string	&target);

		~ScavTrap();

		bool	_getGateKeeperMode(void);
		void	guardGate(void);
};