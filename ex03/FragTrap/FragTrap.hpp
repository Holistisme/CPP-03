/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-03/ex03/FragTrap/FragTrap.hpp                 *
*                    Creation Date: January 29, 2025 12:36 PM                    *
*                    Last Updated: January 29, 2025 18:49 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                            High-Fives robot fingers                            *
*********************************************************************************/

#pragma	once

/********************************************************************************/

#include "./../ClapTrap/ClapTrap.hpp"

/********************************************************************************/

#include <cstdlib>

/********************************************************************************/

class FragTrap : virtual public ClapTrap {
	protected:
		const static int _personalHitPoints = 100;
		const static int _personalEnergyPoints = 100;
		const static int _personalAttackDamage = 30;
	private:
		bool _highFivesRequest;

		void _switchHighFivesRequest(void);
		bool _getHighFivesRequest(void) const;
	public:
		FragTrap(void);
		FragTrap(const std::string &name, const std::string &color);
		FragTrap(const FragTrap	   &original);
		FragTrap &operator=(const FragTrap &original);
		~FragTrap();

		void highFivesGuys(void);
		void highFivesSended(const std::string &input);
};