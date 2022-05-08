/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/05/08 20:39:36 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*res = NULL;
	char		*temp = NULL;
	int			cnt;
	int			val;

	if (buf[0] != '\0')
		temp = ft_strjoin(temp, buf);
	while (1)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		temp = ft_strjoin(temp, buf);
		val = check_nl(temp);
		if (val != 0 || cnt < BUFFER_SIZE)
			break ;
	}
	res = ft_substr(temp, 0, val + 1);
	set_buf(temp, buf, val);
	free(temp);
	return (res);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("txt.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
}
