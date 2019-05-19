#include <netdb.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/un.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>

#define handle_error(msg)   do { perror(msg); exit(EXIT_FAILURE); } while (0)
#define BUF_SIZE            1024
#define SERVER_PATH         "tpf_unix_sock.server"
#define CLIENT_PATH         "tpf_unix_sock.client"

void main(int argc, char *argv[])
{
    int                 cli_socket_fd;
    struct sockaddr_un  client_addr, serv_addr;
    char                buf[BUF_SIZE];

    memset(&client_addr, 0, sizeof(client_addr));
    memset(&serv_addr, 0, sizeof(serv_addr));

    cli_socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(cli_socket_fd < 0)
    {
        handle_error("Socket : ");
    }

    client_addr.sun_family = AF_UNIX;
    strcpy(client_addr.sun_path, CLIENT_PATH);

    unlink(CLIENT_PATH);
    if(bind(cli_socket_fd, (const struct sockaddr *)&client_addr, sizeof(struct sockaddr_un)))
    {
        handle_error("Bind : ");
    }

    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SERVER_PATH);
    if(connect(cli_socket_fd, (const struct sockaddr *)&serv_addr, sizeof(struct sockaddr_un)))
    {
        handle_error("Connect : ");
    }

    send(cli_socket_fd, argv[1], strlen(argv[1]) + 1, 0);

    memset(buf, 0 , BUF_SIZE);
    recv(cli_socket_fd, buf, BUF_SIZE, 0);
    printf("Got data from server : %s\n", buf);
    unlink(CLIENT_PATH);
    close(cli_socket_fd);
}
