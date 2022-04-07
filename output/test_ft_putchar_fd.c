/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putchar_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:02:41 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 10:39:55 by pfuchs           ###   ########.fr       */
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
