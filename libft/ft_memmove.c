/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:37:21 by dborione          #+#    #+#             */
/*   Updated: 2022/10/07 12:04:28 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ 

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char *tmp;
	unsigned char *dest2;

	i = 0;
	tmp = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (((unsigned char *)dest) == (void *)0 
		&& ((unsigned char *)src) == (void *)0 && n != 0)
		return (0);
	while (i < n)
	{
		dest2[i] = tmp[i];
		i++;
	}
//	dest2[i] = '\0';
	return (dest2);
}

/*int		main()
{
//	char	str1[]= "thi\xffs i\xfas \0a g\xde\xadood \0nyan\0cat\0 !\r\n";
//	char	dest1[]= "exemple";
	char s1[20]="alightechs";
//	char	str2[]= "thi\xffs i\xfas \0a g\xde\xadood \0nyan\0cat\0 !\r\n";
//	char	dest2[]= "exemple";
	char s2[20]="alightechs";

//	printf("%zu\n", strlen(str1));
	memmove(s1+5, s1, 7);
//	printf("dest1=%s\n", dest1);
	printf("str1=%s\n", s1);

	memmove(s2+5, s2, 7);
//	printf("dest2=%s\n", dest2);
	printf("str2=%s\n", s2);


	return(0);
}*/
