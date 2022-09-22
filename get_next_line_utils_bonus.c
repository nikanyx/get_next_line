/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:43:54 by cmachado          #+#    #+#             */
/*   Updated: 2022/09/22 23:01:16 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_flag(char *buf, int nl)
{
	return (buf[nl - 1] == '\n');
}

int	check_nl(char *temp)
{
	int		i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

int	set_buf(char *buf, int val)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (val <= BUFFER_SIZE)
			((char *)buf)[i++] = ((char *)buf)[val++];
		else
			buf[i++] = '\0';
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*set_temp(char *s1, char *s2, int nl)
{
	char	*temp;
	int		s_s1;

	temp = NULL;
	s_s1 = 0;
	if (s1)
		s_s1 = check_nl(s1);
	temp = (char *) malloc(nl + s_s1 + 1);
	if (!temp)
		return (NULL);
	if (s1)
	{
		ft_memcpy(temp, s1, s_s1);
		free(s1);
	}
	ft_memcpy(temp + s_s1, s2, nl);
	temp[s_s1 + nl] = '\0';
	set_buf(s2, nl);
	return (temp);
}
