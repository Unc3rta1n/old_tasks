#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    void* context = zmq_ctx_new();
    void* responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");
    assert(rc == 0);
    while (1)
    {
        char buffer[10] = { 0 };
        zmq_recv(responder, buffer, 10, 0);
        char first[10] = { 0 };
        char second[10] = { 0 };
        char operand[3] = { 0 };
        int firstnumber;
        int secondnumber;
        int solution;
        char sendsolution[10];
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == '+')
            {
                operand[0] = buffer[i];
                int k = i;
                for (int l = i - 1; l >= 0; l--)
                {
                    first[l] = buffer[k - 1];
                    k--;
                }
                int s = 0;
                for (int l = i + 1; l < strlen(buffer); l++)
                {

                    second[s] = buffer[l];
                    s++;
                }
            }
            if (buffer[i] == '-')
            {
                operand[0] = buffer[i];
                int k = i;
                for (int l = i - 1; l >= 0; l--)
                {
                    first[l] = buffer[k - 1];
                    k--;
                }
                int s = 0;
                if (buffer[i + 1] == '>')
                {
                    operand[1] = buffer[i + 1];
                    int s = 0;
                    for (int l = i + 2; l < strlen(buffer); l++)
                    {

                        second[s] = buffer[l];
                        s++;
                    }
                }
                else {
                    for (int l = i + 1; l < strlen(buffer); l++)
                    {

                        second[s] = buffer[l];
                        s++;
                    }
                }
            }
            if (buffer[i] == '/')
            {
                operand[0] = buffer[i];
                int k = i;
                for (int l = i - 1; l >= 0; l--)
                {
                    first[l] = buffer[k - 1];
                    k--;
                }
                int s = 0;
                for (int l = i + 1; l < strlen(buffer); l++)
                {

                    second[s] = buffer[l];
                    s++;
                }
            }
            if (buffer[i] == '*')
            {
                operand[0] = buffer[i];
                int k = i;
                for (int l = i - 1; l >= 0; l--)
                {
                    first[l] = buffer[k - 1];
                    k--;
                }
                int s = 0;
                for (int l = i + 1; l < strlen(buffer); l++)
                {
                    second[s] = buffer[l];
                    s++;
                }
            }
        }
        printf_s("%s", first);
        printf_s("\n%s", operand);
        printf_s("\n%s\n", second);
        if ((operand[0] == '-') && (operand[1] != '>'))
        {
            firstnumber = atoi(first);
            secondnumber = atoi(second);
            solution = firstnumber - secondnumber;
            _itoa_s(solution, sendsolution, _countof(sendsolution), 10);
            zmq_send(responder, sendsolution, 10, 0);
            printf_s("\nSend answer\n");
        }
        if (operand[1] == '>')
        {
            firstnumber = atoi(first);
            secondnumber = atoi(second);
            _itoa_s(firstnumber, sendsolution, _countof(sendsolution), secondnumber);
            zmq_send(responder, sendsolution, 10, 0);
            printf_s("\nSend answer\n");
        }
        if (operand[0] == '+')
        {
            firstnumber = atoi(first);
            secondnumber = atoi(second);
            solution = firstnumber + secondnumber;
            _itoa_s(solution, sendsolution, _countof(sendsolution), 10);
            zmq_send(responder, sendsolution, 10, 0);
            printf_s("\nSend answer\n");
        }
        if (operand[0] == '/')
        {
            firstnumber = atoi(first);
            secondnumber = atoi(second);
            solution = firstnumber / secondnumber;
            _itoa_s(solution, sendsolution, _countof(sendsolution), 10);
            zmq_send(responder, sendsolution, 10, 0);
            printf_s("\nSend answer\n");
        }
    }
    return 0;
}