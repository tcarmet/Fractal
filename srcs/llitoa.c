/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llitoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 16:13:34 by tcarmet           #+#    #+#             */
/*   Updated: 2015/02/25 16:13:35 by tcarmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_llintlen(long long int nb)
{
	size_t	len;

	len = 1;
	while (nb <= -10 && len++)
		nb = (nb / -10) * -1;
	return (len);
}

char	*convert_llint(char *str, long long int nb)
{
	if (nb <= -10)
	{
		str = convert_llint(str, ((nb / -10) * -1));
		str[ft_strlen(str)] = (char)(((nb % -10) * -1) + '0');
		return (str);
	}
	str[ft_strlen(str)] = (char)(-nb + '0');
	return (str);
}

char	*ft_llitoa(long long int nb)
{
	char	*str;
	int		isneg;

	isneg = 0;
	if (nb < 0)
		isneg = 1;
	else
		nb = -nb;
	str = (char *)ft_memalloc(sizeof(char) * ft_llintlen(nb) + isneg + 1);
	if (!str)
		return (NULL);
	if (isneg)
		str[0] = '-';
	return (convert_llint(str, nb));
}
