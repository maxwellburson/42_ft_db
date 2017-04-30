/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/04/05 13:46:56 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <vector.h>
#include <libft.h>
#include <stdint.h>
#include <stdlib.h>

enum	e_ctype
{
	CLOSE,
	GET,
	SET,
	ADD
};

struct	s_command
{
	enum e_ctype	type;
	size_t			field;
	void			*value;
};

struct	s_field
{
	void		*name;
	uint64_t	name_size;
	uint64_t	offset;
	uint64_t	value_size;
};

struct	s_header
{
	uint64_t		entry_size;
	uint64_t		field_count;
	struct s_field	*fields;
};

int		load_db(struct s_header *header, t_vec *db,
			int argc, char **argv);
int		get_next_command(struct s_header *header, struct s_command *command);
int		execute_command(struct s_header *header,
			struct s_command command, t_vec *entries, t_vec *db);

#endif