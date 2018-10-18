/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <ussef.id@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 21:00:38 by yidabdes          #+#    #+#             */
/*   Updated: 2018/10/17 21:59:57 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		a;
	int		z;
	int		i;
	char	*newstr;

	if (!s)
		return (NULL);
	a = 0;
	z = ft_strlen(s) - 1;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		a++;
	if (a == z + 1)
		return ("\0");
	while (s[z] == ' ' || s[z] == '\n' || s[z] == '\t')
		z--;
	i = a;
	if (!(newstr = (char *)malloc((z - a + 2) * sizeof(char))))
		return (NULL);
	a = 0;
	while (i <= z)
		newstr[a++] = s[i++];
	newstr[a] = '\0';
	return (newstr);
}
