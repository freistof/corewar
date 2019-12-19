/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_comments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 12:06:15 by fblom         #+#    #+#                 */
/*   Updated: 2019/11/20 12:06:15 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** remove_comments(char *string) takes a string as argument
** and will replace every character after and including
** a comment sign (# or ;) with spaces
*/

void			remove_comments(char *string)
{
	int			i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '#' || string[i] == ';')
		{
			while (string[i] != '\0')
			{
				string[i] = ' ';
				i++;
			}
		}
		i++;
	}
}
