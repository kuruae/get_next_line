/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:35:16 by emagnani          #+#    #+#             */
/*   Updated: 2024/06/05 14:56:27 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while ((size_t)i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		total_len;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((total_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	total_len;
	int		i;

	i = 0;
	total_len = ft_strlen(s);
	str = malloc((total_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while ((size_t)i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

static char	*read_file(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	return (buffer);
}

int	check_newline(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

/* 	if (check_newline(buffer, '\n') == 0)
	{
		if (buffer[0] != '\n');
		output = ft_strjoin(buffer, stash)
	}

	if (check_newline(buffer, '\n') == BUFFER_SIZE)
		ft_bzero(stash, BUFFER_SIZE + 1);
	if (check_newline(buffer, '\n') < BUFFER_SIZE)
		*rest = *buffer + check_newline(buffer, '\n');
	 */

char	*get_next_line(int fd)
{
	char		*output;
	char		buffer[BUFFER_SIZE + 1];
	static char	rest[BUFFER_SIZE + 1] = "";
	int			newline_pos;

	if (fd < 0 || fd > 1023)
		return (NULL);
/* 	if (!rest)
		output = ft_strdup(""); */
	while (1)
	{
/* 		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL); */
		newline_pos = check_newline(buffer, '\n');
		if (buffer[newline_pos] == '\n')
		{
			buffer[newline_pos + 1] == '\0';
			output = ft_strjoin(rest, buffer);
			ft_memset(rest, 0, BUFFER_SIZE + 1);
			ft_memcpy(rest, buffer + newline_pos + 1, BUFFER_SIZE - newline_pos);
			break ;
		}
		ft_strjoin(rest, buffer);
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		if (!read_file(fd, buffer))
			break ;
	}
	if (!*output && *rest)
		output = ft_strdup(rest);
	return (output);
}
