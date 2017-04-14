# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 19:09:15 by gderenzi          #+#    #+#              #
#    Updated: 2017/04/12 17:43:11 by gderenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
SRC			= main.c \
			  parse_arg.c \
			  draw.c \
			  key_hook.c \
			  calc.c \
			  matrix.c \
			  error.c \
			  util.c

OBJ			= $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBDIR		= ./libft
LIBFT		= $(LIBDIR)/libft.a
LIBINC		= -I$(LIBDIR)/includes/
LIBLINK		= -L$(LIBDIR) -lft

MLXDIR		= ./mlx
MLX			= $(MLXDIR)/libmlx.a
MLXINC		= -I$(MLXDIR)
MLXLIB		= -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit

SRCDIR		= ./src/
INCDIR		= ./includes/
OBJDIR		= ./obj/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(LIBLINK) $(MLXLIB) $(OBJ) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

$(addprefix $(OBJDIR), %.o): $(addprefix $(SRCDIR), %.c)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIBDIR)
	@rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(NAME)

re: fclean all
