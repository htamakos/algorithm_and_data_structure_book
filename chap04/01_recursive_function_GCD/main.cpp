/*
 * ユークリッド互除法
 * O(longN)
 */

#include <iostream>


/*
 * ユークリッド互除法により最大公約数を求める関数
 */
int gcd(int m, int n){
  if(n == 0) return m;

  return gcd(n, m % n);
}

int main(){

  std::cout << gcd(32, 2) << std::endl;
  std::cout << gcd(12012, 356) << std::endl;

  return 0;
}
