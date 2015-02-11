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

#include <basesort.h>

#include <algorithm>
#include <vector>
#include <ctime>

// This is the very simple bubblesort implementation
void
BaseSort::sort( std::vector<int> &ilist ) {
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < ilist.size() - j; i++) {
                  if (ilist[i] > ilist[i + 1]) {
                        tmp = ilist[i];
                        ilist[i] = ilist[i + 1];
                        ilist[i + 1] = tmp;
                        swapped = true;
						if( i < position )
							iteractions++;
                  }
            }
      }
}


void
BaseSort::randomSample( std::vector<int> &ilist, double amount ) {
	// Amount is lower than position? Then set position to amount -1
	if( position > amount )
		setPosition( amount -1 );

	// New seed comes from above random seed
	std::default_random_engine listSeed( std::time(0) );
	std::uniform_int_distribution<int> listDist(-32768, 32768);

	for( double i = 0; i < amount; i++ )
		ilist.push_back( listDist( listSeed ) );
}

BaseSort::BaseSort() {
	// clear iteractions
	iteractions = 0;
	position = 100;
}

