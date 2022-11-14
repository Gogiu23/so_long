# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdominic <gdominic@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 12:09:31 by gdominic          #+#    #+#              #
#    Updated: 2022/11/14 16:04:49 by gdominic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

-include sources.mk
-include includes.mk 
-include sources_bonus.mk
-include includes_bonus.mk

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

BLACK		=\034[0;30m
RED	 		=	\033[0;31m
GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
BLUE		=	\033[0;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
LIGHT_GRAY	=	\033[0;37m
DARK_GRAY	=	\033[1;30m
LIGHT_RED	=	\033[1;31m
LIGHT_GREEN	=	\033[1;32m
YELLOW		=	\033[1;33m
LIGHT_BLUE	=	\033[1;34m
LIGHT_PURPLE=	\033[1;35m
LIGHT_CYAN	=	\033[1;36m
WHITE		=	\033[1;37m
NO_COLOR	=	\033[0m

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

NAME			= so_long 

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

MAKE_LIB		= libft.a
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g -MMD
RM				= rm -rf
MKFL			= Makefile
MD				= mkdir -p
LIB_DIR			= ./libft

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

INCLUDE_PATH	=./includes

OBJS			=$(SOURCES:.c=.o)
DEPS			=$(SOURCES:.c=.d)

all:
	$(MAKE) -C libft
	@$(MAKE) $(NAME)

%.o:	%.c $(MKFL) $(MAKE_LIB)
	@printf "\r\033[2K\r$(YELLOW)$(NAME): $(LIGHT_BLUE)$<$(RESET)		\r"
	@$(CC) $(CFLAGS) -I $(INCLUDE_PATH_BONUS) -I $(INCLUDE_PATH) -I $(LIB_DIR) -c $< -o $@
	@printf "\r\033[2K\r$(YELLOW)Done......✅ $(LIGHT_BLUE)$<$(RESET)		\n"
	
$(NAME):: $(MAKE_LIB) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@printf "\033[2K\r$(YELLOW)$(NAME): $(LIGHT_BLUE)$<$(RESET)"
	@printf "\033[2K\r$(BLUE)$(NAME): $(GREEN)Compiled and ready![√]$(RESET)\n"

$(NAME):: 
	@printf "\t$(LIGHT_CYAN)$(NAME)Programm already compiled!! $(RESET)\n"

#=-=-=-=-=-=-=-=-=- BONUS =-=-=-=-=-=-=-=-=-=-=-=-=-#

NAME_BONUS			= 

INCLUDE_PATH_BONUS	=./includes_bonus

OBJS_BONUS			=$(SOURCES_BONUS:.c=.o)
DEPS_BONUS			=$(SOURCES_BONUS:.c=.d)

bonus:
	$(MAKE) -C libft
	@$(MAKE) $(NAME_BONUS)

$(NAME_BONUS):: $(MAKE_LIB) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "\033[2K\r$(YELLOW)$(NAME): $(LIGHT_BLUE)$<$(RESET)"
	@printf "\033[2K\r$(BLUE)$(NAME): $(GREEN)Bonus compiled and ready[√]$(RESET)\n"

$(NAME_BONUS)::
	@printf "$(LIGHT_GREEN)$(NAME_BONUS) is up to date✅$(RESET)\n"
	
#=-=-=-=-=-=-=-=-= RULES -=-=-=-=-=-=-=-=-=-=-=-=-=-#

gmk:
	@find sources -name '*.c' | sed 's/^/SOURCES += /' > sources.mk
	@find includes -name '*.h' | sed 's/^/INCLUDES += /' > includes.mk

gmk_bonus:
	@find sources_bonus -name '*.c' | sed 's/^/SOURCES_BONUS += /' > sources_bonus.mk
	@find includes_bonus -name '*.h' | sed 's/^/INCLUDES_BONUS += /' > includes_bonus.mk

clean:
	@make fclean -C libft
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(RM) $(DEPS)
	@$(RM) $(DEPS_BONUS)
	@echo "Cleaning all the .o in your libft and project!"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "Cleaning all the compiled library!"

re: fclean all

#=-=-=-=-=-=-=-=- DEPS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

-include $(DEPS)
-include $(DEPS_BONUS)

#=-=-=-=-=-=-=-=-= PHONY -=-=-=-=-=-=-=-=-=-=-=-=-=-#

.PHONY: all clean fclean re gmk bonus gmk_bonus

#=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-#

