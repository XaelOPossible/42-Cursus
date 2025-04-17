/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:05:18 by axemicha          #+#    #+#             */
/*   Updated: 2025/04/17 12:25:02 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_doubles(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_params(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_limits(const char *str, int sign)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + (str[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_nbr(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+')
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		if (!str[i + 1])
			return (0);
	}
	return (check_limits(str, sign));
}

static void	check_array_values(char **array, int split_flag)
{
	int		i;
	long	value;

	i = 0;
	while (array[i])
	{
		value = ft_atoi(array[i]);
		if (value < INT_MIN || value > INT_MAX || !check_nbr(array[i]))
		{
			if (split_flag)
				ft_free(array);
			error_msg("ERROR");
		}
		i++;
	}
}

void	check_input(int argc, char **argv)
{
	char	**tmp_array;
	int		split_flag;

	split_flag = 0;
	if (argc == 2)
	{
		tmp_array = ft_split(argv[1], ' ');
		if (!tmp_array || !tmp_array[0])
			error_msg("ERROR");
		split_flag = 1;
	}
	else
		tmp_array = argv + 1;
	if (check_doubles(tmp_array))
	{
		if (split_flag)
			ft_free(tmp_array);
		error_msg("ERROR");
	}
	check_array_values(tmp_array, split_flag);
	if (split_flag)
		ft_free(tmp_array);
}
