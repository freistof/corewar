# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/30 10:51:20 by lvan-vlo       #+#    #+#                 #
#    Updated: 2019/10/14 15:05:23 by fblom         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources
include ../sources

NAME = libftprintf.a
ERRFLAGS = -Wall -Werror -Wextra
OBJS := ${SRC:.c=.o}
LNAMES = $(SRCS)
LSRCS :=${addprefix ../, $(LNAMES)}
LOBJS := ${LNAMES:.c=.o}
LOBJS :=${addprefix ../, $(LOBJS)}
COLOR = \033[1;36m
OFF = \033[0m

all: $(NAME)

%.o: %.c
	@echo "$(COLOR)Building $@ from $< file$(OFF)"
	@gcc -c $(ERRFLAGS) -o $@ $<


$(NAME): $(LOBJS) $(OBJS)
	@echo "$(COLOR)Creating $(NAME)$(OFF)"
	@ar rc $(NAME) $(OBJS) $(LOBJS)

clean:
	@echo "$(COLOR)Removing printflibrary objects$(OFF)"
	@rm -f $(OBJS) $(LOBJS)

fclean: clean
	@echo "$(COLOR)Removing $(NAME)$(OFF)"
	@rm -f $(NAME)

re: fclean all