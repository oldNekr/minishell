# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 22:06:21 by lrosby            #+#    #+#              #
#    Updated: 2021/10/14 22:10:28 by lrosby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases---------------------------------------------------------------------------------------------------------
DEFAULT	= \033[0;39m
GREEN	= \033[0;92m
BLUE	= \033[0;94m
CYAN	= \033[0;96m

# Make variables--------------------------------------------------------------------------------------------------------
BIN_DIR	= bin
SRC_DIR	= src
OBJ_DIR	= obj

BIN		= minishell
NAME	= $(BIN_DIR)/$(BIN)
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INC 	= inc/minishell.h
LIBFT	= -L ./libft/bin/ -lft

CC		= cc -MD
CFLAGS	= -Wextra -Werror -Wall
RM		= rm -rf
MKD		= mkdir -p

SRC = $(wildcard src/*.c)

# Progress vars---------------------------------------------------------------------------------------------------------
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -lt 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# Make Commands---------------------------------------------------------------------------------------------------------
all: $(NAME)

$(NAME): create_dirs compile_other $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@
	@printf "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

compile_other:
	@if [ ! -d "libft" ]; then \
		git clone git@github.com:oldNekr/libft.git; \
	fi
	@make all -C libft/

create_dirs:
	@$(MKD) $(BIN_DIR)
	@$(MKD) $(OBJ_DIR)

clean:
	@printf "$(CYAN)Cleaning up object files in $(BIN)...$(DEFAULT)\n"
	@if [ -d "libft" ]; then \
		  make clean -C libft; \
	fi
	@$(RM) $(OBJ_DIR)

fclean: clean
	@if [ -d "libft" ]; then \
		printf "$(CYAN)Removed libft$(DEFAULT)\n"; \
		$(RM) ./libft; \
	fi
	@printf "$(CYAN)Removed $(NAME)$(DEFAULT)\n"
	@$(RM) -r $(BIN_DIR)

re: fclean all

norm:
	@printf "$(CYAN)\nCheking norm for $(BIN)...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourseHeader $(SRC_DIR) inc/

git:
	git add .
	git commit -m "lipa"
	git push git@github.com:oldNekr/minishell.git

remove:
	@$(RM) ../$(BIN)

.PHONY: all clean fclean re compile_other create_dirs norm git remove