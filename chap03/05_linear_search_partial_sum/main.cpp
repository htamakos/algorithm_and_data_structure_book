/**
 * N個の整数a0,a1,...aN-1と正の整数Wが与えられる
 * a0,a1,.....aN-1の中から何個かの整数を選んで総和をWとすることができるか判定せよ
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, W;
  cin >> N >> W;

  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];

  bool is_exist = false;

  // 0, 1, 2, ..., 2^N までループする
  // 2^N は2つの数の組み合わせ数を表す
  for(int bit = 0; bit < (1 << N); bit++){
    int sum = 0;

    for(int i = 0; i < N; i++){
      if(bit & (1 << i)){
        sum += a[i];
      }
    }

    if(sum == W){
      is_exist = true;
      break;
    }
  }

  if(is_exist){
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
