#include <iostream>

int fibo(int n){

  if(n == 0) return 0;
  if(n == 1) return 1;

  return fibo(n - 1) + fibo(n - 2);
}

int main(){
  std::cout << fibo(32) << std::endl;
  return 0;
}
