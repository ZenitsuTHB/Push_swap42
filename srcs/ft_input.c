/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:11:25 by avolcy            #+#    #+#             */
/*   Updated: 2023/11/26 17:45:06 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	check_duplicated(int ac, char **dup)
{
	int		i;
	int		j;

	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (dup[i])
	{
		j = 1;
		while (dup[j])
		{
			if (i != j && ft_atol(dup[i]) == ft_atol(dup[j]))
				ft_error();
			++j;
		}
		++i;
	}
}

void	check_input(char **av, int i)
{
	char	*s;
	long	num;
	size_t	j;

	while (av[i])
	{
		j = 0;
		s = av[i];
		if (ft_strlen(av[i]) == 0)
			ft_error();
		if ((s[j] == '-' || s[j] == '+') && s[j + 1])
			j++;
		while (j < ft_strlen(s))
		{
			if (!ft_isdigit(s[j]))
				ft_error();
			j++;
		}
		num = ft_atol(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error();
		i++;
	}
}

void	ft_input_arg(int ac, char **av)
{
	char	**avsp;

	if (ac >= 3)
	{
		check_input(av, 1);
		check_duplicated(ac, av);
	}
	else if (ac == 2 && ft_strlen(av[1]) > 1)
	{
		avsp = ft_split(av[1], ' ');
		check_input(avsp, 0);
		check_duplicated(ac, avsp);
		ft_clear_arg(&avsp, 0);
	}
	else if (ac == 2 && !ft_isdigit(av[1][0]))
		ft_error();
	else
		exit(0);
}
