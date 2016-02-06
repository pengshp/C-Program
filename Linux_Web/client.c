/*scocket套接字编程
 * 客户端client
 * 2015-2-6
 * pengshp
 *
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    int st=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(8080);
    addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    if (connect(st,(struct sockaddr *) &addr,sizeof(addr))==-1)
    {
        printf("connect failed %s\n",strerror(errno));
        return EXIT_FAILURE;
    }
    char s[1024];
    memset(s,0,sizeof(1024));
    strcpy(s,"hello word!");
    if(send(st,s,strlen(s),0)==-1)
    {
        printf("send failed %s\n",strerror(errno));
        return EXIT_FAILURE;
    }
    close(st);
    return EXIT_SUCCESS;
}
