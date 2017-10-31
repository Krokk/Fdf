/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchapka <tchapka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 19:09:28 by tchapka           #+#    #+#             */
/*   Updated: 2017/09/30 19:13:26 by tchapka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t len)
{
	char	*tmp;
	char	*str;

	tmp = ft_strnew(ft_strlen(s1) + len + 1);
	str = tmp;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2 && len--)
		*tmp++ = *s2++;
	return (str);
}
