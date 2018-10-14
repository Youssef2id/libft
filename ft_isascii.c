#include "libft.h"

int	ft_isascii(int c)
{
	if (c <= 127)
	{
		if(c <= 177 && c >= 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
