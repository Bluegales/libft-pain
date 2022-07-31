// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class LstLast : public ::testing::Test {
 protected:
  void SetUp() override {
    malloc_size = INT32_MAX;
  }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

TEST_F(LstLast, OptionalSize0) {
  EXPECT_EQ(nullptr, ft_lstlast(nullptr));
}

TEST_F(LstLast, Size1) {
  auto list = generateTestList(1);
  auto data = reinterpret_cast<Data*>(ft_lstlast(list)->content);
  EXPECT_EQ(0, data->a);
  EXPECT_EQ(0, data->b);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}

TEST_F(LstLast, Size10) {
  auto list = generateTestList(10);
  auto data = reinterpret_cast<Data*>(ft_lstlast(list)->content);
  EXPECT_EQ(0, data->a);
  EXPECT_EQ(0, data->b);
  EXPECT_TRUE(isListUnchanged(list));
  freeTestList(list);
}
