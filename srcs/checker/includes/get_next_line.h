/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkierbel <rkierbel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:24:30 by rkierbel          #+#    #+#             */
/*   Updated: 2021/06/14 14:24:32 by rkierbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int	get_next_line(int fd, char **line);

#endif
