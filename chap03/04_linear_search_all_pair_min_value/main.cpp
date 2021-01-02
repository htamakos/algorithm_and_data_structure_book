/*
 * N個の整数 a0,a1,...aN-1とN個の整数b0,b1,...bN-1が与えられる
 * 2組の整数列からそれぞれ1個ずつ整数を選んで和をとる
 * その和として考えられる値の内、整数K以上の範囲内での最小値を求めよ
 * このプログラムでは計算量は O(N^2)
 * 二分探索を使うと O(N log N) で解ける
 */
#include <string>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main(){

  int N, K;
  cin >> N >> K;

  vector<int> vecA(N);
  vector<int> vecB(N);
  for(int i = 0; i < N; i++) cin >> vecA[i];
  for(int i = 0; i < N; i++) cin >> vecB[i];

  int min_value = std::numeric_limits<int>::max();

  int a, s;
  for(int i = 0; i < N; i++){
    a = vecA[i];

    for(int j = 0; j < N; j++){
      s = vecB[j] + a;

      if(s <= K && s < min_value){
        min_value = s;
      }
    }
  }

  cout << min_value << "\n";

  return 0;
}
