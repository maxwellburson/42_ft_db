/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_db.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/05/01 18:20:41 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_db.h>

#define DB_OVERHEAD_PERCENT 0.2

int		open_db(struct s_header *header, t_vec *db, int fd)
{
	ssize_t		size;
	size_t		i;

	if (-1 == (size = read(fd, header, sizeof(*header))))
		return (-1);
	if (size != sizeof(*header))
	{
		g_error = "BAD FILE";
		return (-1);
	}

	header->fields = malloc(sizeof(*header->fields) * header->field_count);
	if (NULL == header->fields)
		return (-1);
	size = read(fd, header->fields,
		sizeof(*header->fields) * header->field_count);
	if (-1 == size)
		return (-1);
	if ((size_t)size != sizeof(*header->fields) * header->field_count)
	{
		g_error = "BAD FILE";
		return (-1);
	}

	i = 0;
	while (i < header->field_count)
	{
		header->fields[i].name = malloc(header->fields[i].name_size);
		if (NULL == header->fields[i].name)
			return (-1);
		if (-1 == (size = read(fd, header->fields[i].name, header->fields[i].name_size)))
			return (-1);
		if ((size_t)size != header->fields[i].name_size)
		{
			g_error = "not everything got written\?\?";
			return (-1);
		}
		i++;
	}

	size = read(fd, db, sizeof(*db));
	if (-1 == size)
		return (-1);
	if (size != sizeof(*db))
	{
		g_error = "BAD FILE";
		return (-1);
	}

	db->elmnt_max = db->elmnt_count * (1 + DB_OVERHEAD_PERCENT);
	if (NULL == (db->data = malloc(db->elmnt_size * db->elmnt_max)))
		return (-1);
	if (-1 == (size = read(fd, db->data, db->elmnt_size * db->elmnt_max)))
		return (-1);
	if ((size_t)size != db->elmnt_size * db->elmnt_max)
	{
		g_error = "BAD FILE";
		return (-1);
	}
	db->data_end = db->data + (db->elmnt_count * db->elmnt_size);

	//TODO: make sure there is nothing left
	
	return (close(fd));
}
