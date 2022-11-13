/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:42:34 by cmachado          #+#    #+#             */
/*   Updated: 2022/10/24 00:15:52 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_data		data;
	static char	buf[BUFFER_SIZE + 1];

	data.temp = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	while (1)
	{
		if (buf[0] != 0)
			
		break;
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