/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:00:34 by sstench           #+#    #+#             */
/*   Updated: 2019/09/21 17:19:29 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcounter(const char *str, char c)
{
	int index;
	int words;

	index = 0;
	words = 0;
	if (!str || !c)
		return (0);
	while (str[index])
	{
		if (str[index] == c && str[index + 1] != c)
			words++;
		index++;
	}
	if (str[0] != '\0')
		words++;
	return (words);
}

static char		*ft_newword(const char *str, char c, int *index)
{
	char	*fresh;
	int		j;

	if (!str || !c)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(fresh) * (ft_strlen(str)))))
		return (NULL);
	j = 0;
	while (str[*index] != c && str[*index])
	{
		fresh[j] = str[*index];
		j++;
		*index += 1;
	}
	fresh[j] = '\0';
	while (str[*index] == c && str[*index])
		*index += 1;
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		word;
	int		index;
	int		j;

	if (!s || !c)
		return (NULL);
	j = 0;
	index = 0;
	word = ft_strcounter(s, c);
	if (!(fresh = (char **)malloc(sizeof(fresh) * (ft_strcounter(s, c) + 2))))
		return (NULL);
	while (s[index] == c && s[index])
		index++;
	while (j < word && s[index])
	{
		fresh[j] = ft_newword(s, c, &index);
		j++;
	}
	fresh[j] = NULL;
	return (fresh);
}
