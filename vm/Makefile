# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/01 13:04:43 by lvan-vlo       #+#    #+#                 #
#    Updated: 2019/12/18 17:25:04 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources

BINARY = corewar
HEADER = -I include/ -I ../libft/
SRC_PATH = src/
SRCS := ${addprefix $(SRC_PATH), $(SRCS)}
OBJ = $(SRCS:%.c=%.o)
FLAGS = -o $(BINARY)
ERRFLAGS = -Wall -Wextra -Werror
VISFLAGS = -lncurses
CC = gcc
LIBPATH = ../libft/
PRINTFPATH = $(LIBPATH)ft_printf/
LIBS = $(LIBPATH)libft.a $(PRINTFPATH)libftprintf.a
COLOR = \033[1;34m
OFF = \033[0m
MAKEFLAGS += --silent

all: $(BINARY)

%.o: %.c
	@echo "$(COLOR)Building $@ from $< file$(OFF)"
	@$(CC) $(HEADER) -c $(ERRFLAGS) -o $@ $<

$(BINARY): $(OBJ)
	@echo "$(COLOR)Make libft$(OFF)"
	@make -C $(LIBPATH)
	@echo "$(COLOR)Make printf library$(OFF)"
	@make -C $(PRINTFPATH)
	@$(CC) $(VISFLAGS) $(HEADER) $(SRCS) $(ERRFLAGS) $(FLAGS) $(LIBS)

clean:
	@echo "$(COLOR)Removing object files$(OFF)"
	@make -C $(LIBPATH) clean
	@make -C $(PRINTFPATH) clean
	@rm -rf $(OBJ)
	@echo "$(COLOR)Object files removed$(OFF)"

fclean: clean
	@make -C $(LIBPATH) fclean
	@make -C $(PRINTFPATH) fclean
	@echo "$(COLOR)Removing executable and extraneous directories$(OFF)"
	@rm -rf $(BINARY)
	@echo "$(COLOR)Executable and directories removed$(OFF)"

re: fclean all