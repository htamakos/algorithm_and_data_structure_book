#include <ostream>
#include <vector>
#include <cstddef>
#include <iostream>

template<class T>
void chmax(T& a, T b)
{
  if(a < b) a = b;
}

template<class T>
void print_all(std::ostream& stream,
               std::vector<std::vector<T>> vv);


template<class T>
T knapsack(std::vector<T>& weight,
           std::vector<T>& value,
           int N,
           int W)
{
  // DP テーブルの初期化
  std::vector<std::vector<T>> dp(N + 1, std::vector<T>(W + 1, 0));

  // DP ループ
  for (std::size_t i = 0; i < N; ++i) {
    for(T w = 0; w <= W; ++w)
    {
      // i番目の品物を選ぶ場合
      if(w - weight[i] >= 0)
      {
        chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]);
      }

      // i番目の品物を選ばない場合
      chmax(dp[i + 1][w], dp[i][w]);
    }
  }

  print_all(std::cout, dp);

  return dp[N][W];
}

template <class T>
void print_all(std::ostream& stream, std::vector<std::vector<T>> datum) {
  std::size_t i = 0;
  for(auto& data : datum)
  {
    std::size_t j = 0;
    for(auto& value : data)
    {
      stream << "[" << i << "," << j << "]:" << value << "\n";
      j++;
    }

    ++i;
  }
}
