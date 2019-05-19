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
#define UNIX_SOCK_PATH      "tpf_unix_sock.server"

void serve_client(int cli_socket_fd)
{
    char            buf[BUF_SIZE];

    printf("Waiting for client data\n");
    read(cli_socket_fd, buf, BUF_SIZE);

    printf("Recv data - %s\n", buf);

    strncpy(buf, "Hello", 5);
    write(cli_socket_fd, buf, BUF_SIZE);
}

void main()
{
    int                     ser_socket_fd, cli_socket_fd;
    struct sockaddr_un      serv_addr, cli_addr;
    int enable = 1;
    int cli_len;

    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));

    /* Create socket */
    ser_socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(ser_socket_fd < -1)
    {
        handle_error("Error for Socket : ");
    }

    if (setsockopt(ser_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
    {
        handle_error("setsockopt : ");
    }

    /* Bind Address */
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, UNIX_SOCK_PATH);
    unlink(UNIX_SOCK_PATH);
    if(bind(ser_socket_fd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)))
    {
        handle_error("Bind:");
    }

    /* Listen */
    if(listen(ser_socket_fd, 3) < 0)
    {
        handle_error("Listen : ");
    }

        printf("Waiting for client connection:\n");
        /* Accept */
        cli_socket_fd = accept(ser_socket_fd, (struct sockaddr *)&cli_addr, &cli_len);
        if(cli_socket_fd < 0)
        {
            handle_error("Accept : ");
            close(ser_socket_fd);
            close(cli_socket_fd);
        }

        cli_len = sizeof(cli_addr);
        if(getpeername(cli_socket_fd, (struct sockaddr *)&cli_addr, &cli_len))
        {
            close(ser_socket_fd);
            close(cli_socket_fd);
            handle_error("Getpeername : ");
        }
        else {
            printf("Client socket filepath: %s\n", cli_addr.sun_path);
        }

        /* server client */
        printf("Got connected, going to serve\n");
        serve_client(cli_socket_fd);
        close(cli_socket_fd);

    close(ser_socket_fd);
    close(cli_socket_fd);
    unlink(UNIX_SOCK_PATH);
}
