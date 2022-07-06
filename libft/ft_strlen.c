/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:57:47 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:57:48 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * size_t ft_strlen(const char *str)
 *
 * Calculates the length of the string pointed
 * to by str, excluding the terminating null byte ('\0').
 *
 * Return: number of bytes in the string
 * pointed to by str.
 */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end != '\0')
		end++;
	return (end - str);
}
