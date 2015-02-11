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

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <iostream>

int main(int argc, char** argv) {
	// most basic sort engine to test
	BaseSort baseSort;
	// Our integer list
	std::vector<int> myList;

	po::options_description description("Usage:");
	description.add_options()
		("help", "This help message")
		("elements",  po::value<int>(), "Set the amount of elements to sort. Default is 1000")
		("position",  po::value<int>(), "Set the position. Default is 100")
		("print_list",  "Print the numbers sorted")
		("print_unsorted_list",  "Print the unsorted list")
		("print_every_iteraction", "Print every iteraction on sort")
		;

	po::variables_map vm;
	po::store( po::parse_command_line( argc, argv, description ), vm );
	po::notify( vm );

	if( vm.count( "help" ) ) {
		std::cout << description << std::endl;
		return 0;
	}

	if( vm.count( "position" ) )
		baseSort.setPosition( vm["position"].as<int>()  );

	// Get random values
	baseSort.randomSample( myList, vm.count( "elements" ) ? vm["elements"].as<int>() : 1000 );

	if( vm.count( "print_every_iteraction" ) )
		baseSort.printIteractions( true );

	if( vm.count( "print_unsorted_list" ) ) {
		for( int i = 0; i < myList.size(); i++ )
			std::cout << myList[i] << " ";
		std::cout << std::endl << std::endl;
	}

	// Effectively sort the list
	baseSort.sort( myList );

	std::cout << std::endl 
		<< "Number of iteractions to sort first " << baseSort.getPosition()
		<< " numbers: " << baseSort.getIteractions() << std::endl << std::endl;

	if( vm.count( "print_list" ) ) {
		for( int i = 0; i < myList.size(); i++ )
			std::cout << myList[i] << " ";
		std::cout << std::endl;
	}

	return 0;
}
