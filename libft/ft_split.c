/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:58:01 by saeby             #+#    #+#             */
/*   Updated: 2022/09/27 10:24:21 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c);
static char	*ft_fill_new_word(const char *str, int start, int end);

// i_word is the index of the start of each word in the complete *s

char	**ft_split(const char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	i_word;
	char			**res;

	res = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return (NULL);
	i = 0;
	j = 0;
	i_word = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && i_word < 0)
			i_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && i_word >= 0)
		{
			res[j++] = ft_fill_new_word(s, i_word, i);
			i_word = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}

// allocates a new *word and fill it with the word starting at index start and
// ending at index end, adds a 0 character then returns the word

static char	*ft_fill_new_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

// check through all *str to count the number of words, when x is set to one 
// it also adds one to the word_count, the x is just a "trigger" to not count
// multiple words when there is multiple separator one after another

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}
