#ifndef PERMUTATION_FUNCTION
#define PERMUTATION_FUNCTION

#include "permutation.hpp"
void permutation_function::print_G( int n , std::vector< std::set< permutation > > &G ){
 for( int i = 0 ; i < n ; i++ ){
  std::cout<<"U[ "<< i <<" ]"<< std::endl;
  for( auto g : G[i] ) std::cout<<g.arraytostring()<<std::endl;
 }
}

int permutation_function::test2( int n , permutation &g, permutation &beta, std::vector< std::set< permutation > > &G ){
 for(int i = 0 ; i < n ; i++ ){
  int x = g.p[ beta.p[i] ];
  bool exits = false;
  for( auto h : G[i] ){
   if( h.p[ beta.p[i] ] == x ){
    permutation pi3 = ( h.inv() ).mult( g );
    g = pi3;
    exits = true;
    break;
   }
  }
  if( !exits ) return i;
 }
 return n;
}

void permutation_function::enter2( int n , permutation &g, permutation &beta, std::vector< std::set< permutation > > &G ){
 int i = permutation_function::test2( n , g , beta , G );
 if( i == n ) return;
 else {
  G[i].insert( g );
 }
 for( int j = 0 ; j <= i ; j++ )
  for( auto h : G[j] ){
   permutation f = g.mult( h );
   permutation_function::enter2( n , f , beta , G );
  }
}

void permutation_function::changebase( int n , permutation &beta, permutation &beta_dash, std::vector< std::set< permutation > > &G ){
 std::vector< std::set< permutation > > H(n);
 std::vector< int > Ip( n );
 iota( Ip.begin() , Ip.end() , 0 );
 permutation I(Ip);
 for( int i = 0 ; i < n ; i++ ) H[i].insert( I );

 for( int i = 0 ; i < n ; i++ ){
  for( auto g : G[i] ){
   enter2( n , g , beta_dash , H );
  }
 }
 G = H;
}

#endif
