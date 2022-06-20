/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/06/20 21:38:13 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 3*/

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
		temp = set_temp(temp, buf, check_nl(buf));
	while (1)
	{
		flag = 0;
		cnt = read(fd, buf, BUFFER_SIZE);
		nl = check_nl(buf);
		if (buf[nl - 1] == '\n')
			flag = 1;
		if (cnt > 0)
			temp = set_temp(temp, buf, nl);
		if (nl < BUFFER_SIZE || flag == 1)
			break ;
	}
	return (temp);
}

/*int	main(void)
{
	int		fd;
	char	*s;

	fd = open("1.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	while (*s)
	{
		s = get_next_line(fd);
		printf("%s", s);
	}
}*/