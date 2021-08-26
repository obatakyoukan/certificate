#ifndef PERMUTATION_HPP
#define PERMUTATION_HPP

#include <iostream>

#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>


class permutation {
 public:
  int n;
  std::vector<int> p;
 public:
  permutation(){}
  permutation(int n ): n(n),p(n){ iota(p.begin(),p.end(),0); }
  permutation(std::vector<int>& p) : n(p.size()),p(p){}
  bool operator < ( const permutation& b ) const {
   assert( n != b.n );
   for( int i = 0 ; i < n ; i++ )
    if( p[i] != b.p[i] ) return p[i] < b.p[i];
   return p[0] < b.p[0];//同じとき
  }
  bool operator == ( const permutation& b ) const {
   assert( n != b.n );
   for( int i = 0 ; i < n ; i++ )
    if( p[i] != b.p[i] ) return false;
   return true;
  }
  bool operator != ( const permutation& b ) const {
   assert( n != b.n );
   for( int i = 0 ; i < n ; i++ )
    if( p[i] != b.p[i] ) return true;
   return false;
  }

  permutation mult( permutation& b );
  permutation inv();
  std::string arraytostring();
};


namespace permutation_function {
 std::vector< int > stringtoarray( std::string C );
 void print_G( int n , std::vector< std::set< permutation > > &G );
 void enter2( int n , permutation &g, permutation &beta, std::vector< std::set< permutation > > &G);
 int test2( int n , permutation &g, permutation &beta,  std::vector< std::set< permutation > > &G );
 void changebase( int n , permutation &beta, permutation &beta_dash , std::vector< std::set< permutation > > &G );
};

#endif

