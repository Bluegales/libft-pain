/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btest_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:36:00 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 08:52:52 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTEST_TYPES_H
# define BTEST_TYPES_H

int	btest_int(int id, int expected, int got);
int	btest_bool(int id, int expected, int got);
int	btest_pointer(int id, const void *expected, const void *got);
int	btest_memory(int id, const void *expected, const void *got, int size);

#endif /* BTEST_TYPES_H */
