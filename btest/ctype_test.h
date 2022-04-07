/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:39:05 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/15 10:39:06 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTYPE_TEST_H
# define CTYPE_TEST_H

void	ctype_test_bool(int (*expected_func)(int), int (*got_func)(int));
void	ctype_test_int(int (*expected_func)(int), int (*got_func)(int));

#endif /* CTYPE_TEST_H */
