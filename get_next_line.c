/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/06/02 21:43:13 by cmachado         ###   ########.fr       */
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
	char		*res = NULL;
	char		*temp = NULL;
	int			cnt;
	int			val;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[0] != '\0')
		temp = ft_strjoin(temp, buf);
	while (1)
	{
		if (buf[0] != '\0')
			set_buf(NULL, buf, 0);
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt > 0)
		{
			temp = ft_strjoin(temp, buf);
			val = check_nl(temp);
		}
		if (val != 0 || cnt < BUFFER_SIZE)
		{
			if (buf[cnt] == '\0' && cnt < BUFFER_SIZE)
			{
				set_buf(NULL, buf, 0);
				return (temp);
			}
			break ;
		}
	}
	res = ft_substr(temp, 0, val + 1);
	set_buf(temp, buf, val);
	free(temp);
	temp = NULL;
	return (res);
}

/*int	main(void)
{
	int		fd;
	char	*s;

	fd = open("txt.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	while (*s)
	{
		s = get_next_line(fd);
		printf("%s", s);
	}
	free(s);
}*/