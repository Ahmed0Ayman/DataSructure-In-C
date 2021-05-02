

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue 
{
    uint32_t *ArrData ;
    uint32_t front ,rear ,capacity ;
    
};


struct Queue * QueueInitialize(uint32_t Size);
bool EnQueue(struct Queue * Q ,uint32_t * data);
bool DeQueue(struct Queue * Q,uint32_t * data);