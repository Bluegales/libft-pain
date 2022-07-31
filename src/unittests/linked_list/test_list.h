#ifndef SRC_UNITTESTS_LINKED_LIST_TEST_LIST_H
#define SRC_UNITTESTS_LINKED_LIST_TEST_LIST_H

#include "src/unittests/libft.h"

struct Data {
  long a;
  long b;
};

t_list *generateTestList(int length);
void freeTestList(t_list *head);
bool isListUnchanged(t_list *head);

#endif // SRC_UNITTESTS_LINKED_LIST_TEST_LIST_H
