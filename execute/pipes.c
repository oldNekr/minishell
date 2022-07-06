/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:10:42 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/18 12:10:43 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_read(t_cmd *cmd, int *lpipe)
{
	if (lpipe)
	{
		if (cmd->infile >= 0)
			dup2(cmd->infile, STDIN_FILENO);
		else
			dup2(lpipe[0], STDIN_FILENO);
		close(lpipe[0]);
		close(lpipe[1]);
	}
	else
	{
		if (cmd->infile >= 0)
			dup2(cmd->infile, STDIN_FILENO);
	}
}

void	set_write(t_cmd *cmd, int *rpipe)
{
	if (rpipe)
	{
		if (cmd->outfile >= 0)
			dup2(cmd->outfile, STDOUT_FILENO);
		else
			dup2(rpipe[1], STDOUT_FILENO);
		close(rpipe[0]);
		close(rpipe[1]);
	}
	else
	{
		if (cmd->outfile >= 0)
			dup2(cmd->outfile, STDOUT_FILENO);
	}
}

void	mkfork(t_data *data, t_cmd *cmd)
{
	char	*tmp;
	char	**tmpenv;

	if (cmd->to_skip == 1)
		exit(1);
	tmp = NULL;
	if (is_built_in(cmd->args[0]))
		launch_builtin(data, cmd);
	else
	{
		tmp = is_cmd_present(data, cmd);
		if (tmp == NULL)
		{
			if (ft_strlen(cmd->args[0]) != 0)
				perror(cmd->args[0]);
			data->exit_code = 127;
		}
		else
		{
			tmpenv = hashmap_to_array(data);
			execve(tmp, cmd->args, tmpenv);
		}
	}
	exit (data->exit_code);
}

void	fork_and_chain(t_data *data, t_cmd *cmd, int *lpipe, int *rpipe)
{
	if (!fork())
	{
		set_read(cmd, lpipe);
		set_write(cmd, rpipe);
		mkfork(data, cmd);
	}
}
