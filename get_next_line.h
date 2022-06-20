/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:44:39 by cmachado          #+#    #+#             */
/*   Updated: 2022/06/20 21:21:08 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		check_nl(char *temp);

int		set_buf(char *buf, int val);

void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*set_temp(char *s1, char *s2, int nl);

#endif