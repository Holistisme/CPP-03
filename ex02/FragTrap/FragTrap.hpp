/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-03/ex02/FragTrap/FragTrap.hpp                 *
*                    Creation Date: January 29, 2025 12:36 PM                    *
*                    Last Updated: January 29, 2025 03:23 PM                     *
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

class FragTrap : public ClapTrap {
	private:
		bool _highFivesRequest;

		void _switchHighFivesRequest(void);
		bool _getHighFivesRequest(void) const;
	public:
		FragTrap(const std::string &name, const std::string &color);
		FragTrap(const FragTrap	   &original);
		~FragTrap();

		void highFivesGuys(void);
		void highFivesSended(const std::string &input);
};