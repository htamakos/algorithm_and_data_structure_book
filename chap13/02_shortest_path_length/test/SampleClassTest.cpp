#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "SampleClass.hpp"

TEST(calc, normal) {
  std::size_t N = 10;
  Graph<int> G(N);

  G[0].push_back(1);
  G[0].push_back(4);
  G[0].push_back(2);
  G[1].push_back(0);
  G[1].push_back(3);
  G[1].push_back(4);
  G[1].push_back(8);
  G[2].push_back(0);
  G[2].push_back(5);
  G[3].push_back(1);
  G[3].push_back(7);
  G[3].push_back(8);
  G[4].push_back(0);
  G[4].push_back(1);
  G[4].push_back(8);
  G[5].push_back(2);
  G[5].push_back(6);
  G[5].push_back(8);
  G[6].push_back(5);
  G[6].push_back(7);
  G[7].push_back(3);
  G[7].push_back(6);
  G[8].push_back(1);
  G[8].push_back(3);
  G[8].push_back(4);
  G[8].push_back(5);

  std::vector<int> res = spBFS(G, 0);

  ASSERT_EQ(0, res[0]);
  ASSERT_EQ(1, res[1]);
  ASSERT_EQ(2, res[3]);
  ASSERT_EQ(1, res[4]);
  ASSERT_EQ(2, res[5]);
  ASSERT_EQ(3, res[6]);
  ASSERT_EQ(3, res[7]);
  ASSERT_EQ(2, res[8]);
}

