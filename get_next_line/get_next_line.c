/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmonico <benmonico@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:17:52 by benmonico         #+#    #+#             */
/*   Updated: 2022/03/19 18:04:59 by benmonico        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	unsigned int		c;

	c = 0;
	while (s[c])
		c++;
	if (!s)
		return (NULL);
	if (start >= c)
		return (ft_strdup(""));
	if (c < len)
		len = c;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, (char *)&s[start], len + 1);
	return (substr);
}

char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*str;
	static char	*aux;	
	int			ret;
	static int	k;
	static int	i;

	if (fd < 0 || BUFFER_SIZE <= 0 || (k > 0 && str == NULL))
		return (NULL);
	if (str && k > 0 && str[k] == '\0')
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	if (str == NULL && k == 0)
	{
		str = ft_calloc(1, sizeof(char));
		while (1)
		{
			if (aux)
				free (aux);
			ft_memset(buffer, 0, BUFFER_SIZE + 1);
			ret = read(fd, buffer, BUFFER_SIZE);
			if (ret == -1)
			{
				free (str);
				return (NULL);
			}
			aux = ft_strdup(str);
			free (str);
			str = ft_strjoin(aux, buffer);
			if (ret == 0)
				break;
		}
	}
	free (aux);
	if (k == 0)
		i = 0;
	else if (str[k + 1])
	{
		k++;
		i = k;
	}
	while (str[k] && (str[k] != '\n' || str[k] != '\0') )
		k++;
	aux = ft_substr(str, i, k - i + 1);
	return (aux);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int fd = open("/Users/benmonico/Desktop/Github/get_next_line/hello.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));	
// 	printf("%s", get_next_line(fd));	
// 	printf("%s", get_next_line(fd));	
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));	
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
	
	
// 	// get_next_line(fd);

// }