/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:31:19 by raubert           #+#    #+#             */
/*   Updated: 2019/08/11 23:42:17 by raubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	unsigned int	res;
	int				neg;

	neg = 0;
	res = 0;
	while (*str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r' ||
			*str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (neg % 2 != 0)
		res = res * -1;
	return (res);
}
