/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:08:54 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:08:55 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * char *ft_strnstr (const char *big, const char *little, size_t len)
 *
 * Finds the first occurrence of the substring little
 * in the string big.  The terminating null bytes ('\0')
 * are not compared.
 *
 * Return: pointer to the beginning of the located substring,
 * or NULL if the substring is not found.
 */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (little[j] != '\0' && big[i + j] == little[j]
				&& (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
