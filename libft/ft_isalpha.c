/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:55:34 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:55:36 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * int ft_isalpha(int c)
 *
 * Checks for an alphabetic character
 * 
 * Return: 0 or 1.
 */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
