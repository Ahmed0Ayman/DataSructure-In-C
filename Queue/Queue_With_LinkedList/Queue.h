

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


typedef struct Q_ptr * QHandler ;  // incomplete struct datatype to prevent the application from corrupt our queue 




// Queue APIs interface 
bool DeQueue(QHandler * Q , uint32_t * data);  
bool EnQueue(QHandler * Q,uint32_t *data);
bool QueueInitialization(QHandler * Q);

