/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:03:52 by rle               #+#    #+#             */
/*   Updated: 2017/05/03 15:13:36 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_db.h>

int	set(struct s_header *header, struct s_command *cmd,
				t_vec *entries, t_vec *db)
{
	size_t	i;
	uint8_t	*entry;

	(void)(db);
	i = 0;
	while (i < entries->elmnt_count)
	{
		entry = *(uint8_t**)vec_get(entries, i);
		memcpy(entry + header->fields[cmd->field].offset,
			cmd->value, header->fields[cmd->field].value_size);
		i++;
	}
	return (0);
}
