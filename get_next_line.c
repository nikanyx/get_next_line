/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/06/24 21:01:26 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*temp;
	int			cnt;
	int			nl;
	int			flag;

	temp = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[0] != '\0')
	{
		temp = set_temp(temp, buf, check_nl(buf));
		if (temp[0] == '\n' && temp[1] == '\0')
			return (temp);
	}
	while (1)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		nl = check_nl(buf);
		flag = check_flag(buf, nl);
		if (cnt > 0)
			temp = set_temp(temp, buf, nl);
		if (nl < BUFFER_SIZE || flag == 1)
			return (temp);
	}
}
