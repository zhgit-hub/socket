#ifndef _HTTP_
#define _HTTP_

#include <netdb.h>


/*  
**  select a work type.
**  DEFAULT : only pthread
**  PTH_POOL : prhread pool
**  EPOLL : IO Multiplexing -- event poll
*/
#define PTH_POOL
#define EPOLL


#define DEFAULT_PORT "4000"
#define PTH_POOL_SIZE 8
#define BUFF_SIZE 1024
#define RESP_SIZE 1024
#define EPOLL_SIZE 1024

#define GET 0
#define OTHERS 1

struct client_info
{
    int sock;
    char client_host[NI_MAXHOST];
    char client_server[NI_MAXSERV];
};

static struct client_info *listen_info;

/*
**  server program core
*/
static void *program_core(void *arg);

/*
**  http response
*/
static void response(struct client_info *info, int type);
static void bad_request(int sock);

#endif