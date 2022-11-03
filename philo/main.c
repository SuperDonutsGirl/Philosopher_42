/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:37:11 by pamartin          #+#    #+#             */
/*   Updated: 2022/06/07 15:37:12 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_output(t_data *data, int state, t_philo *ph)
{
	unsigned long long	t;

	pthread_mutex_lock(&data->output);
	t = get_time() - data->start_time;
	if (state == FORK && !data->dead)
		printf("%lld %d has taken a fork\n", t, ph->name);
	else if (state == EAT && !data->dead)
		printf("%lld %d is eating\n", t, ph->name);
	else if (state == SLEEP && !data->dead)
		printf("%lld %d is sleeping\n", t, ph->name);
	else if (state == THINK && !data->dead)
		printf("%lld %d is thinking\n", t, ph->name);
	else if (state == DEAD)
		printf("%lld %d died\n", t, ph->name);
	pthread_mutex_unlock(&data->output);
}

int	clear_thread(t_data *data)
{
	int	i;
	int	check;

	i = 0;
	while (i < data->nb_philo)
	{
		check = pthread_mutex_destroy(&data->forks[i]);
		check = pthread_detach(data->ph[i]->philo);
		i++;
	}
	return (check);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		error;
	int		i;

	error = parsing(argc, argv);
	if (error > 0)
		return (1);
	data = init_data(argc, argv);
	if (!data)
		return (1);
	end_of_dinner(data);
	pthread_mutex_destroy(&data->output);
	error = clear_thread(data);
	i = 0;
	while (i < data->nb_philo)
	{
		free(data->ph[i]);
		i++;
	}
	free(data->ph);
	free(data);
	if (error > 0)
		return (1);
	return (0);
}
