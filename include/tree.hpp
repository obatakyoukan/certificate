#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

struct Node {
 //親と子供を定義
 //Node* parent;
 std::vector< Node* > children;
 //持っている値
 //std::string str;
 std::map< int , std::set<int> > P;
 std::vector< std::tuple< int , int > > discrete;

 Node(){
 // parent = NULL;
 }

 //bool is_root(){
 // if( parent == NULL ) return true;
 // else return false;
 //}

 void print(){
  for( int i = 0 ; i < children.size() ; i++ ){
   (*children[i]).print();
  }
 }

};

void erase_tree( Node* a ){
 for( int i = 0 ; i < a->children.size() ; i++ ){
  erase_tree( a->children[i] );
 }
 free( a );
}


#endif
