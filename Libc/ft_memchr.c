/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:20:17 by dborione          #+#    #+#             */
/*   Updated: 2022/10/10 12:24:22 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cast_c;
	unsigned char	*s2;

	i = 0;
	cast_c = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == cast_c)
			return (&s2[i]);
		i++;
	}
	return (0);
}

/*int	main()
{
	char *str = "bonjourno";
	int	c = 's';

	printf("%s\n", memchr(str, c, 7));
	printf("%s\n", ft_memchr(str, c, 7));
	return (0);
}*/
