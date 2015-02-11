cmake_minimum_required( VERSION 2.8.11 )
project( intsort )

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )

if ( CMAKE_COMPILER_IS_GNUCXX )
	# Use C++11. Older gcc compilers < 4.9 uses c++0x syntax before fully addopt c++11
    set( CMAKE_CXX_FLAGS "-std=c++0x -fexceptions ${CMAKE_CXX_FLAGS}" )
endif()

find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile" @ONLY)
    add_custom_target(doc ALL
        ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
    install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs" DESTINATION "${CMAKE_INSTALL_DOCDIR}")
endif()

add_subdirectory(src)

