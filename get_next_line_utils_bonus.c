/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:07:04 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/10/21 11:51:53 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Returns the number of chars until the char c is hit. Works with c == 0
size_t	strlen_c(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i])
		i++;
	if (!c)
		return (i);
	if (s[i] != c)
		return (0);
	else
		return (i + 1);
}

//Slightly modified version from the libft where the dest is freed
char	*ft_strjoin_free(char *s1, char const *s2)
{
	size_t	tot_len;
	char	*s_joined;
	int		i;

	i = 0;
	tot_len = strlen_c(s1, 0) + strlen_c((char *)s2, 0) + 1;
	s_joined = malloc(tot_len);
	if (!s_joined)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*s_joined++ = s1[i++];
		free (s1);
	}
	if (s2)
		while (*s2)
			*s_joined++ = *s2++;
	*s_joined++ = 0;
	return (s_joined - tot_len);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (dest);
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

//That's some of the dumbest shit y'all ever witness. 
//Just to save a couple lines of code.
char	*ft_free(void *ptr)
{
	if (ptr)
	{
		free (ptr);
		ptr = NULL;
	}
	return (NULL);
}