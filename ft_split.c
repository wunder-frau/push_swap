#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*substr;

	if (!s)
		return (NULL);
	len_s = strlen(s);
	if (start >= len_s)
		return (strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static unsigned int	ft_getstart(char const *s, char c)
{
	unsigned int	start;

	start = 0;
	if (!s)
		return (0);
	while (s[start] && s[start] == c)
		start++;
	return (start);
}

static char	**ft_free(char **strs, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static unsigned int	ft_getend(char const *s, unsigned int start, char c)
{
	unsigned int	end;

	end = start;
	if (!s)
		return (0);
	while (s[end] && s[end] != c)
		end++;
	return (end);
}

char	**ft_split(char const *s, char c)
{
	size_t			word_count;
	char			**words;
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	word_count = ft_countword(s, c);
	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (*s && i != word_count)
	{
		start = ft_getstart(s, c);
		end = ft_getend(s, start, c);
		words[i] = ft_substr(s, start, end - start);
		if (!words[i])
			return (ft_free(words, i));
		i++;
		s += end;
	}
	words[i] = 0;
	return (words);
}