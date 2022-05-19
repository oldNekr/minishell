/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 02:49:07 by lrosby            #+#    #+#             */
/*   Updated: 2022/05/11 02:49:09 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*get_env_path(t_mini *env, const char *var, size_t len)
{
	char	*oldpwd;
	int 	it;
	int		kt;
	int		size;

	while (env && env->next != NULL)
	{

	}
}

static int update_pwd(t_mini *env)
{
	char	cwd[PATH_MAX];
	char	*oldpwd;

	if (getcwd(cwd, PATH_MAX) == NULL || !(oldpwd = ft_strjoin("OLDPWD=", cwd)))
		return (EXIT_FAILURE);
	if (is_in_env(env, oldpwd) == 0)
		env_add(oldpwd, env);
	ft_memdel(oldpwd);
	return (EXIT_SUCCESS);

}

static int	path(int flag, t_mini *env)
{
	int		it;
	char	*env_path;

	env_path = NULL;
	if (flag == 0)
	{
		update_pwd(env);
		env_path = get_env_path(env, "HOME", 4);
	}

}

int	ft_cd(char **argc, t_mini *env)
{
	int	it;

	if (!argc[1])
		return (path(0, env));
}