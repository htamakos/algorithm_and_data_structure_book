#include <gtest/gtest.h>

#include <cstddef>
#include <sstream>
#include <vector>

#include "SampleClass.hpp"

TEST(search, normal) {
  std::size_t N = 10;
  Graph<int> G(N);

  G[0].push_back(5);
  G[1].push_back(3);
  G[1].push_back(6);
  G[2].push_back(5);
  G[2].push_back(7);
  G[3].push_back(0);
  G[3].push_back(7);
  G[4].push_back(1);
  G[4].push_back(2);
  G[4].push_back(6);
  G[6].push_back(7);
  G[7].push_back(0);

  std::stringstream ss;
  search(G, 4, ss);

  ASSERT_EQ(ss.str(), "1 2 6 3 5 7 0 ");

  ss.str("");
  ss.clear();
  dfs(G, 4, ss);
  ASSERT_EQ(ss.str(), "1 3 0 5 7 6 2 ");
}

