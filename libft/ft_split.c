/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* char **ft_split(char const *s, char c);
*
* Allocates (with malloc(3)) and returns an array
* of strings obtained by splitting ’s’ using the
* character ’c’ as a delimiter. The array must be
* ended by a NULL pointer.
*
* Return: The array of new strings resulting from the split.
* NULL if the allocation fails.
*/

#include "libft.h"

static size_t	getlen(const char *t, char c)
{
	size_t	i;

	i = 0;
	while (t[i] != c && t[i] != '\0')
		i++;
	return (i);
}

static size_t	getsize(const char *s, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			size++;
		i++;
	}
	return (size + 1);
}

static char	**ft_clear(char **str, int j)
{
	while (j)
	{
		free(str[j]);
		j--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	str = (char **)malloc((sizeof(char *) * getsize(s, c)));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			str[j] = ft_substr(&s[i], 0, getlen(&s[i], c));
			if (str[j] == NULL)
				return (ft_clear(str, j));
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
