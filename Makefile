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
SRC =	\
SRCB =	\
BIN_DIR		= bin
SRC_DIR		= src
SRCB_DIR	= srcb
OBJ_DIR		= obj
OBJB_DIR	= objb

BIN		= minishell.a
NAME	= $(BIN_DIR)/$(BIN)
INC 	= inc/minishell.h
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJB	= $(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))

CC		=	cc -MD
CFLAGS	=	-Wextra -Werror -Wall
AR		= ar rcs
RM		= rm -rf
MKD		= mkdir -p

# Progress vars---------------------------------------------------------------------------------------------------------
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -lt 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT) -lt 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))

# Make Commands---------------------------------------------------------------------------------------------------------
all: $(NAME)

$(NAME): mandatory bonus
	@printf "\r%100s\r$(GREEN)$(BIN) and bonus is up to date!$(DEFAULT)\n"

mandatory: create_dirs $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@printf "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: create_dirs_bonus $(OBJB)
	@$(AR) $(NAME) $(OBJB)
	@printf "\r%100s\r$(GREEN)$(BIN) bonus is up to date!$(DEFAULT)\n"

$(OBJB_DIR)/%.o: $(SRCB_DIR)/%.c $(INC)
	@$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
	@printf "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
	@$(CC) $(CFLAGS) -c $< -o $@

create_dirs:
	@$(MKD) $(BIN_DIR)
	@$(MKD) $(OBJ_DIR)

create_dirs_bonus:
	@$(MKD) $(BIN_DIR)
	@$(MKD) $(OBJB_DIR)

clean:
	@printf "$(CYAN)Cleaning up object files in $(BIN)...$(DEFAULT)\n"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(OBJB_DIR)

fclean: clean
	@$(RM) $(BIN_DIR)
	@printf "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

re: fclean all

norm:
	@printf "$(CYAN)\nCheking norm for minishell...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourseHeader $(SRC_DIR) $(SRCB_DIR) inc/

git:
	git add .
	git commit -m "lipa"
	git push

.PHONY: all clean fclean re norm git