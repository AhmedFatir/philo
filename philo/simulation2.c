/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatir <afatir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:24:02 by afatir            #+#    #+#             */
/*   Updated: 2023/05/13 10:42:05 by afatir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	t_time(void)
{
	struct timeval	tm;
	long long		t;

	t = 0;
	if (gettimeofday(&tm, NULL) == -1)
		return (printf("gettimeofday failed\n"), 0);
	t = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (t);
}

int	mutex_init(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->fork_m[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->philo->m_death, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->philo->m_stop, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->philo->m_count, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->print_m, NULL) != 0)
		return (0);
	return (1);
}

int	ft_join(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(data->philo[i].ph_t, NULL) != 0)
			return (0);
		if (pthread_join(data->philo[i].death, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	update_last(t_philo *ph, t_data *da)
{
	pthread_mutex_lock(&da->philo->m_death);
	ph->last = t_time();
	pthread_mutex_unlock(&da->philo->m_death);
}

int	check_last(t_philo *ph, t_data *da)
{
	pthread_mutex_lock(&da->philo->m_death);
	if ((t_time() - ph->last) >= da->t_die)
	{
		return (pthread_mutex_unlock(&da->philo->m_death), 1);
	}
	pthread_mutex_unlock(&da->philo->m_death);
	return (0);
}
