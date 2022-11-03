/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:22:17 by pamartin          #+#    #+#             */
/*   Updated: 2022/06/15 19:22:19 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	check_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] && str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (output_error("parsing", ERR_FORMAT_ARG));
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	int	error;
	int	i;

	error = 0;
	i = 1;
	if (argc < 5 || argc > 6)
		return (output_error("parsing", ERR_NB_ARG));
	while (argv[i])
	{
		error += check_is_digit(argv[i]);
		if (ft_atoi(argv[i]) == -1)
			return (output_error("parsing", ERR_NB_ARG));
		if (ft_atoi(argv[i]) == -2)
			return (output_error("parsing", ERR_FORMAT_ARG));
		if (ft_atoi(argv[i]) == 0)
			return (output_error("parsing", ERR_ARG));
		if (error)
			return (error);
		i++;
	}
	return (error);
}
