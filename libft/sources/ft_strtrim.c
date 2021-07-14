/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:40:43 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/03 17:16:18 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_inset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	len = 0;
	start = 0;
	while (s1[start] && ft_inset(s1[start], set))
		start++;
	len = ft_strlen(s1);
	while (len > start && ft_inset(s1[len - 1], set))
		len--;
	str = (char *)malloc(sizeof(*s1) * (len - start + 1));
	if (str == NULL)
		return (NULL);
	while (start < len)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}			
