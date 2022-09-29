/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmachado <cmachado@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:44:39 by cmachado          #+#    #+#             */
/*   Updated: 2022/09/29 19:53:58 by cmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	char	*temp;
	int		cnt;
	int		nl;
	int		flag;
}	t_data;

char	*get_next_line(int fd);
int		check_flag(char *buf, int nl);
int		check_nl(char *temp);
int		set_buf(char *buf, int val);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*set_temp(char *s1, char *s2, int nl);

#endif