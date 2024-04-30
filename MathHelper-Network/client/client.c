#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <io.h>

int main(void)
{
    printf_s("Connecting to math-helper server\n");
    void* context = zmq_ctx_new();
    void* requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");

    int request_nbr;
    for (request_nbr = 0; request_nbr != 1000; request_nbr++) {
        char buffer[10] = { 0 };
        printf_s("Sending mathematical example %d\n", request_nbr);
        gets_s(buffer, 10);
        zmq_send(requester, buffer, 10, 0);
        zmq_recv(requester, buffer, 10, 0);
        printf_s("Answer: %s\n", buffer);
    }
    zmq_close(requester);
    zmq_ctx_destroy(context);
    return 0;
}