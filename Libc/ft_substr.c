/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:43:57 by dborione          #+#    #+#             */
/*   Updated: 2022/10/21 12:23:46 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		start = 0;
		len = 0;
	}
	if (len > s_len)
		len = s_len;
	s2 = malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (0);
	ft_strlcpy(s2, &s[start], len + 1);
	return (s2);
}

/*int	main()
{
	char *s = "";
	printf("%s\n", ft_substr(s, 1, 1));
	printf("%zu\n", ft_strlen(s));
	return (0);
}*/
