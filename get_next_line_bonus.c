/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isidki <isidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:57:49 by isidki            #+#    #+#             */
/*   Updated: 2023/01/07 00:00:03 by isidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_buff(int fd, char *hold)
{
	int		ret;
	char	*buffer;
	char	*str;

	ret = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(hold), NULL);
	buffer[0] = 0;
	while (ret != 0 && !ft_strchr(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (free(buffer), NULL);
		buffer[ret] = 0;
		str = ft_strjoin(hold, buffer);
		free(hold);
		hold = str;
	}
	return (free(buffer), hold);
}

char	*update(char *hold)
{
	int		i;
	char	*str;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (hold[i] == '\n')
		i++;
	str = ft_substr(hold, i, ft_strlen(hold + i));
	return (free(hold), str);
}

char	*getlinedyali(char *hold)
{
	int		i;
	char	*str;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	str = ft_substr(hold, 0, i + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*hold[10241];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10240)
		return (NULL);
	hold[fd] = read_buff(fd, hold[fd]);
	if (!hold[fd])
		return (NULL);
	if (!*hold[fd])
		return (free(hold[fd]), hold[fd] = NULL, NULL);
	return (line = getlinedyali(hold[fd]), hold[fd] = update(hold[fd]), line);
}
