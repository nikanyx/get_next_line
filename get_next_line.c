/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/04/27 21:16:57 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*res;
	int		cnt;

	while (1)
	{
		cnt = read(fd, &buf, BUFFER_SIZE);
		if (cnt <= 0 && !buf)
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
