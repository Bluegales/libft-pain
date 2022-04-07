/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:02:41 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 10:40:12 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"
#include "btest.h"

int	main(void)
{
	int		error;
	int		fd[2];
	int		size_read;
	char	buffer[20];

	error = 0;
	fd[0] = btest_capture_std();
	ft_putnbr_fd(2147483647, 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putnbr_fd(0, 1);
	size_read = read(fd[0], buffer, 30);
	btest_restore_std();
	error += btest_int(0, 10 + 11 + 1, size_read);
	error += btest_memory(1, "2147483647""-2147483648""0", buffer, 10 + 11 + 1);
	pipe(fd);
	ft_putnbr_fd(2147483647, fd[1]);
	size_read = read(fd[0], buffer, 30);
	error += btest_int(10, 10, size_read);
	error += btest_memory(11, "2147483647", buffer, 10);
	btest_print_result(error);
}
