/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:55:17 by axemicha          #+#    #+#             */
/*   Updated: 2024/11/06 17:19:49 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_isalpha(int c)
{
	if ((c < 65 || c > 90)
		&& (c < 97 || c > 122))
	{
		return (0);
	}
	return (1);
}
 
int main()
{
	// printf("1 : %d\n", isascii(0));
	// printf("1 : %d\n", isascii('z'));
	// printf("1 : %d\n", isascii('A'));
	// printf("1 : %d\n", isascii('Z'));
	// printf("1 : %d\n", isascii('0'));
	// printf("0 : %d\n", isascii('9'));
	// printf("0 : %d\n", isascii('2'));
	// printf("1 : %d\n", isascii('4'));
	// printf("1 : %d\n", isascii('6'));
	char buffer1[10];
	char buffer2[10];
	int arr[10];

	memset(buffer1, 65, sizeof(buffer1));
	tmemset(buffer2, 65, sizeof(buffer2));
	tmemset(arr, 65, sizeof(arr));
	
	for (int i = 0; i < 10; i++) {
        printf("%c ", buffer1[i]);  // Affichera "A A A A A A A A A A"
    }
	printf("\n");
	for (int i = 0; i < 10; i++) {
        printf("%c ", buffer2[i]);  // Affichera "A A A A A A A A A A"
    }
	printf("\n");
	for (int i = 0; i < 10; i++) {
        printf("%c ", arr[i]);  // Affichera "A A A A A A A A A A"
    }
	printf("\n");
	for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);  // Affichera "A A A A A A A A A A"
	}
	return (0);
}