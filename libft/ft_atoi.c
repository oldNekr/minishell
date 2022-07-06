/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:09:20 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:09:21 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * int ft_atoi(const char *nptr)
 *
 * Converts the initial portion of the string pointed to by nptr to int.
 *
 * Return: The converted value or 0 on error.
 */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	sign;
	int		result;

	while (ft_isspace(*nptr))
		nptr++;
	sign = '+';
	if (*nptr == '-')
	{
		sign = '-';
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign == '-')
		return (-result);
	return (result);
}
