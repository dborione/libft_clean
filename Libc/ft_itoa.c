/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:12:59 by dborione          #+#    #+#             */
/*   Updated: 2022/10/20 17:12:54 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_getdigits_nbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr >= -9 && nbr <= 9)
		return (1);
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_pos(long nbr, char *str, int i)
{
	str[i] = '\0';
	while (i > 0)
	{
		str[--i] = ((nbr % 10) + '0');
		if (nbr > 9)
			nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa_neg(long nbr, char *str, int i)
{
	str[i] = '\0';
	nbr = -nbr;
	while (i > 1)
	{
		str[0] = '-';
		str[--i] = ((nbr % 10) + '0');
		if (nbr > 9)
			nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		i;
	long	nbr2;

	nbr2 = nbr;
	i = ft_getdigits_nbr(nbr2);
	if (nbr2 < 0)
	{
		i++;
		str = malloc(sizeof(*str) * (i + 1));
		if (!str)
			return (0);
		str = ft_itoa_neg(nbr2, str, i);
	}
	else
	{
		str = malloc(sizeof(*str) * (i + 1));
		if (!str)
			return (0);
		str = ft_itoa_pos(nbr2, str, i);
	}
	return (str);
}

/*int	main()
{
	printf("%s\n", ft_itoa(INT_MAX));
	return (0);
}*/
