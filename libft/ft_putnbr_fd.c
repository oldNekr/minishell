/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:27:47 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:27:48 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* void ft_putnbr_fd(int nb, int fd)
* nb - The integer to output.
* fd - The file descriptor on which to write.
*
* Outputs the integer ’nb’ to the given file
* descriptor.
*
* Return: None.
*/

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
	}
	if (nb <= -10)
	{
		ft_putnbr_fd(-(nb / 10), fd);
		ft_putnbr_fd(-(nb % 10), fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		if (nb < 0)
			nb = -nb;
		ft_putchar_fd('0' + nb, fd);
	}
}
