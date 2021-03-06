#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include  <string.h>
# include  <stdio.h>
# include  <stdlib.h>
# include  <signal.h>
# include  <unistd.h>
# include  <unistd.h>
# include  <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# define THINKING 1
# define LIFE 1
# define EATING 2
# define SLEEPING 3
# define DIED 5
# define FULL 6

struct	s_all;

typedef struct s_philo
{
	unsigned long	time_of_death;
	struct s_all	*all;
	pid_t			pid;
	int				id;
	int				state;
	int				times_eat;
}	t_philo;

typedef struct s_all
{
	unsigned long	start;
	t_philo			*philo;
	sem_t			*forks;
	sem_t			*write;
	sem_t			*end_mutex;
	int				philosophers_number;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				parsed_times_eat;
	int				end;
	int				done_eat;
	int				*colors;
}				t_all;

unsigned long	my_time(void);
void			error(t_all *all, int i);
void			free_all(t_all *all);
void			start_life(t_philo *philo);
void			ft_usleep(unsigned long ms_sec);
void			printf_msg(char *msg, t_philo *philo);
int				get_args(t_all *all, int ac, char **av);
int				ft_atoi(char *str);

#endif
