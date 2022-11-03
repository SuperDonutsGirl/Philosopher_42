/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:18:59 by pamartin          #+#    #+#             */
/*   Updated: 2022/11/03 14:19:01 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(int name)
{
	t_philo	*philo;
	int		check;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->name = name;
	philo->meal = get_time();
	return (philo);
}

void	init_fork(t_data *data, int name)
{
	if (data->nb_philo == 1)
	{
		data->ph[name]->ph_fork = &data->forks[0];
	}
	else
	{
		if (name == data->nb_philo - 1)
		{
			data->ph[name]->ph_fork = &data->forks[name];
			data->ph[name]->ngb_fork = &data->forks[0];
		}
		else
		{
			data->ph[name]->ph_fork = &data->forks[name];
			data->ph[name]->ngb_fork = &data->forks[name + 1];
		}
	}
}

int	init_ph_data(t_data *data)
{
	int	i;
	int	protect;

	data->ph = malloc(sizeof(t_philo *) * data->nb_philo);
	if (!data->ph)
		return (0);
	memset(data->ph, 0, sizeof(t_philo *) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
	{
		data->ph[i] = init_philo(i + 1);
		if (!data->ph[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		init_fork(data, i);
		protect = pthread_create(&data->ph[i]->philo, NULL, start_dinner, data);
		if (protect != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_every_forks(t_data *data)
{
	int	check;
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
		check = pthread_mutex_init(&data->forks[i], NULL);
		if (check != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_with_protection(t_data *data)
{
	int	check;

	check = pthread_mutex_init(&data->output, NULL);
	if (check != 0)
		return (0);
	check = init_every_forks(data);
	if (check != 0)
		return (0);
	check = init_ph_data(data);
	if (check == 0)
		return (0);
	return (1);
}
