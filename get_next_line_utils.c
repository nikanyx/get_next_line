/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:43:54 by cmachado          #+#    #+#             */
/*   Updated: 2022/06/02 21:43:14 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*new;

	if (!s2)
		return (NULL);
	if (s1)
		lens1 = ft_strlen(s1);
	else
		lens1 = 0;
	lens2 = ft_strlen(s2);
	new = (char *) malloc(lens1 + lens2 + 1);
	if (!new)
		return (NULL);
	if (s1)
	{
		ft_memcpy(new, s1, lens1);
		free(s1);
	}
	ft_memcpy(new + lens1, s2, lens2);
	new[lens1 + lens2] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		start = slen;
		len = 0;
	}
	if (len > slen)
		len = slen;
	s2 = (char *) malloc(len + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s + start, len);
	s2[len] = '\0';
	return (s2);
}*/

int	check_nl(char *temp)
{
	int		i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			break ;
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
			buf[i++] = buf[val++];
		else
			buf[i++] = '\0';
	}
	return (i);
}

char	*set_temp(char *s1, char *s2)
{
	int	slen;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	else
	{
		slen = check_nl(s2);
		s1 = (char *) malloc(slen + check_nl(s1) + 1);
	}
	if (!s1)
		return (NULL);
	while (s2[j] != '\0')
	{
		if (s1[i] != '\0')
			i++;
		else if (j < slen)
			((char *)s1)[i++] = ((char *)s2)[j++];
		else if (j >= slen)
			j = set_buf(s2, slen);
	}
	return (s1);
}

/*void	set_buf(char *temp, char *buf, int val)
{
	int	i;

	i = 0;
	if (temp)
	{
		while (temp[val + 1 + i] != '\0')
		{
			buf[i] = temp[val + 1 + i];
			i++;
		}
	}
	while (i <= BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
}*/
