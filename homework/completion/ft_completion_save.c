#include "sh.h"

int		ft_completion_count(int code)
{
	static int	save = 0;

	if (code == CODE_RESET)
		save = 0;
	else if (code == CODE_PUSH)
		save++;
	else if (code == CODE_GET)
		return (save);
	return (0);
}

int			ft_completion_lastwrite(int code, int val)
{
	static int	save = 0;

	if (code == CODE_RESET)
		save = 0;
	if (code == CODE_SET)
		save = val;
	if (code == CODE_GET)
		return (save);
	return (0);
}

int			ft_completion_reset(void)
{
	ft_completion_count(CODE_RESET);
	ft_completion_lastwrite(CODE_RESET, 0);
	return (0);
}
