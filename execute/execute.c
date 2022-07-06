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

void	wait_all(t_data *data)
{
	int		pid;
	int		status;
	t_cmd	*tmp;

	tmp = data->cmds->next;
	while (tmp != data->cmds)
	{
		pid = waitpid(0, &status, 0);
		if (pid != 0)
			if (WIFEXITED(status))
				data->exit_code = WEXITSTATUS(status);
		if (tmp->outfile >= 0)
			close(tmp->outfile);
		if (tmp->infile >= 0)
			close(tmp->infile);
		tmp = tmp->next;
	}
}

void	run_chain(t_data *data, int lpipe[], int rpipe[])
{
	t_cmd	*tmp;

	pipe(rpipe);
	fork_and_chain(data, data->cmds->next, NULL, rpipe);
	lpipe[0] = rpipe[0];
	lpipe[1] = rpipe[1];
	tmp = data->cmds->next->next;
	while (tmp != data->cmds->prev)
	{
		pipe(rpipe);
		fork_and_chain(data, tmp, lpipe, rpipe);
		close(lpipe[0]);
		close(lpipe[1]);
		lpipe[0] = rpipe[0];
		lpipe[1] = rpipe[1];
		tmp = tmp->next;
	}
	fork_and_chain(data, data->cmds->prev, lpipe, NULL);
	close(lpipe[0]);
	close(lpipe[1]);
}

void	execute(t_data *data)
{
	int		lpipe[2];
	int		rpipe[2];
	t_cmd	*cmd;

	cmd = data->cmds->next;
	if (is_built_in(cmd->args[0]) && cmd->next == data->cmds
		&& cmd->to_skip == 0)
		launch_builtin(data, cmd);
	else
	{
		if (cmd->next == data->cmds)
			fork_and_chain(data, cmd, NULL, NULL);
		else
			run_chain(data, lpipe, rpipe);
		wait_all(data);
	}
}
