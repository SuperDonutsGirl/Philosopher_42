/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:34:33 by pamartin          #+#    #+#             */
/*   Updated: 2022/06/17 21:34:35 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_dinner(void *Nullable)
{
	t_philo	*ph;
	t_data	*data;
	int		i;

	data = (t_data *) Nullable;
	ph = data->ph[data->name_ph];
	data->name_ph++;
	if (ph->name % 2 == 0)
		ft_usleep(50);
	while (data->meal_max == -1 || data->tot_meal < data->meal_max)
	{
		if (!data->dead)
			dinner(data, ph);
	}
	return (NULL);
}

void	*dinner(t_data *data, t_philo *ph)
{
	go(data, ph);
	if (data->dead)
		return (NULL);
	else
		state_output(data, THINK, ph);
	return (NULL);
}

void	go(t_data *data, t_philo *ph)
{
	if (data->nb_philo == 1)
	{
		take_fork1(data, ph);
	}
	else
	{
		take_fork1(data, ph);
		take_fork2(data, ph);
		eat(data, ph);
		pthread_mutex_unlock(ph->ph_fork);
		pthread_mutex_unlock(ph->ngb_fork);
		ph_sleep(data, ph);
	}
}

void	*end_of_dinner(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (dead(data, data->ph[i]))
				return (NULL);
			if (data->meal_max != -1 && (data->tot_meal == data->meal_max))
			{
				pthread_mutex_lock(&data->output);
				return (NULL);
			}
			i++;
		}
	}
}
