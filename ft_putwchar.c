#include "../printf/includes/libft.h"
#include <unistd.h>

int	ft_putwchar(wchar_t c)
{
	char *bytes;
	int bytesleft;
	int modifier;
	int length;

	bytes = ft_strnew(ft_getbyteslength(c));
	bytesleft = ft_getbyteslength(c);
	length = bytesleft;
	modifier = 63;
	if (c <= 127)
		return (write(1, &c, 1));
	while (--bytesleft > 0)
	{
		bytes[bytesleft] = 128 | (c & 63);
		c = (c >> 6);
		modifier = modifier >> 1;
	}
	bytes[0] = (192 + (16 * (length == 2 ? 0 : length - 1)) | (c & modifier));
	bytes[length] = '\0';
	bytesleft = 0;
	while (bytesleft < length)
		write(1, &bytes[bytesleft++], 1);
	ft_memdel((void*)&bytes);
	return (length);
}

char	*ft_getwchar(wchar_t c)
{
	char *bytes;
	int bytesleft;
	int modifier;
	int length;

	bytes = ft_strnew(ft_getbyteslength(c));
	bytesleft = ft_getbyteslength(c);
	length = bytesleft;
	modifier = 63;
	if (c <= 127)
		bytes[0] = c;
	while (--bytesleft > 0)
	{
		bytes[bytesleft] = 128 | (c & 63);
		c = (c >> 6);
		modifier = modifier >> 1;
	}
	bytes[0] = (192 + (16 * (length == 2 ? 0 : length - 1)) | (c & modifier));
	bytes[length] = '\0';
	return (bytes);
}
