/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:06:30 by mfroissa          #+#    #+#             */
/*   Updated: 2023/04/28 20:50:38 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	valeur;

	i = 0;
	sign = 1;
	valeur = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		valeur = valeur * 10 + (str[i] - '0');
		if (valeur > 2147483647)
			return (-1);
		i++;
	}
	if (sign == -1)
		return (valeur * -1);
	return (valeur);
}

int	is_same(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && (!s2[i] || (s2[i] == '+' && !s2[i + 1])))
		return (1);
	return (0);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*tab;
	char	*str;

	tab = malloc(n * size);
	if (!tab)
		return (NULL);
	str = tab;
	while (n > 0)
	{
		n--;
		str[n] = '\0';
	}
	return (tab);
}
