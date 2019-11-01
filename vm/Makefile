# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/01 13:04:43 by lvan-vlo       #+#    #+#                 #
#    Updated: 2019/11/01 13:19:32 by lvan-vlo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources

BINARY = corewar
HEADER = -I include/ -I ../libft/
SRC_PATH = src/
OBJ = $(SRC:%.c=%.o)
SRCS := ${addprefix $(SRC_PATH), $(SRCS)}
FLAGS = -o $(BINARY)
ERRFLAGS = -Wall -Werror -Wextra
CC = gcc
LIBPATH = ../libft/
PRINTFPATH = $(LIBPATH)ft_printf/
LIBS = $(LIBPATH)libft.a $(PRINTFPATH)libftprintf.a
COLOR = \033[1;34m
OFF = \033[0m

all: $(BINARY)

%.o: %.c
	@echo "$(COLOR)Building $@ from $< file$(OFF)"
	@$(CC) $(HEADER) -c $(ERRFLAGS) -o $@ $<

$(BINARY): $(OBJ)
	@echo "$(COLOR)Make libft$(OFF)"
	@make -C $(LIBPATH)
	@echo "$(COLOR)Make printf library$(OFF)"
	@make -C $(PRINTFPATH)
	@$(CC) $(HEADER) $(SRCS) $(ERRFLAGS) $(FLAGS) $(LIBS)

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