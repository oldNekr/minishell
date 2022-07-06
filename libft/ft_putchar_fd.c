/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:18:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:18:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* void ft_putchar_fd(char c, int fd)
* c - The character to output.
* fd - The file descriptor on which to write.
*
* Outputs the character
*
* Return: None.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
