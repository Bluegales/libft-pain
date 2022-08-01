// Copyright 2022
// Author: pfuchs

#include "gtest/gtest.h"
#include "src/malloc_pain/malloc_pain.h"
#include "src/unittests/libft.h"
#include "src/unittests/linked_list/test_list.h"

class Lstdelone : public ::testing::Test {
 protected:
  void SetUp() override { malloc_size = INT32_MAX; }
  void TearDown() override {
    if (is_leaking()) FAIL() << show_leaked_memory();
  }
};

static void delfunction(void *content) { free_pain(content); }

TEST_F(Lstdelone, Simple) {
  auto list = generateTestList(1);
  ft_lstdelone(list, delfunction);
}
