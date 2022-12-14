/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:55:33 by dborione          #+#    #+#             */
/*   Updated: 2022/10/11 16:46:21 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		len;

	len = ft_strlen(str);
	while (len != -1)
	{
		if (str[len] == (unsigned char)c)
			return (&str[len]);
		len--;
	}
	return (0);
}

/*int	main()
{
	char *str = "bonjour";
	int	c = 'b';

	printf("%s", ft_strrchr(str, c));
	return (0);
}*/
