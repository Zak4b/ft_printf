static int	calc_str_len(int value, int base_len)
{
	int		len;
	if (value <= 0)
		len = 1;
	else
		len = 0;
	while (value)
	{
		value /= base_len;
		len++;
	}
}

static int	get_char_pos(char *string, char element)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == element)
			return (i);
		i++;
	}
	return (-1);
}
char	*ft_string_from_base(int nbr, char *base)
{
	char	base_len;
	char	*str;
	int		str_len;
	int		char_count;
	long	nb;

	nb = nbr;
	base_len = ft_strlen(base);
	char_count = 0;
	str_len = calc_str_len(nbr, base_len);
	str = malloc(sizeof(char) * (str_len + 1));
	str[str_len] = '\0';
	if (nb == 0)
		str[0] = base[0];
	if (nb < 0)
	{
		str[str_len - 1] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[char_count++] = base[nb % base_len];
		nb = nb / base_len;
	}
	return (ft_rev_str(str));
}