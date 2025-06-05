/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapupier <sapupier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:26:38 by sapupier          #+#    #+#             */
/*   Updated: 2024/11/20 13:27:14 by sapupier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compte le nb de mots dans la chaine
static int	ft_countword(char const *s, char c)
{
	int	i;
	int	nb_string;

	i = 0;
	nb_string = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0' && s[i] != c)
		{
			nb_string++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (nb_string);
}

// Libere la memoire
static char	**ft_malloc_free(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

// Alloue dans la memoire et copie chaine caract entre deux separateurs
// sur une ligne du tableau
static char	*copy_line_tab(char const *s, int i, int len)
{
	int		k;
	char	*dest;

	k = 0;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (k < len)
		dest[k++] = s[i++];
	dest[k] = '\0';
	return (dest);
}

// Extraire les mots dans le tableau
static char	**extract_word(char **tab, char const *s, int word_count, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < word_count)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			len = 0;
			while (s[i + len] != '\0' && s[i + len] != c)
				len ++;
			tab[j] = copy_line_tab(s, i, len);
			if (!tab[j])
				return (ft_malloc_free(tab, j));
			i += len;
			j++;
		}
	}
	tab[j] = (NULL);
	return (tab);
}

// Alloue avec malloc et retourne un tableau de chaine de caract en separant
// 's' a l aide du caractere 'c', utilise comme delimiteur.
// Tableau doit etre terminee par NULL
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	tab = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = extract_word(tab, s, word_count, c);
	return (tab);
}
/*
int main(void)
{
	char **tab = ft_split("  d cisjhn    sjv flsj  ", ' ');

	// Affiche les mots et les libère après usage
	if (tab)
	{
		int i = 0;
		while (tab[i] != NULL)
		{
			printf("tab[%d] = \"%s\"\n", i, tab[i]);
			free(tab[i]); // Libération de chaque mot
			i++;
		}
		free(tab); // Libération du tableau principal
	}
	else
	{
		printf("Error ; Split failed\n");
	}
	return (0);
}*/