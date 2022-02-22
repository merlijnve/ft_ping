/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 11:08:45 by merlijn       #+#    #+#                 */
/*   Updated: 2022/01/11 15:52:17 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"
#include <errno.h>

void	exit_msg(char *msg, int code) 
{
	printf("%s\n", msg);
	exit(code);
}

int icmp_seq = 1;

void	pinger()
{
	printf("64 bytes from 8.8.8.8: icmp_seq=%d ttl=42 time=1.11ms\n", icmp_seq);
	icmp_seq++;
	alarm(1);
}

int	main(int argc, char **argv)
{
	struct addrinfo	hints;
	struct addrinfo *res;
	int				socketd;
	int				on;
	
	on = 1;
	ft_bzero(&hints,sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	printf("%s\n", argv[1]);
	
	// // list all sockets for given hostname/ip
	// getaddrinfo(argv[1], NULL, NULL, &res);
	
	// initialise a RAW ICMP socket
	// returns a socket descriptor
	// POSSIBILITY FOR SWITCHING BETWEEN IPV4/IPV6 HERE
	printf("getting socket descriptor...\n");
	socketd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
	if (socketd == -1)
	{
		perror("");
		printf("errno: %d\n", errno);
		exit_msg("Socket initialisation failed\n", -1);
	}
	// set socket options
	//getaddrinfo
	if (getaddrinfo("google.com", NULL, &hints, &res) != 0) 
	{
		printf("%d", getaddrinfo("google.com", NULL, &hints, &res));
		printf("errno: %d\n", errno);
		printf("%p\n", res->ai_addr);
		perror("getaddrinfo: ");
	}
	// send a ECHO_REQUEST to socket address
	// start time
	// sendto(AF_INET, );
	// catch echo
	// end time
	signal(SIGALRM, pinger);
	alarm(1);
	while(1);
	printf("finished\n");
	return (0);
}
