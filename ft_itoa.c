#include <stdlib.h>
#include <string.h>

char	*max_num(char *number)
{
	strlcpy(number, "-2147483648", 12);
	return (number);
}

char	*strrev(char *number)
{
	int		len;
	int		i;
	int		j;
	char	collect;

	i = 0;
	j = strlen(number) - 1;
	len = strlen(number) / 2;
	if (*number == '-')
		i = 1;
	while (len--)
	{
		collect = *(number + i);
		*(number + i) = *(number + j);
		*(number + j) = collect;
		i++;
		j--;
	}
	return (number);
}

char	*negative(char *number, int *n)
{
	*n *= -1;
	*number = '-';
	return (number);
}

int	intlen(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		count += 1;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*number;
	char	*start;

	number = malloc((intlen(n) + 1) * sizeof(char));
	if (!number)
		return (NULL);
	start = number;
	if (n == -2147483648)
		return (max_num(number));
	if (n < 0)
		negative(number++, &n);
	while (n >= 10)
	{
		*number = (n % 10) + 48;
		number++;
		n /= 10;
	}
	*number++ = n + 48;
	*number = '\0';
	return (strrev(start));
}