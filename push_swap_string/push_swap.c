/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:12:08 by ssuchane          #+#    #+#             */
/*   Updated: 2024/05/20 19:53:01 by ssuchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	exiterror(void)
{
	printf("Error\n");
	exit(0);
}

int	ft_atoi(char *s)
{
	int				i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!s)
		exiterror();
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (result > 2147483648 || result < -2147483647)
		exiterror();
	return (result * sign);
}

int	*split(char *str, char c)
{
	int	*tab;
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		tab[i] = ft_atoi(str);
	}
	return (tab);
}

int	words_count(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (count);
}

int	*split2(char *str)
{
	int	*tab;
	int	i;

	tab = (int *)malloc(sizeof(int) * words_count(str));
	if (!tab)
		exiterror();
	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		tab[i] = ft_atoi(str);
		i++;
		while (*str != ' ' && *str)
			str++;
	}
	return (tab);
}

int	check_doubles(int *tab, int n, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	check_input(char **argv, int argc)
{
	int	i;
	int	j;
	int	*tab;

	j = 1;
	tab = (int *)malloc(sizeof(int) * (argc - 1));
	if (!tab)
		exiterror();
	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9'))
				exiterror();
			i++;
		}
		tab[j - 1] = ft_atoi(argv[j]);
		if (check_doubles(tab, tab[j - 1], j - 1))
			exiterror();
		j++;
	}
	i = 0;
	while (i < argc - 1)
	{
		printf("Element %d: %d\n", i, tab[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*tab;

	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		tab = split2(argv[1]);
		for (int i = 0; i < words_count(argv[1]); i++)
			printf("Element #%i: %i\n", i, tab[i]);
	}
	else if (argc > 2 && check_input(argv, argc))
	{
		printf("nicu");
	}
	return (0);
}


// check for duplicates in split