/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:57:10 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:57:12 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * int ft_isprint(int c)
 *
 * Checks for any printable character including space.
 * 
 * Return: 0 or 1.
 */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
