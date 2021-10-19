/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_hab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:04:08 by igarg             #+#    #+#             */
/*   Updated: 2021/10/19 10:55:28 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.c"
#include <fcntl.h>
#include "get_next_line_utils_bonus.c"


int main(void)
{
	char *line;
	int  i;
	//int  fd1;
	int  fd2;
	// int  fd3;
	// fd1 = open("files/empty", O_RDWR);
	fd2 = open("Mr._Justice_Maxell_by_Edgar_Wallace.txt", O_RDONLY);
//	fd2[2] = open("./gnlTester-master/files/43_with_nl", O_RDONLY);
//	fd2[1] = open("./gnlTester-master/files/42_with_nl", O_RDONLY);

	// fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i <= 252)
	{
		//line = get_next_line(fd1);
		//printf("%d: %s\n", i, line);
		//free(line);
		line = get_next_line(fd2);
		printf("%d: %s\n", i, line);
		free(line);
//		i++;
//		line = get_next_line(fd2[0]);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(1001);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(fd2[1]);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(1002);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(fd2[2]);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(1003);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(fd2[0]);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(1004);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(fd2[1]);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(1005);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
//		line = get_next_line(fd2[2]);
//		printf("%d: %s\n", i, line);
//		free(line);
//		i++;
		//while (i != 0)
		//  line = get_next_line(fd3);
		//  printf("line [%02d]: %s\n", i, line);
		//  free(line);
		i++;
	}
	//close(fd1);
	close(fd2);
//	close(fd2[1]);
//	close(fd2[2]);
	// close(fd3);
	return (0);
}
