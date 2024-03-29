/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:58:44 by cmachado          #+#    #+#             */
/*   Updated: 2022/09/29 19:53:56 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		data.nl = check_nl(buf[fd]);
		data.flag = check_flag(buf[fd], data.nl);
		if (data.cnt > 0)
			data.temp = set_temp(data.temp, buf[fd], data.nl);
		if (data.nl < BUFFER_SIZE || data.flag == 1)
			return (data.temp);
	}
	return (data.temp);
}

/* int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	int fd2 = open("text2.txt", O_RDONLY);
	char *s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	s = get_next_line(fd2);
	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
}*/