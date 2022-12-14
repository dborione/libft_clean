/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:40:06 by dborione          #+#    #+#             */
/*   Updated: 2022/10/14 15:01:01 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char const	*s2;
	char const	*s3;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	s2 = malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (0);
	while (s1[i] && s1[i] == set[j])
	{
		i++;
		j++;
	}
	s2 = &s1[i];
	s3 = ft_strdup(s2);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(set) - 1;
	while (i > 0 && s1[i] == set[j])
	{
		i--; 
		j--;
	}
	((char *)s3)[i] = '\0';
	return ((char *)s3);
}

/*int	main()
{
	char *s1 = "ababcdeab";
	char const *set = "ab";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
