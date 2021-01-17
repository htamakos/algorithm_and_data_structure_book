#include <gtest/gtest.h>

#include "SampleClass.hpp"

TEST(calc, normal) {
  myalgo::stack::init();
  myalgo::stack::push(9998);
  myalgo::stack::push(100);

  ASSERT_EQ(100, myalgo::stack::pop());
}

