

#include "XOR_DLL.h"

// this struct is defined as incomplete type  this made high level of abstraction to avoid 
// corruption from the application 
struct XOR_DLL_NODE      
{
    uint32_t data ;
    XOR_DLL_node PreNextPtr ;
};

// this function used to insert node at the begining of the list 
XOR_DLL_STATUS XOR_DLL_Insert_Begining(XOR_DLL_node * head,uint32_t data )
{
    XOR_DLL_node  New_node = (XOR_DLL_node )malloc(sizeof(struct XOR_DLL_NODE));
    if(New_node == NULL)
        return XOR_DLL_ERROR;
    
    if(*head == NULL)
    {
        printf("you try to add to empty list so we will init a new list \n ");
        New_node->data = data ;
        New_node->PreNextPtr = NULL ;
        *head = New_node ;
        return XOR_DLL_OK ;
    }else{
        New_node->data = data ;
        New_node->PreNextPtr = *head ;
        (*head)->PreNextPtr = RESLUT_OF_XOR((*head)->PreNextPtr,New_node);
        *head = New_node;
    }

    return XOR_DLL_OK ;
}


// this function will create anew node an mount it at the end of the list 
// if the list is empty so it will create anew list 
XOR_DLL_STATUS XOR_DLL_Insert_End(XOR_DLL_node * head,uint32_t data )
{
    XOR_DLL_node  Prev =NULL,Prev_Old =NULL ,iterator = *head; 
    XOR_DLL_node  New_Node = (XOR_DLL_node )malloc(sizeof(struct XOR_DLL_NODE));
    if(*head == NULL)
    {
        printf("you try to add to empty list so we will init a new list \n ");
        return XOR_DLL_Insert_Begining(head ,data);        
    }
    
    while(RESLUT_OF_XOR(Prev,iterator->PreNextPtr) != NULL)
    {

        Prev_Old = iterator ;
        iterator =RESLUT_OF_XOR(Prev,iterator->PreNextPtr); 
        Prev = Prev_Old ;
    }
    iterator->PreNextPtr = RESLUT_OF_XOR(New_Node,iterator->PreNextPtr);
    New_Node->data = data ;
    New_Node->PreNextPtr = iterator ;
    return XOR_DLL_OK ;

}

// this function used to add anew node at specific location but if that location is not found then will add 
// and if the head pointer point to null means empty list and the function will create a new list 
//this node at the end and at the same time hint the user that this location is not found 


XOR_DLL_STATUS XOR_DLL_Insert_Spec_Loc(XOR_DLL_node * head,uint32_t data , uint32_t position  )
{
    if((*head == NULL)||(position == 1))
    {
        printf("you try to add to empty list the new list wil created \n");
        XOR_DLL_Insert_Begining(head ,data);
        return XOR_DLL_OK ;
    }
    
    XOR_DLL_node  iterator = *head ,Prev = NULL ,Prev_Old = NULL;
    XOR_DLL_node  New_Node =NULL ;


    uint32_t location = 0 ;
    while((iterator != NULL ))
    {
        location++;
        if(location > position)
        {
            printf("position is not found the node will added at the end \n");
            XOR_DLL_Insert_End(head ,data);
            return XOR_DLL_OK ;
        }
        
        if(location == position)
        {
            New_Node =(XOR_DLL_node )malloc(sizeof(struct XOR_DLL_NODE));
            if(New_Node == NULL )
            return XOR_DLL_ERROR ;
    
            New_Node->data = data ;
            New_Node->PreNextPtr = RESLUT_OF_XOR(iterator,Prev);
            
            Prev->PreNextPtr = RESLUT_OF_XOR(RESLUT_OF_XOR(iterator,New_Node),Prev->PreNextPtr);
            iterator->PreNextPtr = RESLUT_OF_XOR(RESLUT_OF_XOR(Prev,New_Node),iterator->PreNextPtr);
            return XOR_DLL_OK ;
            
        }
        Prev_Old = iterator ;
        iterator =RESLUT_OF_XOR(Prev,iterator->PreNextPtr); 
        Prev = Prev_Old ;
    }
    printf("location is not found new node will created at the end of the list\n");
    XOR_DLL_Insert_End(head,data); // location is not found add the data at the end 
    return XOR_DLL_ERROR ;         // also here return an error this means that there is an wrong in operation 
}



// this function is used to delete the first node in the list 
// and then free this loction from the heap 

XOR_DLL_STATUS XOR_DLL_Del_Beginning( XOR_DLL_node * head )
{
    if(*head == NULL)
    {
        printf("you try to dalete from empty list \n");
        return XOR_DLL_ERROR ;
    }
        
    if(((*head)->PreNextPtr) == NULL) // check if list contain only one node  
    {
        ////////////////// from list contain only one node ///////////////////////
        free(*head);
        *head = NULL;
        return XOR_DLL_OK ;
    }
        
        
    XOR_DLL_node  Temp = *head ;       // temp pointer used to hold the pointer to the first locstion that will be free
    *head = (*head)->PreNextPtr ;
    (*head)->PreNextPtr = RESLUT_OF_XOR((*head)->PreNextPtr,Temp);
    free(Temp);
    return XOR_DLL_OK ;
}

XOR_DLL_STATUS XOR_DeleteNodePostion( XOR_DLL_node * head, uint32_t position)
{
    if((*head == NULL)||(position == 0))  // check on the head that not contain null pointer 
    {
        printf("you are tring to delete from empty list \n");
        return XOR_DLL_ERROR ;
    }
    
    if(position == 1)  // check if the application try to delete from the head  of the list 
    {
        XOR_DLL_Del_Beginning(head);
        return XOR_DLL_OK ;
    }
    
    XOR_DLL_node  iterator = *head ,Prev = NULL ,Prev_Old=NULL ,iterator_Next = NULL;
    XOR_DLL_node  Temp =NULL ;


    uint32_t location = 0 ;
    while((iterator != NULL ))
    {
        location++;
        if(location > position)
        {
            printf("position is not found  \n");
            return XOR_DLL_ERROR;
        }
        
        if(location == position)
        {
            Temp = iterator ;
            iterator_Next = RESLUT_OF_XOR(Prev,iterator->PreNextPtr);  // optain the address of hte next node 
            Prev->PreNextPtr = RESLUT_OF_XOR(RESLUT_OF_XOR(iterator,Prev->PreNextPtr),iterator_Next); //modify the PreNextPtr in previous node
            iterator_Next->PreNextPtr = RESLUT_OF_XOR(RESLUT_OF_XOR(Prev,iterator),iterator_Next->PreNextPtr); 
            free(Temp);
            return XOR_DLL_OK ;
        }
        Prev_Old = iterator ;
        iterator =RESLUT_OF_XOR(Prev,iterator->PreNextPtr); 
        Prev = Prev_Old ;
    }
    printf("location is not found \n");
    return XOR_DLL_ERROR ;  

}

// traverse all nodes and print all nodes data
// 
XOR_DLL_STATUS XOR_DLL_Print_All( XOR_DLL_node head)
{
    if(head == NULL)
    {
        printf("sorry you passed an null Ptr in print all function \n"); // hit the user where is the problom to try to solve
        return XOR_DLL_ERROR ;                  // and return an error to make the application to make a decision  
    }
    XOR_DLL_node Prev_Old = NULL,Prev = NULL  ,Curr = head ;
    uint32_t Loc =0;
    while(Curr != NULL )
    { 
        Loc++;
        printf("data is  :%d at location :%d\n ",Curr->data,Loc);
        Prev_Old = Curr ;
        Curr =RESLUT_OF_XOR(Prev,Curr->PreNextPtr); 
        Prev = Prev_Old ;

    }
    return XOR_DLL_OK ;                      
}


// this function used if the user need to delete a specific node but don't no its location  
// so after deletion succfully this function will print to the user what is the location of that node 
// if this node is note found the will print this node with this data is note found 

XOR_DLL_STATUS XOR_DLL_Del_SpecData( XOR_DLL_node * head,uint32_t data )
{
    if(*head == NULL )
    {
        printf("you try to delete from empty list");
        return XOR_DLL_ERROR ;
    }
    
    XOR_DLL_node  iterator = *head ,Prev = NULL ,Prev_Old = NULL,NextItrerator =NULL ;
    uint32_t Node_Loc = 0;

    while((iterator != NULL ))  ///// traverse on all the nodes in the list till reach the end or find the specific node  
    {
        Node_Loc++;
        if(iterator->data == data )
        {

            printf("delete operation on node with data :%d is located at loction :%d is performed succfully\n" ,iterator->data,Node_Loc);
            if(*head == iterator)   ///// check if the iterator is the first node 
            {
                XOR_DLL_Del_Beginning(head);      
                return XOR_DLL_OK;
            }
            if(RESLUT_OF_XOR(Prev,iterator->PreNextPtr) == NULL) // check if itrerator is the last node 
            {
             //////////////////////// dalete fron the end /////////////////////////////////////
                Prev->PreNextPtr = RESLUT_OF_XOR(iterator , Prev->PreNextPtr) ;
                free(iterator);
                return XOR_DLL_OK ;
            }
            NextItrerator = RESLUT_OF_XOR(iterator->PreNextPtr , Prev );
            // prev->prenextptr ^ Curr ^ nextnode 
            Prev->PreNextPtr =          RESLUT_OF_XOR(RESLUT_OF_XOR(NextItrerator,iterator),Prev->PreNextPtr);
            // prev ^ curr ^ nextnode->prenextptr
            NextItrerator->PreNextPtr = RESLUT_OF_XOR(RESLUT_OF_XOR(NextItrerator->PreNextPtr,iterator),Prev);
            free(iterator);
            return XOR_DLL_OK ;
        }
        Prev_Old = iterator;
        iterator = RESLUT_OF_XOR(Prev , iterator->PreNextPtr);
        Prev = Prev_Old ;
    }
        printf("node is not found ");
        return XOR_DLL_ERROR ;      // node is not found 

}

XOR_DLL_STATUS XOR_DLL_Del_End( XOR_DLL_node * head)
{
    if(*head == NULL)
    {
        printf("you try to delete from empty list \n" );
        return XOR_DLL_ERROR ;
    }
    if((*head)->PreNextPtr == NULL)
    {
        printf("this node is contaion only one node will free the list \n");
        free(*head);
        *head = NULL ;
        return XOR_DLL_OK ;
    }
    
    XOR_DLL_node  iterator = *head ,  Prev = NULL ,Prev_Old = NULL;
    while(RESLUT_OF_XOR(Prev,iterator->PreNextPtr) != NULL)
    {

        Prev_Old = iterator ;
        iterator =RESLUT_OF_XOR(Prev,iterator->PreNextPtr); 
        Prev = Prev_Old ;
    }
  
    Prev->PreNextPtr = RESLUT_OF_XOR(iterator , Prev->PreNextPtr) ;
    free(iterator);
    iterator = NULL;
    return XOR_DLL_OK ;

}

XOR_DLL_STATUS XOR_DLL_Search_NodeSpecData( XOR_DLL_node  head, int data)
{
    if(head == NULL )
    {
        printf("you try to search in empty list");
        return XOR_DLL_ERROR ;
    }

    XOR_DLL_node  iterator = head ,Prev = NULL ,Prev_Old = NULL ;
    uint32_t Node_Loc = 0;

    while((iterator != NULL ))
    {
        Node_Loc++;
        if(iterator->data == data )
        {
            printf("node with data :%d is located at loction :%d\n",Node_Loc ,iterator->data);
            return XOR_DLL_OK ;
        }
        Prev_Old = iterator;
        iterator = RESLUT_OF_XOR(Prev , iterator->PreNextPtr);
        Prev = Prev_Old ;
    }
        printf("node is with data %d not found \n",data);
        return XOR_DLL_ERROR ;      // node is not found 


}



