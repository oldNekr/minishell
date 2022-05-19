#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/inc/libft.h"
//# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
//# include <string.h>
//# include <unistd.h>
# include <limits.h>

# define CYAN "\033[0;96m"
# define DEFAULT "\033[0;39m"

char **g_env;

typedef struct s_mini
{
	char	**shell;
	char	*env;
	struct s_mini *next;
}			t_mini;

int	ft_pwd(void);


#endif
