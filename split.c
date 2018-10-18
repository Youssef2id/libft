/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidabdes <ussef.id@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:18:11 by yidabdes          #+#    #+#             */
/*   Updated: 2018/10/19 00:14:59 by yidabdes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_nbmot(char const *str, char c)
{
	int i;
	int nbmot;

	i = 0;
	nbmot = 1;
	while (*str == c)
		str++;
	if (str[i] == '\0')
		nbmot = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c && str[i + 1] != '\0')
				nbmot++;
		}
		i++;
	}
	return (nbmot);
}

int		*ft_begin(char const *str, int nbmot, char c)
{
	int i;
	int *start;
	int j;

	i = 0;
	j = 0;
	if(!(start = (int *)malloc(nbmot * sizeof(int))))
		return (NULL);
	if (str[0] != c && str[0] != c && str[0] != c)
		start[j++] = i++;
	while (str[i] != '\0')
	{
		if ((str[i] == c) && (str[i + 1] != c))
			start[j++] = i + 1;
		i++;
	}
	return (start);
}

int		*ft_end(char const *str, int *start, int nbmot, char c)
{
	int i;
	int j;
	int indx;
	int *end;

	if (nbmot == 0)
		return (0);
	if (!(end = (int *)malloc((2 * nbmot) * sizeof(int))))
		return (NULL);
	j = 0;
	indx = 0;
	while (j < 2 * nbmot)
	{
		end[j] = start[indx];
		j++;
		i = end[j - 1];
		while (str[i] != c)
			i++;
		end[j++] = i - 1;
		indx++;
	}
	return (end);
}

void	filltable(char const *str,char ***tab, int *ind, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (i < ft_nbmot(str, c))
	{
		if (!(word = (char *)malloc((ind[2 * i + 1] -
			ind[2 * i] + 1) * sizeof(char))))
			return ;
		j = 0;
		while (j < (ind[2 * i + 1] - ind[2 * i] + 1))
		{
			word[j] = str[ind[2 * i] + j];
			j++;
		}
		word[j] = '\0';
		*tab[i] = word;
		i++;
	}
	*tab[i] = (void *)0;
}

char	**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		*ind;
	char *word;
	int i;
	int j;

	if (!(tab = (char **)malloc((ft_nbmot(str, c) + 1) * sizeof(char *))))
		return (NULL);
	ind = ft_end(str, ft_begin(str, ft_nbmot(str, c), c), ft_nbmot(str, c), c);
	i = 0;
	while (i < ft_nbmot(str, c))
	{
		if (!(word = (char *)malloc((ind[2 * i + 1] -
			ind[2 * i] + 1) * sizeof(char))))
			return (NULL);
		j = 0;
		while (j < (ind[2 * i + 1] - ind[2 * i] + 1))
		{
			word[j] = str[ind[2 * i] + j];
			j++;
		}
		word[j] = '\0';
		tab[i] = word;
		i++;
	}
	tab[i] = (void *)0;
	return (tab);
}

int main(int argc, char const *argv[])
{
	int *begin;
	int *end;
	char **tab;
	int i;

	i = 0;
	begin = ft_begin(argv[argc - 1], ft_nbmot(argv[argc - 1], '*'), '*');
	end = ft_end(argv[argc - 1], begin, ft_nbmot(argv[argc - 1], '*'), '*');
	printf("%d\n", ft_nbmot(argv[argc - 1], '*'));
	tab = ft_strsplit(argv[argc - 1], '*');
	while(i < ft_nbmot(argv[argc - 1], '*'))
	{
		printf(" %s |", tab[i]);
		i++;
	}
	return 0;
}
// *salut*les***etudiants*



