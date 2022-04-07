/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:22:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 23:46:59 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTEST_MALLOC_H
# define BTEST_MALLOC_H

# include <stddef.h>
# include <stddef.h>

void	*malloc(size_t size);
void	free(void *ptr);
int		btest_get_leaks(void);
void	btest_set_malloc_limit(size_t new_limit);

#endif /* BTEST_MALLOC_H */
