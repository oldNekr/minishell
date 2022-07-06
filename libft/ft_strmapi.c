/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:43:10 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:44:03 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
* s - The string on which to iterate.
* f - The function to apply to each character.
*
* Applies the function ’f’ to each character of
* the string ’s’ , and passing its index as first
* argument to create a new string (with malloc(3))
* resulting from successive applications of ’f’.
*
* Return: The string created from the successive applications
* of ’f’. Returns NULL if the allocation fails.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	newstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (newstr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
