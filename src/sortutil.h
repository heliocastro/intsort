/*

    Copyright (C) 2015  Helio Chissini de Castro <helio@kde.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef __SORTUTIL_H__
#define __SORTUTIL_H__

#include <vector>
#include <ctime>

/**
 * This is SortUtil class. Common static functions to be used for the test code
 **/
class SortUtil
{
public:
	/**
	 * Generate a number of random requested integers
	 * The seed is an unsigned int random;
	 * for pure exercise only.
	 * 
	 * @param ilist the integer vector to be populated
	 * @param amount The amount of integers to be generated
	 * @param seed Set a fixed seed if needed. If not, defaults to time_t current time
     */
	static void randomSample( std::vector<int> &ilist, double amount, time_t seed = std::time(0) );

	/**
	 * Print the output of the integer list
	 *
	 * @param ilist the integer vector list
	 */
    static void printOutput( std::vector<int> &ilist );

private:
	SortUtil() {}
};

#endif //__SORTUTIL_H__
