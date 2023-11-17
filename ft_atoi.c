int	ft_atoi(const char *str)
{
	long int	number;
	int			minus;

	number = 0;
	minus = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	while (*str)
	{
		if (!(*str == 32 || *str == 0 || *str == 9))
			number = 0;
		str++;
	}
	if (minus == 1)
		number *= -1;
	return (number);
}
