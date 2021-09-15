#include "permutation.hpp"
#include "graph.hpp"
#include "cert1.hpp"
#include "cert2.hpp"
#include "cert5.hpp"
#include <time.h>
#include <string>

int main() {
 int n,m;
 char o;
 std::string s;
 std::cin>>o>>s>>n>>m;
 std::vector< std::vector< bool > > E( n , std::vector< bool > ( n , false ) );
 for( int i = 0 ; i < m ; i++ ){
  int u,v;
  std::cin>>o>>u>>v;
  //u--,v--;
  E[u][v] = E[v][u] = true;
 }
 graph g( E );
 
 clock_t start,end;
 double time;
 
 start = clock();
 std::cout<<"Cert5"<<std::endl;
 std::cout<<g.Cert5()<<std::endl;
 end= clock();
 time = static_cast<double> (end-start) / CLOCKS_PER_SEC * 1.0;
 std::cout << "time = " << time << " [sec]" << std::endl;
 
 std::cout << "Tree"<< std::endl;
 g.root.print(1);
 std::cout << "Union Print" << std::endl;
 union_print_root( n , &g.root );

 std::cout << "TREE MAP" << std::endl;
 std::map< std::string , Node > tree_map = make_tree_map( &g.root );
 for( auto i : tree_map ){
  std::cout << i.first << std::endl;
 }

 int u = 0 , v = 5;
 E[u][v] = E[v][u] = true;
 graph g2( E );
 start = clock();
 std::cout<<"G2 Cert5"<<std::endl;
 std::cout<<g2.Cert5()<<std::endl;
 end= clock();
 time = static_cast<double> (end-start) / CLOCKS_PER_SEC * 1.0;
 std::cout << "time = " << time << " [sec]" << std::endl;
 
 std::cout << "Tree"<< std::endl;
 g2.root.print(1);
 std::cout << "Union Print" << std::endl;
 union_print_root( n , &g2.root );
 
 std::cout << "TREE MAP" << std::endl;
 std::map< std::string , Node > tree_map2 = make_tree_map( &g2.root );
 for( auto i : tree_map2 ){
  std::cout << i.first << std::endl;
 }




}
