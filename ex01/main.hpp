/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-03/ex01/main.hpp                        *
*                    Creation Date: January 29, 2025 11:18 AM                    *
*                    Last Updated: January 29, 2025 12:20 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      Sources for the inheritance program                       *
*********************************************************************************/

#include "./output.hpp"
#include "./ClapTrap/ClapTrap.hpp"
#include "./ScavTrap/ScavTrap.hpp"

/********************************************************************************/

#include <ctime>
#include <cstdlib>

/********************************************************************************/

#define SIGNAL	'\033'
#define forever true

/********************************************************************************/

typedef int index;

/********************************************************************************/

int			main(void);

ScavTrap	createNewScavTrap(void);

std::string getInputLine(void);
bool		sameString(const std::string &first, const std::string &second);
void		trimSpaces(std::string &string);