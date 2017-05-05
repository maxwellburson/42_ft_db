/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/05/04 14:49:22 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_db.h>

int			execute_command(struct s_header *header,
				struct s_command command, t_vec *entries, t_vec *db)
{
	uint8_t **entry;
	if (command.type == GET)
		return (get(header, command, entries, db));
	else if (command.type == CLEAR)
		return (clear(header, command, entries, db));
	else if (command.type == SET)
		return (set(header, command, entries, db));
	else if (command.type == ADD)
		return (add(header, command, entries, db));
	else if(command.type == DELETE)
		return (delete(header, command, entries, db));
	else if (command.type == FILTER)
	{
		filter(header, command, entries);
		//entry = *(uint8_t**)vec_get(entries, 0);
		entry = (uint8_t**)((uint8_t*)entries->data + 0);
		write(1, *entry, header->entry_size);
		return (1);
	}
	else
	{
		g_error = "ERROR: bad command type\n";
		return (-1);
	}
}