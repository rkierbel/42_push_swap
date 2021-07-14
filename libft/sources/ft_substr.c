/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:08:46 by rkierbel          #+#    #+#             */
/*   Updated: 2021/04/03 13:30:39 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	i = 0;
	new = (char *)malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = (char)s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
