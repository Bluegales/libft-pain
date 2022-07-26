/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:02:41 by pfuchs            #+#    #+#             */
/*   Updated: 2022/07/26 03:48:25 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>

#define TESTSUIT PutcharFD

void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(const char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putstr_fd(const char *s, int fd);

TEST(TESTSUIT, asd) {
	testing::internal::CaptureStdout();
	std::cout << "My test";

}

class TESTSUIT : public ::testing::Test {

  bool failed = false;
 protected:
  void SetUp() override {
	testing::internal::CaptureStdout();
    ASSERT_NO_FATAL_FAILURE(FUNCTION('0'));
  }
};

TEST_F(FUNCTION_FIX, digits) {
  for (int i = '0'; i <= '9'; i++) {
    EXPECT_EQ(FT_FUNCTION(i), FUNCTION(i));
  }
}

std::cout << "My test";
std::string output = testing::internal::GetCapturedStdout();

int main(void) {
  int error;
  int fd[2];
  int size_read;
  char buffer[20];

  error = 0;
  fd[0] = btest_capture_std();
  ft_putchar_fd('a', 1);
  ft_putchar_fd('Z', 1);
  size_read = read(fd[0], buffer, 20);
  btest_restore_std();
  error += btest_int(0, 2, size_read);
  error += btest_memory(1, "aZ", buffer, 2);
  pipe(fd);
  ft_putchar_fd('a', fd[1]);
  ft_putchar_fd('Z', fd[1]);
  size_read = read(fd[0], buffer, 20);
  error += btest_int(10, 2, size_read);
  error += btest_memory(11, "aZ", buffer, 2);
  btest_print_result(error);
}
