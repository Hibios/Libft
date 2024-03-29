/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnedu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstench <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:53:08 by sstench           #+#    #+#             */
/*   Updated: 2019/09/19 18:19:21 by sstench          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	index = 0;
	if (s1 && s2)
	{
		while (s1[index] != '\0' && index < n)
		{
			if (s1[index] == s2[index])
				index++;
			else
				return (0);
		}
	}
	return (1);
}
