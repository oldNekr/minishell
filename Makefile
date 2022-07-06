# Color Aliases
DEFAULT	= \033[0;39m
GREEN	= \033[0;92m
BLUE	= \033[0;94m
CYAN	= \033[0;96m
RED		= \033[0;91m

# Make variables
CC			= cc
CFLAGS		= -Wextra -Werror -Wall
RM			= rm -f

INC	= minishell.h
#LIBFT = -L libft -lft


NAME = minishell
LIB = minishell.a

BUILTIN = ft_cd ft_echo ft_env ft_exit ft_export ft_pwd ft_unset

CMD = cmd_list cmd_utils get_cmd

ENV = ft_split2 handle_envp hashmap hashmap2 hashmaplist

EXECUTE = execute execute_utils is_cmd_present launch pipes shlvl

SIGNALS = signals

TOKENIZER = handle_dollar order_check token_list tokenize utils

MAIN = minishell

LIBFT	=	ft_atoi.c		ft_isalpha.c	ft_itoa.c\
			ft_putendl_fd.c	ft_strdup.c		ft_strstr.c\
			ft_strmapi.c	ft_tolower.c	ft_bzero.c\
			ft_isascii.c	ft_memcpy.c		ft_memmove.c\
			ft_putnbr_fd.c	ft_strlcat.c	ft_strncmp.c\
			ft_toupper.c	ft_calloc.c		ft_isdigit.c\
			ft_memchr.c		ft_memset.c		ft_putstr_fd.c\
			ft_strlcpy.c	ft_strnstr.c	ft_isalnum.c\
			ft_isprint.c	ft_memcmp.c		ft_putchar_fd.c\
			ft_strchr.c		ft_strlen.c		ft_strrchr.c\
			ft_striteri.c	ft_substr.c		ft_strjoin.c\
			ft_split.c		ft_strtrim.c\
			ft_strcmp.c		ft_isspace.c		ft_strcpy.c\
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c\

SRC = $(addsuffix .c, $(addprefix builtin/, $(BUILTIN))) \
	  $(addsuffix .c, $(addprefix cmd/, $(CMD))) \
	  $(addsuffix .c, $(addprefix env/, $(ENV))) \
	  $(addsuffix .c, $(addprefix execute/, $(EXECUTE))) \
	  $(addsuffix .c, $(addprefix signals/, $(SIGNALS))) \
	  $(addsuffix .c, $(addprefix tokenizer/, $(TOKENIZER))) \
	  $(addprefix libft/, $(LIBFT))\
	  $(addsuffix .c, $(MAIN)) \

OBJ = $(SRC:%.c=%.o)

# Make Commands
all:	$(NAME)

$(NAME):  $(OBJ)
	@printf "\n$(BLUE)Compiling $(NAME)...$(DEFAULT)"
	@ar rcs $(LIB) $?
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) -lreadline
	@printf "\n$(GREEN)Ready!\n$(DEFAULT)"

%.o:	%.c
	@printf "$(BLUE)Generation $(CYAN)%-33.33s\r$(DEFAULT)" $@
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@#make clean -C libft/
#	@printf "$(RED)Cleaning up object files in libft...$(DEFAULT)\n"
	@$(RM) $(OBJ)
	@printf "$(RED)Cleaning up object files in $(NAME)...$(DEFAULT)\n"

fclean:		clean
	@#make fclean -C libft/
#	@printf "$(RED)Removed libft$(DEFAULT)\n"
	@$(RM) $(NAME) $(LIB)
	@printf "$(RED)Removed $(NAME)$(DEFAULT)\n"

re:			fclean all

.PHONY:	all clean fclean re
