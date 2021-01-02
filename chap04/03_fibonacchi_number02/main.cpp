#include <vector>
#include <iostream>

const int CACHE_SIZE = 1000;
std::vector<int> cache(CACHE_SIZE);

int fibo(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;

  if(cache.at(n)) return cache[n];

  return cache[n] = fibo(n - 1) + fibo(n - 2);
}

int main(){
  std::cout << fibo(32) << std::endl;
  return 0;
}
