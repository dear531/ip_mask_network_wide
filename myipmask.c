#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{
	char ip[] = "192.168.1.1";
	char mask[] = "255.255.255.128";
	struct in_addr net_ip, net_mask, tmp;
	char p_min[16], p_max[16];
	int max, min;
	char *p = NULL;
	char userip[] = "192.168.1.128";
	int saveuserip;

	printf("ip:%s, mask:%s\n", ip, mask);
	inet_aton(ip, &net_ip);
	inet_aton(mask, &net_mask);

	tmp.s_addr = net_ip.s_addr & net_mask.s_addr;
	p = inet_ntoa(tmp);
	min = ntohl(tmp.s_addr);
	memcpy(p_min, p, strlen(p));
	printf("min_ip:%s, mask:%s\n", p_min, mask);

	tmp.s_addr = net_ip.s_addr | ~net_mask.s_addr;
	p = inet_ntoa(tmp);
	max = ntohl(tmp.s_addr);
	memcpy(p_max, p, strlen(p));
	printf("max_ip:%s, mask:%s\n", p_max, mask);
	printf("max:%d\nmin:%d\n", max, min);
	printf("max:%u\nmin:%u\n", max, min);

	inet_aton(userip, &tmp);
	saveuserip = ntohl(tmp.s_addr);
	if (saveuserip >= min && saveuserip <= max)
		printf("userip:%s is\n", userip);
	else
		printf("userip:%s is'nt\n", userip);
	return 0;
}
