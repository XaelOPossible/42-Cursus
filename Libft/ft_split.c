/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:59:27 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/12 17:24:30 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*malloc_mots(char *str, char c)
{
	char	*mots;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	mots = (char *)malloc(sizeof(char) * (len + 1));
	if (!mots)
		return (NULL);
	while (i < len)
	{
		mots[i] = str[i];
		i++;
	}
	mots[i] = '\0';
	return (mots);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
		}
		free(tab);
	}
}

static char	**populate_tab(char **tab, const char *s, char c, int *j)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[*j] = malloc_mots((char *)&s[i], c);
			if (!tab[*j])
			{
				free_tab(tab);
				return (NULL);
			}
			(*j)++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	words = count_word((char *)s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	tab = populate_tab(tab, s, c, &j);
	if (tab == NULL)
	{
		free_tab(tab);
		return (NULL);
	}
	tab[j] = NULL;
	return (tab);
}
