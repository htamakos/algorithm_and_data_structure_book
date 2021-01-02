/*
 * 動的計画法 (DP) 例題1
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
#define ll long long

int main(){
  vector<ll> h { 2, 9, 4, 5, 1, 6, 10 };
  int N = h.size();

  // 配列DP
  vector<ll> dp(N, numeric_limits<ll>::max());

  // 0, 7: (9-2), 

  // 初期条件
  dp[0] = 0;

  for(int i = 1; i < N; ++i){
    if(i == 1) {
      dp[i] = abs(h[i] - h[i - 1]);
    } else {
      dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]),
                  dp[i - 1] + abs(h[i] - h[i - 1]));
    }
  }

  cout << dp[N - 1] << endl;

  return 0;
}
