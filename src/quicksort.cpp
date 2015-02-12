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

#include <quicksort.h>

#include <algorithm>
#include <vector>
#include <ctime>
#include <iostream>

// Quicksort implementation
void
QuickSort::sort( std::vector<int> &ilist ) {
	bool swapped = true;
	int j = 0;
	int tmp;

	std::cout << "- Using Quicksort" << std::endl;

	resetIteractions();

	templateSort( ilist.begin(), ilist.begin() + getPosition() );

}

// Standard C++ implementation
// This is the short version from wikibooks
// http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort#C.2B.2B
// Under CC 3.0 Share-Alike
template <typename T>
void QuickSort::templateSort(T begin, T end) {
    if (begin != end) {
        T middle = std::partition (begin, end, std::bind2nd(
                    std::less<typename std::iterator_traits<T>::value_type>(), *begin));
        templateSort (begin, middle);
        T new_middle = begin;
        templateSort (++new_middle, end);
    }
	addIteraction();
}
