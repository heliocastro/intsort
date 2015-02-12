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


#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include <basesort.h>

#include <vector>

/**
 * This is BaseSort class. Is a simple class for sorting integer elements
 * The standard sort code algorithm is bubblesort. 
 * Function sort is virtual, allowing to change the algorithm in derived classes
 **/
class QuickSort : public BaseSort
{
public:
    /**
     * Sort the list of integers using quicksort
     *
     * @param ilist the list of integers to be sorted
     */
	void sort( std::vector<int> &ilist );

private:
	/**
	 * Template based quicksort, using std algorithms
	 * 
     * @param begin Initial element on integer list
	 * @param end Last element on integer list
     */
     template <typename T>
     void templateSort(T begin, T end);

	 /**
	  * Flag to sinalize when the required value reach the left most node 
	  * all iteractions over him are done.
	  */
	 bool leftMostNode;

	 /** 
	  * Reference value from position
	  **/
	 int referenceValue;
public:
	/**
	 * QuickSort constructor
	 **/
	QuickSort() {};
};

#endif //__QUICKSORT_H__
