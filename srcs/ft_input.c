/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:11:25 by avolcy            #+#    #+#             */
/*   Updated: 2023/10/19 18:31:54 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include<stdio.h>

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
	while  (str[i] && str[i] >= '0' && str[i] <= '9')
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
//	char	*s;

	(void)ac;
//	printf("|%s|\n", dup[0]);
//	printf("|%s|\n", dup[1]);
	i = 1;
	while (dup[i])
	{
		j = 1;
		while (dup[j])
		{
			if(i != j && ft_atol(dup[i]) == ft_atol(dup[j]))
			{
				ft_putstr_fd(DUP_MSG, 2);
				exit(0);
			}
			++j;
		}
		++i;
	}
}

void	check_intsize(char *s)
{
	long	num;

	num = ft_atol(s);
	if (num <= INT_MIN || num >= INT_MAX)
	{
	 	ft_putstr_fd(INT_PROB, 2);
		exit(0);
	}
}
void    check_input(int ac, char **av)
{
    size_t      i;
    int     j;
    char    *s;

    if (ac == 1 || ((ac == 2 && av[1][0]) == '\0' && ft_strlen(av[1]) == 0))
    {
        ft_putstr_fd(ARG_MSG, 2);
        exit(0);
    }
    else
    {
        check_duplicated(ac, av);
        i =  1;
        while (av[i])
        {
            //printf("len of av[%zu] -> %zu\n", i, ft_strlen(av[i]));
            j =  0;
            s = av[i];
            check_intsize(s);
            while(s[j])
            {
                if (s[0] == '+' || s[0] == '-')
                    j++;
                if(!ft_isdigit(s[j]))// && s[j] != '-' && s[j] != '+')
                {
                    if (s[j] == '-' || s[j] == '+')
                    {
                        ft_putstr_fd(SIGN_MSG, 2);
                        exit(0);
                    }
                    ft_putstr_fd(CHAR_MSG, 2);
                    exit(0);
                }
                j++;
            }
            i++;
        }
    }
}

void	ft_input(int ac, char **av)
{
    int i = 0;
    if (ac == 2 && av[1][0] != '\0' && ft_strlen(av[1]) != 0 && av[1][0] != ' ')
    {
        av = ft_split(av[1], ' ');
        while(av[i])
        {
            printf("colunm -> %d is |%s|\n", i, av[i]);
            i++;
        }
    }
    check_input(ac, av);
}
