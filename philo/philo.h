/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:38:06 by pamartin          #+#    #+#             */
/*   Updated: 2022/06/07 15:38:08 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

//Define variable parsing
# define ERR_NB_ARG 	"too many or not enough arguments"
# define ERR_FORMAT_ARG	"argument is not a digit"
# define ERR_ARG "argument can't be equal to 0"

//Define variable output état
enum	e_state
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
	LOCK,
	UNLOCK,
};

typedef struct timeval	t_time;

typedef struct s_philo
{
	int					name;
	unsigned long long	meal;
	pthread_mutex_t		*ph_fork;
	pthread_mutex_t		*ngb_fork;
	pthread_t			philo;
}			t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					meal_max;
	int					tot_meal;
	int					round_table;
	int					name_ph;
	int					dead;
	unsigned long long	start_time;
	t_philo				**ph;
	pthread_mutex_t		*forks;
	pthread_mutex_t		output;
}			t_data;

//parsing
int					parsing(int argc, char **argv);

//Init
t_data				*init_data(int argc, char **argv);
int					init_with_protection(t_data *data);
void				*start_dinner(void *Nullable);

//Utils
int					ft_atoi(const char *str);
int					output_error(char *stage, char *msg);
void				state_output(t_data *data, int state, t_philo *ph);

//Action
void				*dinner(t_data *data, t_philo *ph);
void				go(t_data *data, t_philo *ph);
void				take_fork1(t_data *data, t_philo *ph);
void				take_fork2(t_data *data, t_philo *ph);
void				eat(t_data *data, t_philo *ph);
void				ph_sleep(t_data *data, t_philo *ph);
int					dead(t_data *data, t_philo *ph);
void				*end_of_dinner(t_data *data);
void				ft_usleep(unsigned long long time);
unsigned long long	get_time(void);
#endif
