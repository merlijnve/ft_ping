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

void	exit_msg(char *msg, int code) 
{
	printf("%s", msg);
	exit(code);
}

int	main(int argc, char **argv)
{
	struct addrinfo	*res;
	int				socketd;
	int				option_value;
	
	option_value = 1;
	printf("%s\n", argv[1]);
	// // list all sockets for given hostname/ip
	// getaddrinfo(argv[1], NULL, NULL, &res);
	
	// initialise a socket for a socketfd
	socketd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (socketd == -1)
	{
		exit_msg("Socket initialisation failed\n", -1);
	}
	// set socket options
	printf("socketd: %i\n", socketd);
	setsockopt(socketd, IPPROTO_ICMP,IP_HDRINCL, &option_value, sizeof(option_value));

	for (res = res; res != NULL; res = res->ai_next)
	{
		// sendto(socketfd, )
	}

	// send a ECHO_REQUEST to socket address
	// start time
	// sendto(AF_INET, );

	// catch echo
	// end time

	return (0);
}
