#include "ft_sh1.h"

int		ft_find_node(t_env **env, char *str)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (tmp && tmp->name && (ft_strcmp(tmp->name, str) == 0))
			return (1);
		tmp = tmp->nxt;
	}
	return (0);
}
