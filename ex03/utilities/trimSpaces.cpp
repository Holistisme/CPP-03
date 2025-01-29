/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-03/ex03/utilities/trimSpaces.cpp                *
*                    Creation Date: January 25, 2025 04:00 PM                    *
*                    Last Updated: January 29, 2025 12:17 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                Utility for removing extra spaces from a string                 *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief Removes leading and trailing spaces from a string.
 * 
 * @param string The string to process.
 */
void trimSpaces(std::string &string) {
	size_t start = 0;
	size_t end	 = string.length();

	while (start < string.length() && std::isspace(string[start]))
		++start;
	while (end > start && std::isspace(string[end - 1]))
		--end;

	string = string.substr(start, end - start);
}