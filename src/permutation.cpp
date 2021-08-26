#include "permutation.hpp"

permutation permutation::mult(permutation& b) {
 assert( n == b.n );
 std::vector<int> c( n );
 for( int i = 0 ; i < n ; i++ ){
  c[i] = p[ b.p[i] ];
 }
 return permutation( c );
}

permutation permutation::inv() {
 std::vector<int> c( n );
 for( int i = 0 ; i < n ; i++ ){
  c[ p[i] ] = i;
 }
 return permutation( c );
}

std::string permutation::arraytostring() {
 std::vector<bool> P(n,true);
 std::string C = "";
 for( int i = 0 ; i < n ; i++ ){
  if( P[i] ){
   //if( i != 0 ) C += " ";
   C += "(";
   C += std::to_string( i );
   P[i] =  false;
   int j = i;
   while( P[ p[j] ] ){
    C += ",";
    j = p[j];
    C += std::to_string( j );
    P[j] = false;
   }
   C += ")";
  }
 }
 return C;
}

std::vector< int > permutation_function::stringtoarray( std::string C ){
 int n = 0;
 for(int i = 0 ; i < C.size() ;  ){
  if( C[i] == '(' ){
   i++;
   int tmp = 0;
   while( i < C.size() and '0' <= C[i] and C[i] <= '9' ){
    tmp *= 10;
    tmp += C[i] - '0';
    i++;
   }
   n = std::max( n , tmp + 1 );
  }else if( C[i] == ',' ){
   i++;
   int tmp = 0;
   while( i < C.size() and '0' <= C[i] and C[i] <= '9' ){
    tmp *= 10;
    tmp += C[i] - '0';
    i++;
   }
   n = std::max( n , tmp + 1 );
  }else if( C[i] == ')' ){
   i++;
  }else {
   std::cerr<<"Formal err"<<std::endl;
   exit(1);
  }
 }
 std::vector< int > res( n );
 iota( res.begin() , res.end()  , 0 );
 int x,y,z;
 for(int i = 0 ; i < C.size() ;  ){
  if( C[i] == '(' ){
   i++;
   int tmp = 0;
   while( i < C.size() and '0' <= C[i] and C[i] <= '9' ){
    tmp *= 10;
    tmp += C[i] - '0';
    i++;
   }
   x = tmp;
   z = tmp;
  }else if( C[i] == ',' ){
   i++;
   int tmp = 0;
   while( i < C.size() and '0' <= C[i] and C[i] <= '9' ){
    tmp *= 10;
    tmp += C[i] - '0';
    i++;
   }
   y = tmp;
   res[ x ] = y;
   x = y;
  }else if( C[i] == ')' ){
   res[x] = z;
   i++;
  }else {
   std::cerr<<"Formal err"<<std::endl;
   exit(1);
  }
 }
 return res;
}

