/*
 * 線形探索法
 * N個の整数a1,a2,a3...,aN-1と整数値vが与えられる
 * ai = v となるデータが存在するか判定せよ
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, v, elm;

  cin >> N >> v;

  bool isExist = false;

  for(int i = 0; i < N; i++){
    cin >> elm;
    if(elm == v){
      isExist = true;
    }
  }

  if(isExist){
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }

  return 0;
}
