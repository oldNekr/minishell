/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshandy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:56:51 by pshandy           #+#    #+#             */
/*   Updated: 2021/10/14 11:56:52 by pshandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>

# define F_ALLOC -42

/* Возможные функции токенов */

enum e_token {
	INPUT,
	HEREDOC,
	TRUNC,
	APPEND,
	PIPE,
	CMD,
	ARG
};

/* Вспомогательные списки для хэшмапы на открытом хэшировании */

typedef struct s_hashmap
{
	char				*key;
	char				*value;
	struct s_hashmap	*prev;
	struct s_hashmap	*next;
}		t_hashmap;

/* Элемент двуанаправленного списка токенов */

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}			t_token;

/* Элемент двунаправленного списка команд */

typedef struct s_cmd
{
	char			**args;
	int				args_num;
	int				infile;
	int				outfile;
	int				to_skip;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}			t_cmd;

/* Структура для хранения основных данных программы */

typedef struct s_data
{
	int			hashmap_size;
	int			exit_code;
	t_token		*head;
	t_cmd		*cmds;
	t_hashmap	**hashmap;
}		t_data;

/* ------------------ env ------------------ */

int			init_hashmap(t_data *data, int size);
int			add_to_hashmap(t_data *data, char *key, char *value);
int			del_from_hashmap(t_data *data, char *key);
int			handle_envp(t_data *data, char **envp);
int			envp_size(char	**envp);
char		*get_value(t_data *data, char *key);
char		**ft_split2(char *str, char token);
char		**hashmap_to_array(t_data *data);
void		free_hashmap(t_data *data);
t_hashmap	*get_record(t_data *data, char *key);

int			_ft_lstinit(t_hashmap **hashmap);
int			_ft_lstadd_back(t_hashmap **hashmap, char *key, char *value);
int			_ft_lstdel(t_hashmap **hashmap, char *key);
void		print_list(t_hashmap **hashmap);
void		_ft_lstclear(t_hashmap **lst);

/* -----------------signals----------------- */

void		init_signal(void);

/* -----------------tokenize---------------- */

int			is_special_char(char *str);
int			quote_pick(char c, int *single_quote, int *double_quote);
int			create_token_list(t_data *data, char *line);
int			token_lstadd_back(t_token **token_list, char *str, int type);
int			token_lstinit(t_token **token_list);
int			tokenize(t_data *data, char *line);
int			check_quotes(char *buf);
int			is_operator(t_token *t);
int			validate(t_data *data);
char		*get_special_char(char **line);
char		*get_token_str(char **line);
char		*handle_dollar(t_data *data, char *str);
void		add_char(char **line, char c);
void		token_lstclear(t_token **lst);
void		set_type(t_token *token);

/* ------------------ cmd ------------------ */

int			cmd_lstinit(t_cmd **cmd_list);
int			cmd_lstadd_back(t_cmd **cmd_list, t_cmd *cmd);
int			ft_heredoc(t_data *data, char *args);
char		**add_str(char **arr, char *str);
void		cmd_lstclear(t_cmd **lst);
void		get_cmd(t_data *data);
t_cmd		*cmd_create_elem(void);

/* -----------------builtin----------------- */

int			is_letter(char *str);
int			ft_cd(t_data *data, char **args);
int			ft_echo(char **args);
int			ft_env(t_data *data);
int			ft_export(t_data *data, char *str);
int			print_exp(t_data *data);
int			ft_pwd(void);
int			ft_unset(t_data *data, char *str);
int			is_number(char *str);
void		ft_exit(t_data *data, char **args);

/* -----------------execute----------------- */

int			is_built_in(char *cmd);
char		*is_cmd_present(t_data *data, t_cmd *cmd);
void		execute(t_data *data);
void		launch_builtin(t_data *data, t_cmd *tmp);
void		select_and_exec(t_data *data, t_cmd *cmd);
void		fork_and_chain(t_data *data, t_cmd *cmd, int *lpipe, int *rpipe);
void		change_lvl(t_data *data);

#endif
