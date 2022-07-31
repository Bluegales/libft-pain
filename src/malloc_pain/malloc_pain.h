#ifndef TESTS_MALLOC_PAIN_H
#define TESTS_MALLOC_PAIN_H

#include <string>

extern "C" {
  void *malloc_pain(size_t size);
  void free_pain(void *data);
}

extern size_t malloc_size;
bool is_leaking();
std::string show_leaked_memory();

#endif // TESTS_MALLOC_PAIN_H
