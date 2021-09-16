#ifndef CERT6_HPP
#define CERT6_HPP
#include "graph.hpp"
#include "graph_lib.hpp"
#include "graph_print.hpp"
#include "refine.hpp"
#include "basic_function.hpp"
#include "CompResult.hpp"
#include "permutation.hpp"
#include "permutation_library.hpp"

#include "tree.hpp"

void graph::Canon6( permutation &beta, std::vector< std::set<permutation> > &G , std::map<int , std::set< int > > &P , std::vector<int> &mu , bool &BestExist , Node *node , std::map< int , std::set<int> > &PreQ , std::map < std::string , Node > &tree_map ){
 //basic_function::print_partition( P );

 std::map< int , std::set<int> > Q = REFINE( P );
 //node->P = Q; // 単一の分割の要素は，含まない．
 
 std::set<int> preUnique;
 for( auto i : PreQ ){
  if( i.second.size() == 1 )
   preUnique.insert( *i.second.begin() );
 }

 int index = 0 ;
 int Pindex = 0;
 for( auto i : Q ){
  if( i.second.size() == 1 ){
   if( preUnique.find( *i.second.begin() ) != preUnique.end() )
    continue;
   node->discrete.push_back( std::tie( index , *i.second.begin() ) );
   index ++;
  }else{
   index += i.second.size();
   node->P[Pindex++] = i.second;
  }
 }

 basic_function::print_partition( Q );
 int l = -1;
 for(auto i : Q )
  if( i.second.size() > 1 ){
   l = i.first;
   break;
  }
 CompResult Res = CompResult::Better;
 std::vector<int> pi;
 if( l == - 1 ){
  l = n;
  pi = std::vector<int> ( n );
 }else pi = std::vector<int> ( l + 1 );
 if( BestExist ){
 	for(int i=0;i<l;i++) pi[i] = *Q[i].begin();
	Res = Compare( mu , pi , l ); 
 }

 //std::vector< Node* >& children = node->children;

 if( l == n ){
  if( !BestExist ){
   for(int i = 0 ; i < n ; i++ ) mu[i] = *Q[i].begin();
   BestExist = true;
  }else if( Res == CompResult::Better ){
   mu = pi;
   //std::cout<<"Better"<<std::endl;
  }else if( Res == CompResult::Equal ){
   std::vector< int > pi2tmp( n );
   for(int i = 0 ; i < n ; i++ ) pi2tmp[ pi[i] ] = mu[i];
   permutation pi2( pi2tmp );
   permutation_function::enter2( n , pi2  , beta , G );
  }
 }
 //else if( 1 )
 else if( Res != CompResult::Worse )
 {
  std::set<int> C = Q[l];
  std::set<int> D = Q[l];
  std::map<int,std::set<int> > R;
  for( int j = 0 ; j < l ; j++ ) R[j] = Q[j];
  for( int j = l + 1 ; j < Q.size(); j++ ) R[j+1] = Q[j];
  std::vector< bool > no_check( n , false );
  for( auto u : C )
  //for( auto it = C.begin() ; it != C.end() ; it++ )
  {
  // int u = *it;
   if( no_check[ u ] ) continue;
   std::set<int> Rl , Rl1 = D;
   Rl.insert( u );
   Rl1.erase( u );
   R[l] = Rl;
   R[l+1] = Rl1;
   
   Node child;
   //Node* child = (Node*) malloc( sizeof( Node ) ) ; //まだ、内容は未定義
   node->children.push_back( child );
   Canon6( beta , G , R , mu , BestExist , &node->children[ node->children.size() - 1 ] , Q , tree_map );
   std::vector< int > beta_dashtmp( n );
   std::vector< bool > no_use( n , true );
   for( int j = 0 ; j <= l ; j++ ) {
    beta_dashtmp[j] = *R[j].begin();
    no_use[ *R[j].begin() ] = false;
   }
   int j = l;
   for( int i = 0 ; i < n ; i++ ) 
    if( no_use[i] ) {
     j++;
     beta_dashtmp[j] = i;
    }
   permutation beta_dash( beta_dashtmp );
   permutation_function::changebase( n , beta , beta_dash , G );
   for( auto g : G[l] ) {
    no_check[ g.p[u]  ] = true;
   }
  }
 }
}

std::string graph::Cert6( std::map< std::string , Node > &tree_map ) {
 std::map<int , std::set<int> > P;
 std::vector<int> mu( n );
 iota( mu.begin() , mu.end() , 0 );

 for( int i = 0 ; i < n ; i++ )
  P[0].insert( i );
 /*
 std::map< std::tuple<int,Vector> , std::vector<int> > X = getPartitions();
 int index = 0;

 std::cerr << "GetPartitions() :";
 for( auto it : X ) {
  for( auto v : it.second ) P[ index ].insert( v );
  index++;
  //Output
  std::cerr <<" {";
  for( auto v : it.second ) std::cerr << " " << v ;
  std::cerr <<" }";
 }
 std::cerr << std::endl;
*/
 //root = (Node*) malloc( sizeof( Node ) );

 bool BestExist = false;
 std::vector< int > Ip(n);
 iota( Ip.begin() , Ip.end() , 0 );
 permutation I( Ip );
 std::vector< std::set< permutation > > G(n);
 for( int i = 0 ; i < n ; i++ ) G[i].insert( I );
 std::map<int, std::set<int> > PreQ = P ;
 Canon6( I , G , P , mu , BestExist , &root , PreQ , tree_map );
 //unsigned long long int num = 0;
 std::string s = "";
 for(int i = 1 ; i < n ; i++ )
  for(int j = 0 ; j < i ; j++ )
  {
   //num <<= 1;
   if( is_edge( mu[i] , mu[j] ) ){
    s += "1";
    //num++;
   }else{
    s += "0";
   }
  }
 return s;
}
#endif
