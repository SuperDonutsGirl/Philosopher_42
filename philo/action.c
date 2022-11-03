/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:26:44 by pamartin          #+#    #+#             */
/*   Updated: 2022/06/15 19:26:47 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_data *data, t_philo *ph)
{
	if (get_time() >= (ph->meal + data->time_to_die))
	{
		state_output(data, DEAD, ph);
		data->dead = 1;
		return (1);
	}
	return (0);
}

void	eat(t_data *data, t_philo *ph)
{
	state_output(data, EAT, ph);
	ph->meal = get_time();
	if (data->meal_max != -1 && data->round_table < data->nb_philo)
	{
		data->round_table++;
		if (data->round_table == data->nb_philo)
		{
			data->round_table = 0;
			data->tot_meal++;
		}
	}
	ft_usleep(data->time_to_eat);
}

void	ph_sleep(t_data *data, t_philo *ph)
{
	state_output(data, SLEEP, ph);
	ft_usleep(data->time_to_sleep);
}

void	take_fork1(t_data *data, t_philo *ph)
{
	if (data->dead)
		return ;
	pthread_mutex_lock(ph->ph_fork);
	state_output(data, FORK, ph);
	if (data->nb_philo == 1)
		ft_usleep(data->time_to_die + 10);
}

void	take_fork2(t_data *data, t_philo *ph)
{
	if (data->dead)
		return ;
	pthread_mutex_lock(ph->ngb_fork);
	state_output(data, FORK, ph);
}
