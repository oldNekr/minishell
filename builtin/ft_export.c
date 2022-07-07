/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_letter(char *str)
{
	while (*str)
	{
		if (!ft_isalpha(*str))
			return (0);
		str++;
	}
	return (1);
}

static void	sort_exp(char **array, int len)
{
	char	*tmp;
	int		ord;
	int		it;

	ord = 0;
	while (array && ord == 0)
	{
		ord = 1;
		it = -1;
		while (++it < len - 1)
		{
			if (ft_strcmp(array[it], array[it + 1]) > 0)
			{
				tmp = array[it];
				array[it] = array[it + 1];
				array[it + 1] = tmp;
				ord = 0;
			}
		}
	}
}

int	print_exp(t_data *data)
{
	char	**array;
	int		len;
	int		it;

	array = hashmap_to_array(data);
	len = envp_size(array);
	sort_exp(array, len);
	it = -1;
	while (++it < len)
	{
		printf("declare -x %s\n", array[it]);
		free(array[it]);
	}
	free(array);
	return (EXIT_SUCCESS);
}

int	ft_export(t_data *data, char *str)
{
	char		**strarr;
	t_hashmap	*tmp;

	if (!str || ft_strchr(str, '=') == 0 || *str == '=')
		return (1);
	if (ft_isdigit(str[1]))
	{
		printf("Not a valid identifier\n");
		return (EXIT_FAILURE);
	}
	strarr = ft_split2(str, '=');
	tmp = get_record(data, strarr[0]);
	if (tmp == NULL)
		add_to_hashmap(data, strarr[0], strarr[1]);
	else
	{
		free(tmp->value);
		tmp->value = strarr[1];
		free(strarr[0]);
	}
	free(strarr);
	return (0);
}
