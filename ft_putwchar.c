#include "../printf/includes/libft.h"
#include <unistd.h>

static int ft_getbyteslength(wchar_t c)
{
	if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else if (c <= 2097151)
		return (4);
	else if (c <= 67108863)
		return (5);
	else if (c <= 2147483647)
		return (6);
	return (0);
}

int	ft_putwchar(wchar_t c)
{
	char *bytes;
	int bytesleft;
	int modifier;
	int length;
	int written;

	bytes = ft_strnew(6);
	bytesleft = ft_getbyteslength(c);
	length = bytesleft;
	modifier = 63;
	written = 0;
	if (c <= 127)
		return (write(1, &c, 1));
	if (bytesleft > 6)
		return (-1);
	while (--bytesleft > 0)
	{
		bytes[bytesleft] = 128 | (c & 63);
		c = (c >> 6);
		modifier = modifier >> 1;
	}
	bytes[0] = (192 + (16 * (length == 2 ? 0 : length - 1)) | (c & modifier));
	written = write(1, bytes, length);
	ft_memdel((void*)&bytes);
	return (written);
}
