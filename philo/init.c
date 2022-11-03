/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:38:49 by pamartin          #+#    #+#             */
/*   Updated: 2022/06/15 11:38:51 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;
	int		check;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->meal_max = ft_atoi(argv[5]);
	else
		data->meal_max = -1;
	data->tot_meal = 0;
	data->round_table = 0;
	data->name_ph = 0;
	data->dead = 0;
	data->start_time = get_time();
	check = init_with_protection(data);
	if (!check)
		return (NULL);
	return (data);
}
