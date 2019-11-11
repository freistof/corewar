/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_player.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:11:10 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/11 18:52:46 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Check magic header
*/

static int	check_magic(t_player *player, char *str, int *i)
{
	if (str[*i] != 0)
		return (0);
	else if (str[*i + 1] != MAGIC_BYTE_1)
		return (0);
	else if (str[*i + 2] != MAGIC_BYTE_2)
		return (0);
	else if (str[*i + 3] != MAGIC_BYTE_3)
		return (0);
	*i += 4;
	return (1);
}

/*
** Check name length and read into player struct (value unimportant)
*/

static int	check_name(char *str, int *i, t_player *player)
{
	int x;

	player->name = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	ft_strncpy(player->name, &str[*i], PROG_NAME_LENGTH);
	player->name[PROG_NAME_LENGTH] = '\0';
	*i += PROG_NAME_LENGTH;
	x = 0;
	while (x < 4)
	{
		if (str[*i + x] != 0)
			return (0);
		x++;
	}
	*i += 4;
	return (1);
}

/*
** Get executable code's size
*/

static void	get_code_size(char *str, int *i, t_player *player)
{
	int		final_size;

	final_size = 0;
	final_size += (unsigned char)str[*i] << 24;
	final_size += (unsigned char)str[*i + 1] << 16;
	final_size += (unsigned char)str[*i + 2] << 8;
	final_size += (unsigned char)str[*i + 3];
	player->code_size = final_size;
	*i += 4;
}

/*
** Check comment length and put into struct
*/

static int	check_comment(char *str, int *i, t_player *player)
{
	int		x;

	player->comment = (char *)ft_memalloc(sizeof(char) * COMMENT_LENGTH + 1);
	ft_memcpy(player->comment, &str[*i], COMMENT_LENGTH);
	player->comment[COMMENT_LENGTH] = '\0';
	*i += COMMENT_LENGTH;
	x = 0;
	while (x < 4)
	{
		if (str[*i + x] != 0)
			return (0);
		x++;
	}
	*i += 4;
	return (1);
}

/*
** Check code length and put into struct
*/

static int	check_and_parse_code(char *str, int *i, t_player *player)
{
	// ft_printf("FILE SIZE: %d\tI: %d\tCODE SIZE: %d\n", player->file_size, *i, player->code_size);
	if (player->file_size - *i != player->code_size)
		return (0);
	player->code = (unsigned char *)ft_memalloc(sizeof(unsigned char) * \
	player->code_size + 1);
	ft_memcpy(player->code, &str[*i], player->code_size);
	player->code[player->code_size] = '\0';
	return (1);
}

/*
** Parse player file into player struct
*/

int			parse_player(char *file, t_player *player, int player_num)
{
	int		i;

	if (player->file_size < MIN_PLAYER_FILE_SIZE)
		return (0);
	i = 0;
	if (!check_magic(player, file, &i))
		return (0);
	if (!check_name(file, &i, player))
	{
		ft_printf("FAILED ON NAME\n");
		return (0);
	}
	get_code_size(file, &i, player);
	if (!check_comment(file, &i, player))
	{
		ft_printf("FAILED ON COMMENT\n");
		return (0);
	}
	if (!check_and_parse_code(file, &i, player))
	{
		ft_printf("FAILED ON CHECK AND PARSE\n");
		return (0);
	}
	player->id = player_num + 1;
	return (1);
}
