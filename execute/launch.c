/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:56:51 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:56:52 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	launch_builtin(t_data *data, t_cmd *tmp)
{
	int	tmpin;

	tmpin = -42;
	if (tmp->outfile >= 0)
	{
		tmpin = dup(1);
		dup2(tmp->outfile, 1);
	}
	select_and_exec(data, tmp);
	if (tmp->outfile >= 0)
	{
		dup2(tmpin, 1);
		close(tmpin);
	}
}

static void	ft_exp(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[++i])
		data->exit_code = ft_export(data, cmd->args[i]);
	if (i == 1 && cmd->args[1] == NULL)
		data->exit_code = print_exp(data);
}

void	select_and_exec(t_data *data, t_cmd *cmd)
{
	int	i;

	if (ft_strcmp("echo", cmd->args[0]) == 0)
		data->exit_code = ft_echo(&(cmd->args[1]));
	else if (ft_strcmp("pwd", cmd->args[0]) == 0)
		data->exit_code = ft_pwd();
	else if (ft_strcmp("cd", cmd->args[0]) == 0)
		data->exit_code = ft_cd(data, cmd->args);
	else if (ft_strcmp("env", cmd->args[0]) == 0)
		data->exit_code = ft_env(data);
	else if (ft_strcmp("export", cmd->args[0]) == 0)
		ft_exp(data, cmd);
	else if (ft_strcmp("unset", cmd->args[0]) == 0)
	{
		i = 0;
		while (cmd->args[++i])
			data->exit_code = ft_unset(data, cmd->args[i]);
	}
	else if (ft_strcmp("exit", cmd->args[0]) == 0)
		ft_exit(data, cmd->args);
}
