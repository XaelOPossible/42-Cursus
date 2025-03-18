
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int i = 8;
	unsigned char bits = 0;

	while(i--)
	{
		bits =	(bits << 1) | (octet & 1);
		octet = (octet >> 1);
	}
	return (bits);
}

void print_bits(unsigned char octet)
{
	int	i;
	unsigned char bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
int main()
{
 	unsigned char test1 = 25;

	print_bits(test1);
	write(1, "\n", 1);
	print_bits(reverse_bits(test1));
	write(1, "\n", 1);
	return (0);
}