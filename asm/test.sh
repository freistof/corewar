# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    test.sh                                            :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/11 10:22:43 by fblom         #+#    #+#                  #
#    Updated: 2019/12/11 10:22:45 by fblom         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

for i in test_files/*/*.s ; do
	./asm $i > out_my
	orig=`awk 'NF>1{print $NF}' out_my | grep .cor`
	echo "${YELLOW}${i}${NC}"
	if [ ! -z "$orig" ]
		then
			mine="${orig}.my"
			mv $orig $mine
			./../resources/asm $i > out_th
			their=`awk 'NF>1{print $NF}' out_th | grep .cor`
		diffy=`diff $mine $their`
			if  [ -z "$diffy" ] && [ ! -z "$their" ] && [ ! -z "$mine" ]
				then
					echo "${GREEN}No diff between ${mine} and ${their}${NC}"
			else
				echo "${RED}Diff between ${mine} and ${their}${NC}"
			fi
	elif [ -z "$orig" ]
		then
			./asm $i > out_my
			./../resources/asm $i > out_th
			mine=`cat out_my | grep error`
			their=`cat out_th | grep "error\|Invalid\|Max length\|dereference"`
			# cat out_my
			# cat out_th
			if [ ! -z "$mine" ] && [ ! -z "$their" ]
				then
					echo "${GREEN}Both give an error${NC}"
			else
				echo "${RED}One does not give an error${NC}"
			fi
	fi
	rm -f out_my
	rm -f out_th
	rm -f test_files/*/*.cor
	rm -f test_files/*/*.cor.my
	echo ""
done
