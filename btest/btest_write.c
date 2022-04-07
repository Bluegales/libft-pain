/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:06:21 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/14 21:02:50 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btest_write.h"

#include <unistd.h> // dup dup2 pipe
#include <stdio.h> // stdout
#include <fcntl.h> // F_SETFL F_GETFL O_NONBLOCK

static int	g_stdout_bk = 0;

int	btest_capture_std(void)
{
	int		stolen[2];
	int		flags;

	g_stdout_bk = dup(fileno(stdout));
	pipe(stolen);
	dup2(stolen[1], fileno(stdout));
	flags = fcntl(stolen[0], F_GETFL, 0);
	fcntl(stolen[0], F_SETFL, flags | O_NONBLOCK);
	return (stolen[0]);
}

void	btest_restore_std(void)
{
	if (!g_stdout_bk)
		return ;
	dup2(g_stdout_bk, fileno(stdout));
	g_stdout_bk = 0;
}
