
include_directories(
	${Boost_INCLUDE_DIR}
	)

set( INTSORT_SRCS
	main.cpp
	basesort.cpp
	quicksort.cpp
	sortutil.cpp
	)

add_executable( intsort ${INTSORT_SRCS} )

target_link_libraries( intsort
	${Boost_PROGRAM_OPTIONS_LIBRARY}
)
