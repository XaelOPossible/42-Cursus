/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:15:51 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 17:24:45 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p1;
	unsigned char *p2;
	size_t i;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	i = 0;
	while (p1[i] == p2[i] && p1[i] && p2[i] && i < n)
	{
		i++;
	}
	return(p1[i] - p2[i]);
}