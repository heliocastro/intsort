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


#ifndef __BASESORT_H__
#define __BASESORT_H__

#include <vector>

/**
 * This is BaseSort class. Is a simple class for sorting integer elements
 * The standard sort code algorithm is bubblesort. 
 * Function sort is virtual, allowing to change the algorithm in derived classes
 **/
class BaseSort
{
public:
    /**
     * Sort the list of integers using simple bubblesort
     * It can be overrided to new classes to use different sort algorithms
     *
     * @param ilist the list of integers to be sorted
     */
	virtual void sort( std::vector<int> &ilist );

	/**
	 * Generate a number of random requested integers
	 * The seed is an unsigned int random;
	 * for pure exercise only.
	 * 
	 * @param ilist the integer vector to be populated
	 * @param amount The amount of integers to be generated
     */
	void randomSample( std::vector<int> &ilist, double amount );

	/**
	 * Set the position of the sorted list you want to get to see iteractions number
     * Default is 100.
     * If the number set prove to be higher than the provided amount of numbers 
	 * in the integers list, the max number of the integers is taken.
	 *
 	 * @param pos position of the integers list where info is required
	 */
	void setPosition( double pos = 100 ) { position = pos; }

	/**
	 * Get the number of iteractions done until reach interactions requested
     *
	 * @returns Number of iteractions happened until reach the requested position
     */
	double getIteractions() const {  return iteractions; }

	/**
	 * Get the position where we want to stop the iteractions
     *
	 * @returns position number
     */
	double getPosition() const {  return position; }

	/**
	 * Enable or disable output of all list iteractions. U
	 * Useful only for debug process.
	 *
	 * @param enable Enable or disable the output
	 */
	void printIteractions( bool enable ) { showIter =  enable; }

public:
	/**
	 * BaseSort constructor
	 **/
	BaseSort();
private:
	int iteractions;
	double position;
	bool showIter;
};

#endif //__BASESORT_H__
