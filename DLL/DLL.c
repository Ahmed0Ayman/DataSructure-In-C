
#include "DLL.h"




struct _node   // incomplete data type to protect our list from corruption by application 
{
    Item_Type data ;      
    struct _node * next ;
    struct _node * prev ;
};



DLL_STATUS DLL_Insert_Begining( DLL_node * head,Item_Type data )
{

     DLL_node  new_node = ( DLL_node )malloc(sizeof(struct _node ));
    if(new_node == NULL)
         return DLL_ERROR;

    if(*head == NULL)
    {
        printf("empty list first node in  DLL with specific data %d\n" , data);
        *head = new_node;
        new_node->prev  = NULL ;
        new_node->next = NULL;
        new_node->data = data ;
        return DLL_OK ;
    }

    new_node->prev= NULL;
    new_node->next = *head ;
    *head = new_node;
    new_node->data = data;
    return DLL_OK;
}


DLL_STATUS DLL_Insert_End( DLL_node * head,Item_Type data )
{
 DLL_node  new_node = ( DLL_node )malloc(sizeof(struct _node ));
    if(new_node == NULL)
         return DLL_ERROR;

 DLL_node  temp =*head ;

if(temp == NULL)
{
    DLL_Insert_Begining(head , data);
    return DLL_OK;
}

while(temp->next != NULL)
{
    temp = temp->next ;
}
temp->next = new_node;
new_node->prev = temp;
new_node->next = NULL ;
new_node->data = data ;
return DLL_OK ;

}



DLL_STATUS DLL_Insert_Spec_Loc( DLL_node  * head,Item_Type data , int position  )
{
     DLL_node  temp = *head ;
     DLL_node  new_node = ( DLL_node )malloc(sizeof(struct _node ));
       if(new_node == NULL)
         return DLL_ERROR;
    uint32_t count = 0 ;

    if((*head == NULL)||(position ==0))
    {
        printf("this position is not exist empty list \n");
        DLL_Insert_Begining(head,data);
        return DLL_ERROR ;
    }
    while((temp->next != NULL)&&(count < position-1))
    {
        if(position == 1)
            break;
        count++;
        temp = temp->next;


    }
//    temp = temp->prev ;
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next=new_node;
    new_node->data= data;
    return DLL_OK ;
}



DLL_STATUS DLL_Print_All( DLL_node  head)
{
     DLL_node  temp = head ;
    uint32_t count = 0;
    if(head == NULL)
    {
        printf("this is empty linked list \n");
        return DLL_ERROR;
    }
    while(temp->next != NULL  )
    {
        printf("the data of the num_%d DLL_node is %d\n",count,temp->data);
        if(temp->next == NULL)
            break ;
        temp= temp->next ;
        count++;
    }
    return DLL_OK ;
}


DLL_STATUS DLL_Del_Beginning( DLL_node * head )
{
     DLL_node temp = *head ;
    if(*head == NULL)
    {
        printf("this is empty linked list \n");
        return true;
    }
    
    
    *head = (*head)->next;  // modify head of the linked list to the next node 
    if((*head) != NULL)
    (*head)->prev = NULL;  
    free(temp);
    return true ;
}


DLL_STATUS DLL_Del_End( DLL_node * head)
{
    if(*head == NULL)     // check if the head is equal null so return error  
    return DLL_ERROR ;
    
    if((*head)->next == NULL) // check if the list contain only one node. in this case we will modify the head so call delete from beginning function 
    {
    DLL_Del_Beginning(head);
    return DLL_OK ;
    }
    DLL_node  temp =*head ;
    
    while(temp->next != NULL) // traversal till reach the end of the list 
    {
        
        temp = temp->next ;
    }
    // now we have the address of last node so we will do some modification then free that node 
    temp->prev->next = NULL ; // now mark this next pointer of the prev node null  
    free(temp); // here we free the last node 
    return DLL_OK ;
}




DLL_STATUS  DLL_Search_NodeSpecData(DLL_node head, Item_Type data)
{
    if(head == NULL)
    return DLL_ERROR ;
    
    
    
    uint32_t Loc =0;
    
    while(head->next != NULL) // traverse on all node untill reach the required node with required data 
    {
        Loc++;
        if(head->data == data)
        {
            printf("the node with this data : %d is found at location : %d",data ,Loc);
            return DLL_OK ;
        }
        
    }
    
    // if we reach here this mean that this node with that specific data is not found so we will retrn an error to caller funcltion 
    
    return DLL_ERROR ;
}
