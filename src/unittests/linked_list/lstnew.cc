// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/unittests/libft.h"
#include "src/malloc_pain/malloc_pain.h"

class LstNew : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

TEST_F(LstNew, NullContent) {
  t_list *head = reinterpret_cast<t_list *>(ft_lstnew(nullptr));
  EXPECT_EQ(nullptr, head->content);
  free_pain(head);
}

TEST_F(LstNew, NextNull) {
  t_list *head = ft_lstnew(nullptr);
  EXPECT_EQ(nullptr, head->next);
  free_pain(head);
}

TEST_F(LstNew, ContentUnchanged) {
  int a = 42;
  t_list *head = ft_lstnew(&a);
  EXPECT_EQ(42, a);
  free_pain(head);
}

TEST_F(LstNew, MallocFail) {
  malloc_size = 0;
  t_list *head = ft_lstnew(nullptr);
  EXPECT_EQ(nullptr, head);
}
