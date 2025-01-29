/*********************************************************************************
*                              Author: Alexy Heitz                               *
*               File Name: /CPP-03/ex03/DiamondTrap/DiamondTrap.hpp              *
*                    Creation Date: January 29, 2025 03:47 PM                    *
*                    Last Updated: January 29, 2025 06:47 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                             The sources of horror                              *
*********************************************************************************/

#include "./../FragTrap/FragTrap.hpp"
#include "./../ScavTrap/ScavTrap.hpp"

/********************************************************************************/

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;
	public:
		DiamondTrap(const std::string &name, const std::string &color);
		DiamondTrap(const DiamondTrap &original);
		~DiamondTrap();

		std::string getColoredName(void)  const;
		std::string getName(void)		  const;
		void		attack(const std::string &target);
		void		whoAmI(void);
};