

#include "Queue.h"


/*
to make our Queue more reliable and secure we define queue data type as incomplete data type to prevent 
client from corrupt our queue 
*/

static bool Q_IS_INIT ; 

struct Q_ptr{         
    struct Queue * front ;
    struct Queue * rear ;
};


struct Queue{
    uint32_t data;
    struct Queue * next ;
    struct Queue * pre ;
};



bool QueueInitialization(QHandler * Q)
{
 QHandler Q_new = (QHandler)malloc(sizeof(struct Q_ptr ));
 if(Q_new== NULL)
 return false ;
 
 
 Q_new->front = NULL ;
 Q_new->rear = NULL ;
 *Q = Q_new ;
 Q_IS_INIT = true ;
 return true ;
    
}


bool EnQueue(QHandler * Q,uint32_t *data)
{
    if(Q_IS_INIT == false)
    QueueInitialization(Q);
    
    
    struct Queue * new_node = (struct Queue *)malloc(sizeof(struct Queue));
    if(new_node == NULL)
    return false ;
    
    new_node->data = * data ;
    
    if((*Q)->front == NULL )
    {
        (*Q)->front = new_node ;
        (*Q)->rear = new_node ;
    new_node->next = NULL ;
    new_node->pre = NULL  ;    
        return true ;
        
    }
    (*Q)->front->pre =  new_node;
    new_node->next = (*Q)->front ;
    (*Q)->front = new_node ;
    new_node->pre = NULL  ;
    return true ;
    
}

bool DeQueue(QHandler * Q , uint32_t * data)
{
    if(Q_IS_INIT == false)
    QueueInitialization(Q);
    
    
    if((*Q)->rear == NULL)
    return false ;
    
    struct Queue * Q_rear = (*Q)->rear ;
    *data = (*Q)->rear->data ;
    (*Q)->rear = (*Q)->rear->pre ;
    free(Q_rear);
    return true ;
    
}

