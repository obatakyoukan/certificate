#ifndef BASIC_FUNCTION_HPP
#define BASIC_FUNCTION_HPP
#include <set>
#include <map>
namespace basic_function {
 // A <= B
 bool SetInclude( std::set< int > &A , std::set< int > &B ){
  for( auto v : A )
   if( B.find( v ) == B.end() ) return false;
  return true;
 }
 // A / B
 void SetDelete( std::set< int > &A, std::set< int > &B ) {
  for( auto v : B ) A.erase( v );
 }
 void SetPrint( std::set< int > &A ){
  std::cout<<"{ ";
  for( auto it = A.begin() ; it != A.end() ; it++ ){
   std::cout<<*it<<' ';
  }
  std::cout<<"}"<<std::endl;
 }
 
 void print_partition( std::map<int , std::set<int> > &A ){
  std::cout<<"[";
  for( auto i : A ){
   std::cout<<"{ ";
   for( auto j : i.second ) std::cout<<j<<" ";
   std::cout<<"} ";
  }
  std::cout<<"]"<<std::endl;
 }

 std::string string_partition( std::map<int, std::set<int> > &A) {
  std::string res = "[";
  for( auto i : A ){
   res += "{";
   for( auto j : i.second )
    res += std::to_string(j) + ",";
   res += "}";
  }
  res += "]";
  return res;
 }

};

#endif
