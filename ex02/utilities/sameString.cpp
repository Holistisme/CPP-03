/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-03/ex02/utilities/sameString.cpp                *
*                    Creation Date: January 25, 2025 04:00 PM                    *
*                    Last Updated: January 29, 2025 12:17 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*          Utility to check if two string a are identical without case           *
*********************************************************************************/

#include	"./../main.hpp"

/********************************************************************************/

/**
 * @brief Compares two strings case-insensitively.
 * 
 * This function checks if two strings are alphabetically identical,
 * ignoring differences in capitalization.
 * 
 * @param first The first string to compare.
 * @param second The second string to compare.
 * @return true: If the strings are identical (case-insensitive), false otherwise.
 */
bool sameString(const std::string &first, const std::string &second) {
	if (first.length() != second.length())
		return (false);

	for (size_t i = 0 ; i < first.length() ; i++) {
		char firstCurrentChar	= (first[i] >= 'a' && first[i] <= 'z')   ? (first[i] - 'a' + 'A')  : first[i];
		char secondCurrentChar	= (second[i] >= 'a' && second[i] <= 'z') ? (second[i] - 'a' + 'A') : second[i];

		if (firstCurrentChar != secondCurrentChar)
			return (false);
	}
	return (true);
}