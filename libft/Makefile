#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 17:42:27 by fblom         #+#    #+#                  #
#    Updated: 2019/02/18 15:53:12 by fblom         ########   odam.nl          #
#                                                                              #
#******************************************************************************#

include sources
NAME = libft.a
ERRFLAGS = -Wall -Werror -Wextra
INCL = libft.h
OBJ = $(SRCS:%.c=%.o)
HEADER = -I./
COLOR = \033[1;35m
OFF = \033[0m

all: $(NAME)

%.o: %.c
	@echo "$(COLOR)Building $@ from $< file$(OFF)"
	@gcc -c $(ERRFLAGS) $(HEADER) -o $@ $<

$(NAME): $(OBJ)
	@echo "$(COLOR)Creating $(NAME)$(OFF)"
	@ar -rc $(NAME) $(OBJ)

clean:
	@echo "$(COLOR)Removing library objects$(OFF)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(COLOR)Removing $(NAME)$(OFF)"
	@rm -f $(NAME)

re: fclean all
