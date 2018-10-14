#include "libft.h"
#include <stdio.h>
#include "ft_strncmp.c"
#include "ft_strlen.c"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	if (!s2)
		return ((char *)s1);
	while (*s1 != '\0' && i < (int)n)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
		i++;
	}
	return (NULL);
}

int main(void)
{
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	printf("%s\n", strstr("lorem ipsum dolor sit amet", "dolor"));
	return 0;
}
