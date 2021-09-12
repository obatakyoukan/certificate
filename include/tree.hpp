#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "basic_function.hpp"

struct Node {
 //親と子供を定義
 //Node* parent;
 std::vector< Node > children;
 //持っている値
 //std::string str;
 std::map< int , std::set<int> > P;
 std::vector< std::tuple< int , int > > discrete; // index , value

 Node(){
 // parent = NULL;
 }

 //bool is_root(){
 // if( parent == NULL ) return true;
 // else return false;
 //}

 void print(int depth){
  std::cout << "depth : " << depth << std::endl;
  std::cout << "discrete : ";
  for( auto i : discrete ){
   int a,b;
   std::tie(a,b) = i;
   std::cout << "(" << a << "," << b << ")" ;
  }
  std::cout << std::endl << "P : ";
  basic_function::print_partition( P );
  for( int i = 0 ; i < children.size() ; i++ ){
   children[i].print( depth + 1 );
  }
 }

 void union_print( int depth , std::vector<int> Vs ){
  std::cout << "depth : " << depth << std::endl;
  std::vector< int > index;
  for( int i = 0 ; i < Vs.size() ; i++ ){
   if( Vs[i] == -1 ){
    index.push_back( i );
   }
  }
  for( auto i : discrete ){
   int a,b;
   std::tie(a,b) = i;
   Vs[ index[ a ] ] = b;
  }

  for( auto v : Vs )
   std::cout << v << " ";
  std::cout << std::endl;
  
  for( int i = 0 ; i < children.size() ; i++ ){
   children[i].union_print( depth + 1 , Vs );
  }

 }

};

void erase_tree( Node* a ){
 for( int i = 0 ; i < a->children.size() ; i++ ){
  erase_tree( &a->children[i] );
 }
 free( a );
}

void union_print_root( int n , Node *root ){
 std::vector< int > Vs( n , -1 );
 (*root).union_print( 1  , Vs );
}

#endif
