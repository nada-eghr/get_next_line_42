// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/24 17:09:18 by naessgui          #+#    #+#             */
// /*   Updated: 2025/01/01 18:01:58 by naessgui         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

// // int main()
// // {
// //     printf("fd :\n");
// // int fd = open("nada.txt", O_RDONLY);
// // printf("fd : %d\n",fd);
// // char *str;
// // // str =get_next_line(fd);
// // // printf("%s\n", str);
// // while ((str =get_next_line(fd)))
// // {
// //  printf("%s\n", str);
// //  free(str);
// // }
// // }
// // void ll(){system("leaks -q a.out");}
// // int main()
// // {
// //     // atexit(ll);
// //     int fd = open("nada.txt", O_RDONLY , 0777);

// //    for (int i = 0; i < 4 ; ++i)
// //    {
// //     char *line = get_next_line(fd);
// //     printf("%s", line);
// //     free(line);

// //    }

// //     close (fd);

// // }
int main()
{
  int fd = open("nada.txt",O_RDONLY);
  // write (fd, "lucy sisar", 10);
  // char *str =get_next_line(fd);
  printf("%s",get_next_line(fd));
  
  int fd1 = open("test.txt",O_RDONLY);
  printf("%s",get_next_line(fd1));
  
  printf("%s",get_next_line(fd));
  printf("%s",get_next_line(fd1));
  close(fd);
   close(fd1);
//   while ((str = get_next_line(fd)))
//   {
//     printf("%s",str);
//     free(str);
//   }
//   close(fd);
//   printf("\n----------------------------------------------------\n");
//    int fd1 = open("test1.txt",O_CREAT | O_RDONLY) ;
//   char *str1;
//   while ((str1 = get_next_line(fd1)))
//   {
//     printf("%s",str1);
//     free(str1);
//   }
//   printf("\n----------------------------------------------------\n");
//    int fd2 = open("test2.txt",O_CREAT | O_RDONLY) ;
//   char *str2;
//   while ((str2 = get_next_line(fd2)))
//   {
//     printf("%s",str2);
//     free(str2);
//   }
//   printf("\n----------------------------------------------------\n");
//    int fd3 = open("test3.txt", O_CREAT | O_RDONLY) ;
//   char *str3;
//   while ((str3 = get_next_line(fd3)))
//   {
//     printf("%s",str3);
//     free(str3);
//   }
// printf("\n----------------------------------------------------\n");
//    int fd4 = open("test4.txt",O_CREAT | O_RDONLY) ;
//   char *str4;
//   while ((str4 = get_next_line(fd4)))
//   {
//     printf("%s",str4);
//     free(str4);
//   }
//   printf("\n----------------------------------------------------\n");
//    int fd5 = open("test5.txt", O_CREAT | O_RDONLY) ;
//   char *str5;
//   while ((str5 = get_next_line(fd5)))
//   {
//     printf("%s",str5);
//     free(str5);
//   }
}