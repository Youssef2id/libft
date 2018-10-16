/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <ussef.id@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 00:20:54 by yidabdes          #+#    #+#             */
/*   Updated: 2018/10/17 00:29:09 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strnew;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(strnew = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
		* sizeof(char))))
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		strnew[i] = s1[i];
		i++;
	}
	while (j < (int)ft_strlen(s2))
	{
		strnew[i] = s2[j];
		i++;
		j++;
	}
	strnew[i] = '\0';
	return (strnew);
}
