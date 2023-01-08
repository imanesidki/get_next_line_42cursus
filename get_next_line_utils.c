/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:00:22 by isidki            #+#    #+#             */
/*   Updated: 2023/01/06 23:54:58 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int c)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	str = (char *)string;
	len = ft_strlen(string);
	while (i < len || c == '\0')
	{
		if (*(str + i) == (char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*dup;
	int		i;
	int		j;

	if (!s1)
		dup = ft_strdup("");
	else
		dup = ft_strdup(s1);
	str = (char *)malloc(ft_strlen(s2) + ft_strlen(dup) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (dup[++i])
		str[i] = dup[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	free(dup);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	srclen;

	if (!s)
		return (NULL);
	srclen = (unsigned int)ft_strlen(s);
	i = -1;
	if (start >= srclen)
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *) malloc(len + 1);
	if (!sub)
		return (NULL);
	while (++i < len && start[s] && start < srclen)
		*(sub + i) = *(s + start + i);
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *source)
{
	char	*dst;
	int		i;

	i = -1;
	dst = (char *) malloc(ft_strlen(source) + 1);
	if (!dst)
		return (NULL);
	while (source[++i])
		dst[i] = source[i];
	*(dst + i) = '\0';
	return (dst);
}
