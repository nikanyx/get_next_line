/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:58:44 by cmachado          #+#    #+#             */
/*   Updated: 2022/09/23 00:13:28 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	t_data		data;

	data.temp = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[fd][0] != '\0')
	{
		data.temp = set_temp(data.temp, buf[fd], check_nl(buf[fd]));
		if (data.temp[0] == '\n' && data.temp[1] == '\0')
			return (data.temp);
	}
	while (1)
	{
		data.cnt = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][BUFFER_SIZE] = 0;
		data.nl = check_nl(buf[fd]);
		data.flag = check_flag(buf[fd], data.nl);
		if (data.cnt > 0)
			data.temp = set_temp(data.temp, buf[fd], data.nl);
		if (data.nl < BUFFER_SIZE || data.flag == 1)
			return (data.temp);
	}
	return (data.temp);
}
