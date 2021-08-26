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



main : permutation.a
	${CXX} -o main ${CXXFLAGS} main.cpp permutation.a 

clean:
	rm *.o *.a

