/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:44:34 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/05 17:44:51 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memset(void *s, int c, size_t n)
{
	size_t a = 0;
	unsigned char *ptr = s;
	unsigned char value = (unsigned char) c;
	
	while (a < n)
	{
		ptr[a] = value;
		a++;
	}
	return (ptr);
}