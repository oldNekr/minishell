/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:56:51 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:56:52 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	promt(t_data *data)
{
	int		i;
	char	*buf;

	while (1)
	{
		i = 0;
		buf = readline("minishell >");
		if (!buf)
			break ;
		while (buf[i] && ft_isspace(buf[i]))
			i++;
		if (ft_strlen(&buf[i]) != 0)
			add_history(&buf[i]);
		if (ft_strlen(&buf[i]) != 0 && tokenize(data, &buf[i]))
		{
			cmd_lstinit(&(data->cmds));
			get_cmd(data);
			execute(data);
			token_lstclear(&(data->head));
			cmd_lstclear(&(data->cmds));
		}
		free(buf);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argv;
	data.exit_code = 0;
	if (argc > 1)
		return (printf("У шелла нет аргументов!\n"));
	if (handle_envp(&data, env) == F_ALLOC)
		return (-1);
	init_signal();
	change_lvl(&data);
	promt(&data);
	free_hashmap(&data);
}
