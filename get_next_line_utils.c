/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:43:54 by cmachado          #+#    #+#             */
/*   Updated: 2022/10/24 00:15:50 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void cpybuf ()
{
	int i;
	int j;

	while (data.temp[j])
		j++;
	while (buf[i])
	{
		data.temp[j] = buf[i];
		if (data.temp[j] == '\n')
			br
	}
}