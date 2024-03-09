/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebriere <ebriere@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:04:04 by ebriere           #+#    #+#             */
/*   Updated: 2023/11/26 21:52:14 by ebriere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len_s;
	size_t		i;
	char		*s2;

	len_s = ft_strlen((char *)s);
	s2 = malloc(len_s + 1 * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len_s + 1)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
