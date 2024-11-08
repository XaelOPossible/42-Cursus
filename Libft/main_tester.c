/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:27:05 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/08 17:12:32 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char const *str = "HelllllleeeeeeCoucoullllllhhhhheeee";
	char const *set = "Hhel";

	printf("%s", ft_strtrim(str, set));
}
