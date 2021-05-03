

#include "SLL.h"


struct _node {
    int data  ;
    struct _node * next;
};



// this fuction is to implement the insert function at the beging of the list

void SLL_Insert_Begining( SSL_PtrNode * head , int data )
{
     SSL_PtrNode new_node = ( SSL_PtrNode )malloc(sizeof(struct _node ));
 if(*head == NULL)   // first node in the list
 {
     *head = new_node;
     new_node->next = NULL;
    new_node->data = data;
     return;

 }

    new_node->next = *head;
    *head = new_node;
    new_node->data = data;

}

// this function is to print all node in the list

void SLL_Print_All( SSL_PtrNode  head )
{
    int counter = 0;
    if(head == NULL)
    {
        printf("empty list : \n");
        return;
    }
    while(head != NULL)
    {
        printf(" %d \n",head->data);
        counter ++;
        head = head->next;
    }

}

void SLL_Insert_Spec_Loc( SSL_PtrNode * head ,int data,int location)
{
     SSL_PtrNode  new_node = ( SSL_PtrNode )malloc(sizeof(struct _node ));
     SSL_PtrNode  temp_node = *head ;
    int counter =0;

    if((*head == NULL)||(location==0))
    {
        printf("empty node so we add the first node with data = %d to list :\n ",data);
        SLL_Insert_Begining(head,data);
        return;
    }
    while(temp_node != NULL)
    {
        if(temp_node->next == NULL)
        break;

        counter ++;
        if(counter == location)
        break;
       temp_node = temp_node->next;

    }
    if(location>counter)
    {
        printf("this location is note allocated we insert this node with data = %d at the end :\n",data);
        SLL_Insert_End(head,data);
        return;
    }

    new_node->next = temp_node->next;
    temp_node->next = new_node;
    new_node->data = data;
}

//search with specific node data

 SSL_PtrNode  SLL_Search_NodeSpecData( SSL_PtrNode  head, int data)
{
    int node_number=0;
    SSL_PtrNode node_add=NULL;
    if(head == NULL)
    {
        printf("empty node :");
        return NULL;
    }
    while(head != NULL)
    {

        if(head->data  == data)
        {
            node_add = head;
            printf("node is founded : with data :%d ,with node number %d\n",head->data,node_number);
        }
        node_number++;
        head = head->next;
    }
    if(node_add == NULL)
    {
        printf("the node is note founde !!!! with data = %d \n",data);
    }
    return node_add;
}

void SLL_Insert_End ( SSL_PtrNode * head ,int  data)
{
     SSL_PtrNode  new_node = ( SSL_PtrNode )malloc(sizeof(struct _node ));
     SSL_PtrNode  temp_head=*head ;

    if(*head == NULL)
    {
        printf("this is empty node so we add at the head with data = %d \n",data);
        SLL_Insert_Begining(head,data);
        return;
    }
    while(temp_head != NULL)
    {
        if(temp_head->next == NULL)
        break;
        temp_head = temp_head->next;
    }
    temp_head->next = new_node;
    new_node->next = NULL;
    new_node->data = data;

}
// delete node at beging
void SLL_Del_Beginning( SSL_PtrNode  *head )
{
     SSL_PtrNode temp_node=NULL;
    if(*head == NULL)
    {
        printf("empity list : \n");
        return;
    }
    temp_node= *head;
    *head = (*head)->next;
    free(temp_node);
}

// delete the node from the end
void SLL_Del_End( SSL_PtrNode * head)
{

    while(*head != NULL)
    {
        if((*head)->next->next == NULL)
        break;

        (*head) = (*head)->next;
    }
    free((*head)->next);
    (*head)->next= NULL;
}

// delete node with given data
void SLL_Del_SpecData( SSL_PtrNode * head ,int data)
{
     SSL_PtrNode temp_node=*head;
    if(*head == NULL)
    {
        printf("empty node mean that there is no node  with data = %dto delete \n",data);
        return;

    }
    if((*head)->data == data)
    {
        SLL_Del_Beginning(head);
        return;
    }
    while(data != temp_node->data)
    {
        if(temp_node->next->data == data)
        break;

        temp_node = temp_node->next;
    }
    free(temp_node->next);
    temp_node->next = temp_node->next->next;
}
