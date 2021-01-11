#include "gdt.h"

int kernel_loader()
{
    gdt_setup();

    return 0;
}

#define MAX_REQUEST_NUM 512

struct request
{
    u16 disk;
    u16 sector;
    u16 cylinder;
    u16 offset;
};

struct request request_buffer[MAX_REQUEST_NUM];

bool server_busy;

void io_server_task()
{
    if(!server_busy)
    {
        for(int i = 0; i < request_buffer; i++)
        {
            if(request_buffer[i])   //se è una richiesta valida (!= 0)
            {
                query_disk(request_buffer[i]);
                server_busy = true;
                break;
            }
        }
    }

    if(disk_ready())
    {
        disk_buffer_read = read_disk();
        server_busy = false;
    }
}


