#include <limits>
#include <string>
#include <vector>

template <class T>
void chmin(T& a, T b) {
  if (a > b) a = b;
}

int edit_distance(std::string S, std::string T, int cost = 1) {
  // DP テーブルの初期化
  std::vector<std::vector<int>> dp(
      S.size() + 1,
      std::vector<int>(T.size() + 1, std::numeric_limits<int>::max()));

  dp[0][0] = 0;

  for (std::size_t i = 0; i <= S.size(); ++i) {
    for (std::size_t j = 0; j <= T.size(); ++j) {
      if (i > 0 && j > 0) {
        if (S[i - 1] == T[j - 1]) {
          chmin(dp[i][j], dp[i - 1][j - 1]);
        } else {
          chmin(dp[i][j], dp[i - 1][j - 1] + cost);
        }
      }

      if (i > 0) {
        chmin(dp[i][j], dp[i - 1][j] + cost);
      }

      if (j > 0) {
        chmin(dp[i][j], dp[i][j - 1] + cost);
      }
    }
  }

  return dp[S.size()][T.size()];
}
