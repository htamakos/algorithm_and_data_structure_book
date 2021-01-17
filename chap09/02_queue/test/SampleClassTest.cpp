#include <gtest/gtest.h>

#include "SampleClass.hpp"

TEST(calc, normal) {
  myalgo::queue::init();
  myalgo::queue::enqueue(109);
  myalgo::queue::enqueue(2);
  myalgo::queue::enqueue(3);

  ASSERT_EQ(109, myalgo::queue::dequeuemyalgo::queue::dequeue();
}

