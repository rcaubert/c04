/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:17:14 by raubert           #+#    #+#             */
/*   Updated: 2019/08/12 14:30:58 by raubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		ft_test(char *base)
{
	char	*test;
	int		i;
	int		j;

	test = base;
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[i] != test[j] && test[j])
			j++;
		if (base[i] == test[j])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		blen;
	char	*test;
	int		n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	n = nbr;
	test = base;
	blen = ft_strlen(base);
	if (ft_test(base) == 0)
		return ;
	while (*test)
	{
		if (*test == '\0' || blen <= 1 || *test < '0' ||
				(*test > '9' && *test < 'A') || (*test > 'Z' && *test < 'a') ||
				(*test > 'z' && *test < 127))
			return ;
		test++;
	}
	if (n >= blen)
		ft_putnbr_base((n / blen), base);
	ft_putchar(base[n % blen]);
}
