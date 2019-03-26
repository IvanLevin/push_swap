#include "../../inc/push_swap.h"

static	int		check_same(int var, int *arr_d, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (arr_d[i] == var)
			return (-1);
		i++;
	}
	arr_d[i] = var;
	return (0);
}

int				check_valid_num(int argc, char **argv)
{
	int		*arr_d;
	int		var;
	int 	check;
	int		i;

	if(!(arr_d = (int *)malloc(sizeof(int) * (argc - 1))))
		return (-1);
	check = 0;
	i = 1;
	while (argc > 1)
	{
		var = ft_atoi(argv[i]);
		if (var <= 2147483647 && var >= -2147483648)
		{
			if(check_same(var, arr_d, check) == -1)
			{
				free(arr_d);
				return (-1);
			}
		}
		else
		{
			free(arr_d);
			return (-1);
		}
		check++;
		i++;
		argc--;
	}
	free(arr_d);
	return (0);
}

static	int		check_valid_arg(char **argv, int i)
{
	int j;

	j = 0;
	if (argv[i][j] == '+' || argv[i][j] == '-')
		j++;
	while (argv[i][j] >= '0' && argv[i][j] <= '9')
		j++;
	if ((argv[i][j - 1] == '+' || argv[i][j - 1] == '-'))
		return (-1);
	if (argv[i][j] != '\0' || j > 10)
		return (-1);
	return (0);
}

int				check_valid(int argc, char **argv)
{

	int		i;
	int 	len;

	i = 1;
	len = argc;

	if (argc < 1)
		return (-1);
	while (argc > 1)
	{
		if (check_valid_arg(argv, i) == -1)
			return (-1);
		i++;
		argc--;
	}
	return (0);
}
