/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:26:34 by naessgui          #+#    #+#             */
/*   Updated: 2024/12/17 17:49:49 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen( const char *str)
{
    int i;
    i = 0;
    
    if (!str)
        return (0);

    while (str[i])
    {
        i++;
    }
    return i;
}

char *ft_strjoin( char  *s1, char *s2)
{
    int i ;
    int j ;
    char *str;
    j = 0;
    i = 0;
    
    if (!s1 && !s2)
        return(NULL);
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    while (s1 && s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
    {
        str[i+j] = s2[j];
        j++;
    }
    str[i+j] = '\0';
   free(s1);
    return (str);
}
int  ft_strchr(char *s, char c)
{
    int i ;
    i = 0;
    if (!s)
        return 0;
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
    
}