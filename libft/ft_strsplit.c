/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 15:26:53 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/16 15:26:54 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**make_temp(char **string, const char *s, char c)
{
	char	**temp;

       	string[ft_substring_count(s, c) - 1] = NULL;
	temp = string;
	return (temp);
}

static char		**put_in_string(char *substring, char **string)
{
	*string = substring;
	return (string += 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char		*substring;
	char		**string;
	char		**temp;

	string = (char **)malloc((sizeof(char *) + 1) *
		ft_substring_count(s, c));
	if (string == NULL)
		return (string);
	temp = make_temp(string, s, c);
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			substring = ft_strndup(s, ft_substring_size(s, c));
			s += ft_substring_size(s, c);
			string = put_in_string(substring, string);
		}
	}
	return (temp);
}
