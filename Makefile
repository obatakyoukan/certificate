CXX = g++
CXXFLAGS = -O3 -std=c++17 -Iinclude/
DEBUGFLAGS = -Wall -O3 -std=c++17 -Iinclude/
TARGETDIR = bin
AR?=ar

INCLUDE_GRAPH = include/graph.hpp include/graph_lib.hpp include/graph_print.hpp include/refine.hpp include/cert1.hpp include/cert2.hpp

#main : permutation.a main.cpp include/graph.hpp include/graph_lib.hpp include/graph_print.hpp include/basic_function.hpp include/cert1.hpp include/cert2.hpp include/refine.hpp include/Vector.hpp include/CompResult.hpp 
#	${CXX} -o main ${CXXFLAGS} main.cpp permutation.a

main : main.cpp 
	${CXX} -o main ${CXXFLAGS} main.cpp

clean:
	rm *.o *.a

