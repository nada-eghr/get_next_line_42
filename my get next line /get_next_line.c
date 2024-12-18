/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:25:56 by naessgui          #+#    #+#             */
/*   Updated: 2024/12/18 11:21:37 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *line (char *hold)
{
    char *buffer;
    int i = 0;
    while ( hold && hold[i] != '\n')
        i++;
    i++;
    buffer = malloc (i + 1);
    if (!buffer)
        return (NULL);
        //printf ("%s\n", buffer);
    int k = 0;
    while ( k < i)
    {
        buffer[k] = hold [k];
        k++;
    }
    buffer[k] = '\0';
    return (buffer);  
}

char *rest(char *hold , int len )
{
    char *end ;
    int len_hold;
    
    len_hold = ft_strlen(hold);
    end = malloc(len_hold - len + 1);
    if (!end)
        return (NULL);
    int i = 0;
    while (len < len_hold)
    {
        end[i] = hold[len];
        len++;
        i++;
    }
    end[i] = '\0';
    return (end);
    
    
}
void ll() {system("leaks -q a.out");}
char *get_next_line(int fd)
{
    atexit(ll);
    static char *hold;
    char *buff;
    char * ln ;
    int rd = 1;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return(NULL);
    while (rd != 0)
    {
        rd = read(fd , buff, BUFFER_SIZE);
        buff[rd] = '\0';
        hold = ft_strjoin(hold, buff);
        if (ft_strchr(buff, '\n'))
            break; 
    }
    free(buff);
    if (!hold || *hold == '\0')
		return (NULL);
    ln = line(hold); 
    int len = ft_strlen(ln);
    hold = rest(hold , len);
        
    return (ln);
}
int main()
{
    int fd = open("test.txt", O_RDONLY , 0777);
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
   printf("%s",get_next_line(fd));
    printf("%s",get_next_line(fd));
    close (fd);

}
