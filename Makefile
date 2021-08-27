CXX = g++
CXXFLAGS = -O3 -std=c++17 -Iinclude/
DEBUGFLAGS = -Wall -O3 -std=c++17 -Iinclude/
TARGETDIR = bin
AR?=ar

INCLUDE_PERMUTATION = include/permutation.hpp include/permutation_library.hpp include/permutation_function.hpp
INCLUDE_GRAPH = include/graph.hpp include/graph_lib.hpp include/graph_print.hpp include/refine.hpp include/cert1.hpp include/cert2.hpp include/basic_function.hpp include/Vector.hpp include/CompResult.hpp ${INCLUDE_PERMUTATION}

#main : permutation.a main.cpp include/graph.hpp include/graph_lib.hpp include/graph_print.hpp include/basic_function.hpp include/cert1.hpp include/cert2.hpp include/refine.hpp include/Vector.hpp include/CompResult.hpp 
#	${CXX} -o main ${CXXFLAGS} main.cpp permutation.a

main : main.cpp ${INCLUDE_GRAPH}
	${CXX} -o main ${CXXFLAGS} main.cpp

clean:
	rm *.o *.a

