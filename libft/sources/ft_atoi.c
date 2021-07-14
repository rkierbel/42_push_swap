/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 09:56:52 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/11 15:56:34 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_overflow(char *str)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (!ft_isdigit(str[i]))
		if (str[i++] == '-')
			l = 1;
	while (ft_isdigit(str[i]))
	{
		if (str[i++] == '9')
			k++;
		j++;
	}
	if (l == 1 && k == 26)
		return (0);
	else if (j > 19)
		return (-1);
	else
		return (0);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_xval(int rslt, unsigned long long xval, int sign)
{
	unsigned long long	min;
	unsigned long long	max;

	min = 9223372036854775808U;
	max = 9223372036854775807U;
	if (xval > max && sign == 1)
		return (-1);
	if (xval > min && sign == -1)
		return (0);
	return (rslt * sign);
}

int	ft_intsign(char *str, int i, int *sign)
{
	if (str[i] == '-')
	{
		*sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	int					rslt;
	unsigned long long	xval;
	char				*p_str;

	if (str[0] == '\0')
		return (0);
	if (ft_check_overflow((char *)str) == -1)
		return (-1);
	i = 0;
	sign = 1;
	rslt = 0;
	xval = 0;
	p_str = (char *)(str);
	while (ft_isspace(p_str[i]))
		i++;
	i = ft_intsign(p_str, i, &sign);
	while (p_str[i] >= '0' && p_str[i] <= '9')
	{
		rslt = rslt * 10 + p_str[i] - '0';
		xval = xval * 10 + p_str[i] - '0';
		i++;
	}
	return (ft_xval(rslt, xval, sign));
}
