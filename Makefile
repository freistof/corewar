#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 09:39:37 by fblom         #+#    #+#                  #
#    Updated: 2019/12/16 09:39:37 by fblom         ########   odam.nl          #
#                                                                              #
#******************************************************************************#

LIBPATH = libft/
PRINTFPATH = $(LIBPATH)ft_printf/
ASMPATH = assembler/
VMPATH = vm/
DISPATH = disassembler/

all: make

make:
	@make -C $(LIBPATH)
	@make -C $(PRINTFPATH)
	@make -C $(ASMPATH)
	@make -C $(VMPATH)
	@make -C $(DISPATH)

clean:
	@make -C $(LIBPATH) clean
	@make -C $(PRINTFPATH) clean
	@make -C $(ASMPATH) clean
	@make -C $(VMPATH) clean
	@make -C $(DISPATH) clean

fclean: clean
	@make -C $(LIBPATH) fclean
	@make -C $(PRINTFPATH) fclean
	@make -C $(ASMPATH) fclean
	@make -C $(VMPATH) fclean
	@make -C $(DISPATH) fclean

re: fclean all
