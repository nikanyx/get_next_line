/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/04/28 21:27:34 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*res = NULL;
	int			cnt;

	while (1)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		printf("%s%i", buf, cnt);
		if (cnt < BUFFER_SIZE)
			break ;
	}
	return (res);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("txt.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
}
