/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-03/ex00/main.hpp                        *
*                    Creation Date: January 25, 2025 04:02 PM                    *
*                    Last Updated: January 27, 2025 02:00 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   All the essential sources for the program!                   *
*********************************************************************************/

#include	"./output.hpp"
#include	"./ClapTrap/ClapTrap.hpp"

/********************************************************************************/

#include	<ctime>
#include	<cstdlib>

/********************************************************************************/

#define SIGNAL 	'\033'
#define forever	true

/********************************************************************************/

typedef int	index;

/********************************************************************************/

int			main(void);

ClapTrap	createNewClapTrap(void);

std::string	getInputLine(void);
bool		sameString(const std::string &first, const std::string &second);
void		trimSpaces(std::string &string);