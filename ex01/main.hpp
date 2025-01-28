#include	"./output.hpp"
#include	"./ClapTrap/ClapTrap.hpp"
#include	"./ScavTrap/ScavTrap.hpp"

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

ScavTrap	createNewScavTrap(void);

std::string	getInputLine(void);
bool		sameString(const std::string &first, const std::string &second);
void		trimSpaces(std::string &string);