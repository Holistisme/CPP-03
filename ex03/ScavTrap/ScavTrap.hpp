/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-03/ex03/ScavTrap/ScavTrap.hpp                 *
*                    Creation Date: January 29, 2025 11:18 AM                    *
*                    Last Updated: January 29, 2025 18:49 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                         Sources for the ScavTrap class                         *
*********************************************************************************/

#pragma	once

/********************************************************************************/

#include "./../ClapTrap/ClapTrap.hpp"

/********************************************************************************/

class ScavTrap : virtual public ClapTrap {
	protected:
		const static int _personalHitPoints = 100;
		const static int _personalEnergyPoints = 50;
		const static int _personalAttackDamage = 20;
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