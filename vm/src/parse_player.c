/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_player.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:11:10 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/18 17:18:37 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

/*
** Checks that player file has correct info then parses it into struct
*/

static int	check_magic(char *str, int *i)
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

static int	check_name(char *str, int *i, t_player *player)
{
	int x;

	player->name = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	ft_memcpy(player->name, &str[*i], PROG_NAME_LENGTH);
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

static int	check_and_parse_code(char *str, int *i, t_player *player)
{
	if (player->file_size - *i != player->code_size)
		return (0);
	player->code = (unsigned char *)ft_memalloc(sizeof(unsigned char) * \
	player->code_size + 1);
	ft_memcpy(player->code, &str[*i], player->code_size);
	player->code[player->code_size] = '\0';
	return (1);
}

int			parse_player(char *file, t_player *player, int player_num)
{
	int		i;

	if (player->file_size < MIN_PLAYER_FILE_SIZE)
		return (error_and_return_null("Player file size too small.\n\n"));
	i = 0;
	if (!check_magic(file, &i))
		return (error_and_return_null("Incorrect magic header.\n\n"));
	if (!check_name(file, &i, player))
		return (error_and_return_null("Incorrect name.\n\n"));
	if (!check_code_size(file, player, &i))
		return (error_and_return_null("Code too large (max 993 bytes)\n\n"));
	if (!check_comment(file, &i, player))
		return (error_and_return_null("Incorrect player comment.\n\n"));
	if (!check_and_parse_code(file, &i, player))
		return (error_and_return_null("Incorrectly formatted player\n\n"));
	player->id = player_num + 1;
	ft_memdel((void **)&file);
	return (1);
}
