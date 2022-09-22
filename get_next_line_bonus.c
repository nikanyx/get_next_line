/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:58:44 by cmachado          #+#    #+#             */
/*   Updated: 2022/09/22 23:12:04 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*temp;
	int			cnt;
	int			nl;
	int			flag;

	temp = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[fd][0] != '\0')
	{
		temp = set_temp(temp, buf[fd], check_nl(buf[fd]));
		if (temp[0] == '\n' && temp[1] == '\0')
			return (temp);
	}
	while (1)
	{
		cnt = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][BUFFER_SIZE] = 0;
		nl = check_nl(buf[fd]);
		flag = check_flag(buf[fd], nl);
		if (cnt > 0)
			temp = set_temp(temp, buf[fd], nl);
		if (nl < BUFFER_SIZE || flag == 1)
			return (temp);
	}
	return(temp);
}
