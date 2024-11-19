/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:58:24 by marvin            #+#    #+#             */
/*   Updated: 2024/11/15 11:58:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void inverse_tab(int start, int size, char buff)
{
	int i;
	int j;
	char temp;

	i = start;
	j = size - 1;
	while (i < j)
	{
		temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
		i++;
		j--;
	}
}

void	ft_print_hexadecimal(void *ptr)
{
	unsigned long adress;
	const char *hexatab;
	char buffer[20];
	int size;
	int start;
	
	adress = (unisgned long)ptr;
	buffer[size++] = '0'
	buffer[size++] = 'x'
	start = size;
	hexatab = "0123456789abcdef";

	if (adress == 0)
	{
		buffer[size++] = '0';
	}
	else
	{
		while (adress > 0)
		{
			buffer[taille++] = hexatab[adress % 16];
			adress /= 16;
		}
	}
	inverse_tab(start, size, buffer);
	buffer[size++] = '\n';
	write(1, buffer, taille);
}
int main()
{
	int x = 42;
	int *ptr = &x;
	ft_print_hexadecimal(ptr);
	return (0);
}
