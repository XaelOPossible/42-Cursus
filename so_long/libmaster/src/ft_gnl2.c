/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:14:36 by axemicha          #+#    #+#             */
/*   Updated: 2025/01/16 15:16:43 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libmaster.h"

char	*ft_stradd(char *str, char buff)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (ret == NULL)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buff;
	ret[++i] = '\0';
	return (ret);
}

int	gnl(int fd, char **str)
{
	char			buff;
	int				ret;

	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		*str = ft_stradd(*str, buff);
		if (buff == '\n')
			return (ret);
		else
			ret += 1;
		ret = read(fd, &buff, 1);
	}
	if (ret == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}
