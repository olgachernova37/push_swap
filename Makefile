# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:18:15 by olcherno          #+#    #+#              #
#    Updated: 2025/05/14 15:58:12 by olcherno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc # cc 
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCDIR = src
OBJDIR = obj
LIBFTDIR = libs/libft
FTPRINTF_DIR = libs/libftprintf

SRC_OP = main/push_swap.c main/errors.c main/set_param_a_to_b.c main/set_param_b_to_a.c main/sort_three.c main/sorting.c  main/stack_commands.c  main/stack_initialisation.c
SRC_DATA = commands/push.c commands/swap.c commands/rotate.c commands/r_rotate.c
SRC = $(SRC_OP) $(SRC_DATA)

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))

# Rules of files
$(NAME): $(OBJS) $(LIBFTDIR)/libft.a $(FTPRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -L$(FTPRINTF_DIR) -lftprintf -o $(NAME)

# Create necessary directories for object files
$(OBJDIR):
	mkdir -p $(OBJDIR)/main $(OBJDIR)/commands

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(LIBFTDIR) -I$(FTPRINTF_DIR) -c $< -o $@

# Rules to build the libraries # making makefile of libft
$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR) 

$(FTPRINTF_DIR)/libftprintf.a:    # making makefile of printf
	$(MAKE) -C $(FTPRINTF_DIR)

# Rules of actions
.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean

re: fclean all