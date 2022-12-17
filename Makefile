# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isojo-go <isojo-go@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:19:35 by isojo-go          #+#    #+#              #
#    Updated: 2022/12/17 18:19:02 by isojo-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Makefile structure ---

## Program Name:
NAME	=	so_long

## Folder Structure:
SRCDIR	=	src
OBJDIR	=	obj
BINDIR	=	bin

## Libraries:
LIBMLX	=	./lib/LIBMLX
LIBFT	=	./lib/LIBFT
LIBS	=	$(LIBFT)/libft.a $(LIBMLX)/libmlx.a -framework OpenGL -framework AppKit

## Header Files (dedicated and from libraries):
HEADERS	=	-I ./inc -I $(LIBFT)/inc -I $(LIBMLX)/inc

## Source Files:
SRC	=	$(wildcard $(SRCDIR)/*.c)
OBJ	=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

## Compilation flags:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf
DEBUG		=	-g3 -fsanitize=address

## Extras:
### Colors:
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# **************************************************************************** #

# --- Makefile instructions ---

all:		libft libmlx $(NAME)

$(NAME):	$(OBJ)
			@mkdir -p $(BINDIR)
			@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o ./$(BINDIR)/$(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

debug:		$(OBJ)
			@mkdir -p $(BINDIR)
			@$(CC) $(OBJ) $(LIBS) $(HEADERS) -o ./$(BINDIR)/$(NAME) $(DEBUG)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

libmlx:
			@$(MAKE) -C $(LIBMLX)

libft:
			@$(MAKE) -C $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@mkdir -p $(OBJDIR)
			@printf "$(BLUE)Compiling: $< ...$(DEF_COLOR)"
			@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
			@echo "$(GREEN)Done!$(DEF_COLOR)"

clean:
			@$(RM) $(OBJ) $(OBJDIR)
			@echo "$(YELLOW)$(NAME) object files removed!$(DEF_COLOR)"
			@$(MAKE) -C $(LIBFT) clean
			@$(MAKE) -C $(LIBMLX) clean

fclean:
			@$(MAKE) -C $(LIBFT) fclean
			@$(MAKE) -C $(LIBMLX) fclean
			@if [ -d $(OBJDIR) ]; then \
				$(RM) $(OBJ) $(OBJDIR); \
				echo "$(YELLOW)$(NAME) object files removed!$(DEF_COLOR)"; \
			fi
			@$(RM) $(NAME) $(BINDIR)
			@echo "$(RED)$(NAME) removed!$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft libmlx