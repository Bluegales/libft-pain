/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_putendl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:02:41 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 10:40:05 by pfuchs           ###   ########.fr       */
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
	ft_putendl_fd("hey its me Mario", 1);
	ft_putendl_fd("A", 1);
	size_read = read(fd[0], buffer, 20);
	btest_restore_std();
	error += btest_int(0, 19, size_read);
	error += btest_memory(1, "hey its me Mario\nA\n", buffer, 19);
	pipe(fd);
	ft_putendl_fd("hey its me Mario", fd[1]);
	ft_putendl_fd("A", fd[1]);
	size_read = read(fd[0], buffer, 20);
	error += btest_int(10, 19, size_read);
	error += btest_memory(11, "hey its me Mario\nA\n", buffer, 19);
	btest_print_result(error);
}
