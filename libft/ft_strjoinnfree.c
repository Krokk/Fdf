/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchapka <tchapka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 11:11:41 by tchapka           #+#    #+#             */
/*   Updated: 2017/09/30 19:12:55 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinnfree(char *s1, char *s2, size_t len, char c)
{
	char	*str;

	str = ft_strnjoin(s1, s2, len);
	if (c == '1' || c == 'B')
		free((char *)s1);
	if (c == '2' || c == 'B')
		free((char *)s2);
	return (str);
}
