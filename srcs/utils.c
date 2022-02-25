#include "data.h"

void	*ft_xcalloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = calloc(count, size);
	if (!ptr)
		exit_error(NULL);
	return (ptr);
}

void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit_error(NULL);
	return (ptr);
}

void	exit_error(char *errmsg)
{
	if (errno != 0)
		perror(NULL);
	else if (errmsg)
		fprintf(stderr, "%s\n", errmsg);
	exit(EXIT_FAILURE);
}

FILE	*fopen_wrapper(char *filepath)
{
	FILE	*file;

	file = fopen(filepath, "r");
	if (!file)
		exit_error("File open failed.");
	return (file);
}

double	strtod_wrapper(char *str)
{
	char	*endptr;
	double	d;

	if (!str)
		return (0);
	errno = 0;
	d = strtod(str, &endptr);
	if (isnan(d))
		exit_error("Nan is invalid.");
	if (errno == ERANGE)
		exit_error(NULL);
	if (*endptr != '\0')
		exit_error("Contains characters that cannot be converted.");
	if (d == HUGE_VAL)
		exit_error("An overflow has occurred.");
	return (d);
}
