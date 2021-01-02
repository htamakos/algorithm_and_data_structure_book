#include <limits>
#include <vector>
#include <iostream>


enum class CACHE_VALUE {
  INITIAL = -1,
  FALSE = 0,
  TRUE = 1,
};

/*
 * 再帰関数による部分和 (メモ化バージョン)
 */
bool partial_sum(int n, int w,
                 const std::vector<int> &a,
                 std::vector<std::vector<CACHE_VALUE>> &cache){
  if(n == 0) {
    if(w == 0) {
      return true;
    } else {
      return false;
    };
  };
  if(w < 0) return false;

  // メモ化チェック
  if(cache[n][w] != CACHE_VALUE::INITIAL) return static_cast<bool>(cache[n][w]);

  // a[n-1] を選ぶ場合
  if(partial_sum(n - 1, w - (a[n - 1]), a, cache)) return static_cast<bool>(cache[n][w] = CACHE_VALUE::TRUE);

  // a[n-1] を選ばない場合
  if(partial_sum(n - 1, w, a, cache)) return static_cast<bool>(cache[n][w] = CACHE_VALUE::TRUE);

  return static_cast<bool>(cache[n][w] = CACHE_VALUE::FALSE);
}

int main(){
  std::vector<int> v = { 1, 2, 3, 3, 4 };

  int N = v.size();
  int W = 99;
  int MAX = 1000;

  std::vector< std::vector<CACHE_VALUE>> cache (N+1, std::vector<CACHE_VALUE>(MAX + 1, CACHE_VALUE::INITIAL));

  if(partial_sum(N, W, v, cache)){
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
