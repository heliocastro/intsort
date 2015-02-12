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

#include <vector>
#include <iostream>

// This is the very simple bubblesort implementation
void
BaseSort::sort( std::vector<int> &ilist ) {
	bool swapped = true;
	int j = 0;
	int tmp;
	double pos = getPosition() < ilist.size() ? getPosition() : ilist.size() -1;

	std::cout << "- Using BubbleSort ( Default algorithm )" << std::endl;

	resetIteractions();

	// Keep the pos elementh to track
	int trackElement  = ilist[100];
	int currentPos = pos;

	while (swapped) {
		addTotalIteraction();
		swapped = false;
		j++;
		// We dont need sort all elements, only first 100
		for (int i = 0; i < ilist.size() - j; i++) {
			if (ilist[i] > ilist[i + 1]) {
				tmp = ilist[i];
				ilist[i] = ilist[i + 1];
				ilist[i + 1] = tmp;
				swapped = true;
				if( i == currentPos && ilist[i] != trackElement ) {
						currentPos++;
						addIteraction();
				} else if( i == currentPos-1 && ilist[i] == trackElement ) {
					currentPos--;
					addIteraction();
				}
			}
		}
		if( debugEnabled() ) {
			for( int i = 0; i < pos; i++ )
				std::cout << ilist[i] << " ";
			std::cout << std::endl;
		}
	}
}

BaseSort::BaseSort() {
	// clear iteractions
	iteractions = 0;
	position = 100;
	traceEnabled = false;
}

