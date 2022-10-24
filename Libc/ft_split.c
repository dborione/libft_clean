/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:33:30 by dborione          #+#    #+#             */
/*   Updated: 2022/10/24 15:57:03 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static int	ft_tab_len(const char *s, char c)
{
	unsigned long	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	if (c == '\0')
		return (1);
	while (i < ft_strlen(s))
	{
		while (s[i] != c)
		{
			i++;
			if (s[i] == c)
			{
				count++;
				j = i;
			}
		}
		j++;
		i++;
	}
	return (count);
}

static char	**ft_fill_tab(char **tab, char *ptr, const char *s, char c)
{
	size_t	i;
	int	j;
	int	x;
	
	i = 0;
	j = 0;
	x = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] && s[i] != c)
		{
			i++;
			if (s[i] == c || s[i] == '\0')
			{
				ptr = ft_substr(s, j, i - j);
				tab[x] = ptr;
				x++;
				j = i;
			}
		}
		j++;
		i++;
	}
	tab[x] = NULL;
	return (tab);
}

static int	ft_is_c_in_s(const char *s, char c)
{
	int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	**ft_count_zero(char **tab, const char *s, char *ptr, char c, int count)
{
	if (ft_is_c_in_s(s, c) == 0 && count == 0)
	{
		tab = malloc(sizeof(*tab) * 2);
		if (!tab)
			return (0);
		tab[0] = ptr;
		tab[1] = NULL;
	}
	else
	{
		tab = malloc(sizeof(*tab));
		if (!tab)
			return (0);
		tab[0] = NULL;	
	}
	return (tab);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	char	*ptr;
	int		count;
	char	*s2;

	s2 = (char *)s;
	if (!s)
		return (NULL);
	tab = NULL;
	ptr = NULL;
	if (ft_strlen(s) == 0)
		return (ft_count_zero(tab, s, ptr, c, 0));
	count = ft_tab_len(s, c);
	ptr = ft_strdup(s);
	if (count == 0)
		return (ft_count_zero(tab, s, ptr, c, count));
	tab = malloc(sizeof(*tab) * (count + 1));
	if (!tab)
		return (0);
	tab = ft_fill_tab(tab, ptr, s, c);
	return (tab);
}

/*int	main()
{
	const char *s = "";
	char **tab = ft_split(s, 'z');
	if (!s)
	{
		//free(tab);	
		return (0);
	}
	
	unsigned long 	i = 0;
	int		j = 0;
//	printf("%lu\n", sizeof(tab[50]));
	//printf("%lu\n", sizeof(s));
	while(tab[i])
    {
		while(tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		printf("[]");
		j = 0;
		i++;
	}
	//printf("%s\n", tab[i + 1]);
	return (0);
}*/
