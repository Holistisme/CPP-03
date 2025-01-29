/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-03/ex01/ScavTrap/ScavTrap.hpp                 *
*                    Creation Date: January 29, 2025 11:18 AM                    *
*                    Last Updated: January 29, 2025 12:23 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                         Sources for the ScavTrap class                         *
*********************************************************************************/

#pragma	once

/********************************************************************************/

#include "./../ClapTrap/ClapTrap.hpp"

/********************************************************************************/

class ScavTrap : public ClapTrap {
	private:
		bool _gatekeeperMode;

		void _setGateKeeperMode(void);
	public:
		ScavTrap(const std::string &name, const std::string &color);
		ScavTrap(const ScavTrap	   &original);
		~ScavTrap();

		void attack(const std::string &target);

		bool getGateKeeperMode(void);
		void guardGate(void);
};