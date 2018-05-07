#include "sh.h"

char	*ft_addmemory(char **str, int size, int add)
{
	char	*val;

	if (!str || add < 0 || size < 0)
		return (0);
	if (!(val = (char*)malloc(size + add)))
	{
		ft_strdel(str);
		return (0);
	}
	ft_memcpy((void*)val, (void*)*str, (size_t)(size));
	while (add-- > 0)
		val[size++] = 0;
	free(*str);
	*str = val;
	return (val);
}

char	*ft_readtostr(char *str, char end, int fd, int try)
{
	char	*buff;
	int		re;
	int		over;
	int		size;

	over = -1;
	re = 0;
	size = 100;
	if (!(buff = (char*)ft_memalloc(size + 1)))
		return (0);
	if (!str || !*str)
		return (buff);
	while (try-- > 0 && (over == -1 || !ft_isin(end, &buff[over])))
	{
		re += read(fd, &buff[re], size - re);
		over = ft_strinstr(buff, str);
		if (over == -1 && re == size)
		{
			if (!ft_addmemory(&buff, size + 1, 100))
				return (0);
			size += 100;
		}
	}
	return (over == -1 ? 0 : buff);
}
