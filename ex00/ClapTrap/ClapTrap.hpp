/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-03/ex00/ClapTrap/ClapTrap.hpp                  *
*                    Creation Date: January 25, 2025 12:51 PM                    *
*                    Last Updated: January 27, 2025 12:24 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                 Claptrap bolts                                 *
*********************************************************************************/

#pragma	once

/********************************************************************************/

#include	<iostream>

/********************************************************************************/

class ClapTrap {
	private:
		std::string	_name;
		std::string	_color;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

		void setName(const std::string			&name);
		void setHitPoints(const unsigned int	&amount);
		void setEnergyPoints(const unsigned int &amount);
		void setAttackDamage(const unsigned int &amount);

		std::string getName(void)		  const;
		std::string getColor(void)		  const;
		std::string getColoredName(void)  const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void editHitPoints(const int	&amount);
		void editEnergyPoints(const int	&amount);
		void editAttackDamage(const int &amount);

		bool checkEnergy(void) const;
	public:
		ClapTrap(const std::string		   &name, const std::string &color);
		ClapTrap(const ClapTrap			   &original);
		ClapTrap &operator=(const ClapTrap &original);
		~ClapTrap();

		int	 getHitPoints(void) const;
		void setColor(const std::string &color);

		void attack(const std::string	&target);
		void takeDamage(unsigned int	amount);
		void beRepaired(unsigned int	amount);

		void displayStatus(void);
};