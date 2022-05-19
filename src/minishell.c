/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 02:48:57 by lrosby            #+#    #+#             */
/*   Updated: 2022/05/11 02:48:59 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_(void)
{
	char	*buff;
	t_mini	*shell;
	signal(SIGKILL, sigint);
	signal(SIGINT, sigint);

}

static char	**ft_env(char **envp)
{
	int it;
	int kt;

	it = -1;
	ft_strlen(*envp);
	while (envp[++it])
		it++;
	g_env = (char **) malloc(sizeof (char **) * (it + 1));
	g_env[0] = ft_strdup("0");
	it = 0;
	kt = -1;
	while (envp[++kt])
		g_env[++it] = ft_strdup(envp[kt]);
	g_env[it] = 0;
	return (g_env);
}

int	main(int argc, char **argv, char **envp)
{
	(void )argc;
	(void )argv;
	g_env = ft_env(envp);
	ft
	printf(CYAN"mmassssd\n"DEFAULT);
	printf("qwed");
	return (0);
}
