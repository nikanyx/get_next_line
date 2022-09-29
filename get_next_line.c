/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/09/29 19:54:08 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_data		data;
	static char	buf[BUFFER_SIZE + 1];

	data.temp = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[0] != '\0')
	{
		data.temp = set_temp(data.temp, buf, check_nl(buf));
		if (data.temp[0] == '\n' && data.temp[1] == '\0')
			return (data.temp);
	}
	while (1)
	{
		data.cnt = read(fd, buf, BUFFER_SIZE);
		data.nl = check_nl(buf);
		data.flag = check_flag(buf, data.nl);
		if (data.cnt > 0)
			data.temp = set_temp(data.temp, buf, data.nl);
		if (data.nl < BUFFER_SIZE || data.flag == 1)
			return (data.temp);
	}
	return (data.temp);
}

/*int	main(void)
{
	int		fd = open("text.txt", O_RDONLY);
	char	*s = get_next_line(fd);

	printf("%s", s);
	free(s);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
}*/