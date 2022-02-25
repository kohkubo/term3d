#include "load.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	bufsize;
	size_t	i;

	bufsize = 0;
	if (strlen(s) > start)
		bufsize = ft_min(strlen(s) - start, len);
	buf = (char *)ft_xcalloc(bufsize + 1, sizeof(char));
	i = 0;
	while (i < bufsize)
	{
		buf[i] = s[start + i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

static char	**cut_word(char const *s, char c, char **buf)
{
	const char	*ptr;
	size_t		len;
	size_t		i;

	i = 0;
	while (buf != NULL && *s)
	{
		ptr = strchr(s, c);
		if (ptr == NULL)
			ptr = s + strlen(s);
		len = ptr - s;
		if (len > 0)
			buf[i++] = ft_substr(s, 0, len);
		s += len + (s[len] != '\0');
	}
	buf[i] = NULL;
	return (buf);
}

char	**free_string_array(char **buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		free(buf[i]);
		buf[i] = NULL;
		i++;
	}
	free(buf);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**buf;
	const char	*ptr;
	size_t		i;

	if (s == NULL)
		return (NULL);
	ptr = s;
	i = 1;
	while (*ptr)
		if (*ptr++ != c && (*ptr == c || *ptr == '\0'))
			i++;
	buf = (char **)ft_xcalloc(i, sizeof(char *));
	return (cut_word(s, c, buf));
}
