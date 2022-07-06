/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:11:48 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 14:15:40 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* char	*ft_itoa(int n)
*
* Allocates (with malloc(3)) and returns a string representing
* the integer received as an argument.
* Negative numbers must be handled.
*
* Return: The string representing the integer.
* NULL if the allocation fails.
*/

#include "libft.h"

static int	ft_getsize(int n)
{
	int	size;

	size = 1;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static int	ft_getsign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_getsize(n);
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = 48;
	if (n < 0)
		str[0] = '-';
	str[size - 1] = '\0';
	while (n != 0 && size--)
	{
		str[size - 1] = ft_getsign(n) * (n % 10) + '0';
		n = n / 10;
	}
	return (&str[0]);
}
