CXX = g++
CXXFLAGS = -O3 -std=c++17 -Iinclude/
DEBUGFLAGS = -Wall -O3 -std=c++17 -Iinclude/
TARGETDIR = bin
AR?=ar

permutation.a : permutation.o permutation_function.o
	${AR} rcs permutation.a permutation.o permutation_function.o

permutation.o : src/permutation.cpp include/permutation.hpp
	${CXX} ${CXXFLAGS} -o permutation.o -c src/permutation.cpp
permutation_function.o : src/permutation_function.cpp include/permutation.hpp
	${CXX} ${CXXFLAGS} -o permutation_function.o -c src/permutation_function.cpp


graph.a : graph_lib.o graph_print.o refine.o cert1.o cert2.o
	${AR} rcs graph.a graph_lib.o graph_print.o refine.o cert1.o cert2.o

graph_lib.o : src/graph_lib.cpp include/graph.hpp include/Vector.hpp include/CompResult.hpp include/basic_function.hpp
	${CXX} ${CXXFLAGS} -o graph_lib.o -c src/graph_lib.cpp
graph_print.o : src/graph_print.cpp include/graph.hpp include/Vector.hpp include/CompResult.hpp include/basic_function.hpp
	${CXX} ${CXXFLAGS} -o graph_print.o -c src/graph_print.cpp
refine.o : src/refine.cpp include/graph.hpp include/Vector.hpp include/CompResult.hpp include/basic_function.hpp
	${CXX} ${CXXFLAGS} -o refine.o -c src/refine.cpp
cert1.o : src/cert1.cpp include/graph.hpp include/Vector.hpp include/CompResult.hpp include/basic_function.hpp
	${CXX} ${CXXFLAGS} -o cert1.o -c src/cert1.cpp
cert2.o : src/cert2.cpp include/graph.hpp include/Vector.hpp include/CompResult.hpp include/basic_function.hpp include/permutation.hpp
	${CXX} ${CXXFLAGS} -o cert2.o -c src/cert2.cpp






main : permutation.a graph.a main.cpp
	${CXX} -o main ${CXXFLAGS} main.cpp permutation.a graph.a

clean:
	rm *.o *.a

