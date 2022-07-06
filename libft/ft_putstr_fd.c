/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:12:43 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 12:12:45 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* void ft_putstr_fd(char *s, int fd)
* c - The string to output.
* fd - The file descriptor on which to write.
*
* Outputs the string ’s’ to the given file descriptor.
*
* Return: None.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}
