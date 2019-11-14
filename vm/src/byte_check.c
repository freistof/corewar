#include <stdio.h>

int main(void)
{
	int T_IND = 3;
	int T_DIR = 2;
	int T_REG = 1;

	int ind_and_reg = T_IND << 6;
	ind_and_reg += T_REG << 4;
	int dir_and_reg = T_DIR << 6;
	dir_and_reg += T_REG << 4;

	printf("IND AND REG FIRST ARG: %d\t2nd ARG: %d\tEXTRA: %d\n", ind_and_reg >> 6, ind_and_reg >> 4 & T_REG, ind_and_reg >> 4 & T_DIR);
	printf("DIR AND REG FIRST ARG: %d\t2nd ARG: %d\tEXTRA: %d\n", dir_and_reg >> 6, dir_and_reg >> 4 & T_REG, dir_and_reg >> 4 & T_IND);
	// printf("CHECK: %d\t%d\n", check, (check & T_DIR << 6) || check & T_REG << 6) && check & T_REG << 4);
	return (0);
}