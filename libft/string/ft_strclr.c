/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 19:25:47 by mburson           #+#    #+#             */
/*   Updated: 2016/12/01 19:25:49 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_strclr(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}
