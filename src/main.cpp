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
#include <quicksort.h>
#include <sortutil.h>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>

int main(int argc, char** argv) {
	QuickSort sort;
	std::vector<int> myList;
	std::vector<int> tmpList;

	po::options_description description("Usage:");
	description.add_options()
		("help", "This help message")
		("elements",  po::value<int>(), "Set the amount of elements to sort. Default is 1000")
		("position",  po::value<int>(), "Set the position. Default is 100")
		("enable_debug",  "Enable trace debug of all iteractions")
		;

	po::variables_map vm;
	po::store( po::parse_command_line( argc, argv, description ), vm );
	po::notify( vm );

	if( vm.count( "help" ) ) {
		std::cout << description << std::endl;
		return 0;
	}

	if( vm.count( "position" ) )
		sort.setPosition( vm["position"].as<int>()  );

	// Get random values 
	SortUtil::randomSample( myList, vm.count( "elements" ) ? vm["elements"].as<int>() : 1000 );

	std::cout << "Current element on position " << sort.getPosition() << " is " << myList[100] << std::endl << std::endl;

	if( vm.count( "enable_debug" ) )
		sort.setDebugEnabled( true );

	// Preserve original list
	tmpList = myList;

	// Effectively sort the list
	sort.sort( tmpList );

	std::cout  << "Number of iteractions to sort element " << sort.getPosition() << " : " << sort.getIteractions() << std::endl << std::endl;

	// copy again the original list
	tmpList = myList;

	// Call the superclass base algorithm
	sort.BaseSort::sort( myList );

	std::cout  << "Number of iteractions to sort element " << sort.getPosition() << " : " << sort.getIteractions() << std::endl << std::endl;

	return 0;
}
