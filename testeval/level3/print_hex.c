#include <unistd.h>

// void	print_hex(int p)
// {
// 	char *str;

// 	str = "0123456789abcdef";
// 	if (p == 0)
// 		write (1, "0", 1);
// 	while (p)
// 	{
// 		write(1, &str[p % 16], 1);
// 		p /= 16;
// 	}
// }

// int	ft_atoi(const char *nptr)
// {
// 	int	neg;
// 	int	num;

// 	neg = 1;
// 	num = 0;
// 	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
// 	{
// 		nptr++;
// 	}
// 	if (*nptr == '+' || *nptr == '-')
// 	{
// 		if (*nptr == '-')
// 		{
// 			neg *= -1;
// 		}
// 		nptr++;
// 	}
// 	while (*nptr >= '0' && *nptr <= '9')
// 	{
// 		num = num * 10 + (*nptr - 48);
// 		nptr++;
// 	}
// 	return (num * neg);
// }

// int		main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 		print_hex(ft_atoi(argv[1]));
// 	write(1, "\n", 1);
// 	return (0);
// }

void	ft_printhex(unsigned long long num)
{
	if (num >= 16)
	{
		ft_printhex(num / 16);
		ft_printhex(num % 16);
	}
	else
	{
		if (num <= 9)
			write(1, (num + '0'), 1);
		else
			write(1, (num - 10 + 'a'), 1);
	}
}

int main (int argc, char **argv)
{
	
}