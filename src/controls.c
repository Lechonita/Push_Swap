/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:27:24 by jrouillo          #+#    #+#             */
/*   Updated: 2023/02/02 14:28:35 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Compares 2 numbers with each other. Used in check_duplicates to see if 
	there are any duplicates in the input values. */

int	compare_nb(char *argv1, char *argv2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv1[i] == '+' && argv2[j] != '+')
		i++;
	else if (argv1[i] != '+' && argv2[j] == '+')
		j++;
	else if (argv1[i] == '-' && argv2[j] == '-')
	{
		i++;
		j++;
	}
	while (argv1[i] == '0' && argv1[i + 1] != '\0')
		i++;
	while (argv2[j] == '0' && argv2[j + 1] != '\0')
		j++;
	while (argv1[i] && argv2[j] && argv1[i] == argv2[j])
	{
		i++;
		j++;
	}
	return (argv1[i] - argv2[j]);
}

/* This function checks if there are any duplicates in the input values.*/

int	check_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && !compare_nb(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* This function checks if the input value fits in an int. */

int	checkint_min_max(char *argv)
{
	int	i;
	int	sign;

	i = 0 ;
	sign = 1;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1] != '\0')
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	while (argv[i] == '0')
		i++;
	if (ft_strlen(argv + i) > 10)
		return (0);
	if ((sign == 1) && ft_strlen(argv + i) >= 10
		&& ft_strncmp((argv + i), "2147483647", 11) > 0)
		return (0);
	if ((sign == -1) && ft_strlen(argv + i) >= 10
		&& ft_strncmp((argv + i), "2147483648", 11) > 0)
		return (0);
	return (1);
}

/* This function checks if the input value is a signed digit
	and nothing else. */

int	ft_signed_digit(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

/* This function checks the input values to see that they fit the requirements :
	- digits only
	- has to fit in an int
	- no duplicates 
	If they don't fit the requirements => "Error" */

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_signed_digit(argv[i]))
			return (0);
		if (!checkint_min_max(argv[i]))
			return (0);
		i++;
	}
	if (check_duplicates(argv))
		return (0);
	return (1);
}
