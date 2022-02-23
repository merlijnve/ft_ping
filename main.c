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
	struct addrinfo *tmp;
	int				socketd;
	int				on;
	void *packet;	

	on = 1;
	ft_bzero(&hints,sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	printf("%s, on: %d, argc: %p\n", argv[1], on, &argc);
	
	// // list all sockets for given hostname/ip
	// getaddrinfo(argv[1], NULL, NULL, &res);
	
	// initialise a RAW ICMP socket
	// returns a socket descriptor
	// POSSIBILITY FOR SWITCHING BETWEEN IPV4/IPV6 HERE
	printf("getting socket descriptor...\n");
	socketd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
	if (socketd == -1)
	{
		perror("socket: ");
		printf("errno: %d\n", errno);
		exit_msg("Socket initialisation failed\n", -1);
	}
	// set socket options??
	//getaddrinfo
	if (getaddrinfo("google.com", NULL, &hints, &res) != 0) 
	{
		printf("errno: %d\n", errno);
		perror("getaddrinfo: ");
		exit_msg("Getting address info failed\n", -1);
	}
	for (tmp = res; tmp != NULL; tmp = tmp->ai_next) {
		printf("ai_flags: %d, ai_family: %d, ai_socktype: %d\n", res->ai_flags, res->ai_family, res->ai_socktype);
		printf("sockaddr family: %d, sockaddr:%s\n", res->ai_addr->sa_family, res->ai_addr->sa_data);
	char *s;
	s = malloc(sizeof(char *));
	printf("inet_ntop: %s, canonname: %s\n", inet_ntop(AF_INET, res, s, res->ai_addrlen),res->ai_canonname);
	// send a ECHO_REQUEST to socket address
	// start time
	if (sendto(socketd, packet, sizeof(packet), 0, res->ai_addr, res->ai_addrlen))
	{
		perror("sendto: ");
		//exit_msg("Sendto failed\n", -1);
	}
	}
	// catch echo
	// end time
	signal(SIGALRM, pinger);
	alarm(1);
	while(1);
	printf("finished\n");
	freeaddrinfo(res);
	return (0);
}
