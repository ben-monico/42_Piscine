/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmonico <benmonico@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:08:18 by bcarreir          #+#    #+#             */
/*   Updated: 2022/03/20 19:04:07 by benmonico        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup == NULL)
		return (0);
	ft_strlcpy(dup, s, (ft_strlen(s) + 1));
	return (dup);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*a;

	i = 0;
	a = (char *)b;
	while (i < len)
		a[i++] = c;
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s2[i])
		i++;
	str = (char *)ft_calloc((i + ft_strlen(s1) + 1), sizeof(char));
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	while (*s2)
		str[i++] = (char)*s2++;
	str[i] = '\0';
	return (str);
}
