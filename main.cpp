#include "permutation.hpp"

int main() {
 std::string s;
 std::cin>>s;
 std::vector< int > a = permutation_function::stringtoarray( s );
 permutation p( a );
 std::cout << p.arraytostring() << std::endl;
}
