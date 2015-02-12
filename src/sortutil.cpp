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

#include <sortutil.h>

#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>

void
SortUtil::randomSample( std::vector<int> &ilist, double amount, time_t seed ) {
	// New seed comes from above random seed
	std::default_random_engine listSeed( seed );
	std::uniform_int_distribution<int> listDist(-32768, 32768);

	for( double i = 0; i < amount; i++ )
		ilist.push_back( listDist( listSeed ) );
}

void
SortUtil::printOutput( std::vector<int> &ilist ) {
    for( int i = 0; i < ilist.size(); i++ )
            std::cout << ilist[i] << " ";
        std::cout << std::endl;
}

