
#ifndef __DLL__
#define __DLL__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct _node * DLL_node ; // pointer to incomplete struct 
typedef  uint32_t Item_Type ;

typedef enum   // enum used to indicate the status of operation performed on the list
{
    DLL_ERROR,
    DLL_OK

}DLL_STATUS ;

// use this enums to define this numerical values




DLL_STATUS DLL_Insert_Begining( DLL_node * head,Item_Type data );

DLL_STATUS DLL_Insert_End( DLL_node * head,Item_Type data );

DLL_STATUS DLL_Insert_Spec_Loc( DLL_node * head,Item_Type data , int position  );

DLL_STATUS DLL_Del_Beginning( DLL_node * head );

DLL_STATUS DeleteNodePostion( DLL_node * head,Item_Type data , int position  );

// traverse all nodes and print all nodes data
DLL_STATUS DLL_Print_All( DLL_node  head);

DLL_STATUS DLL_Del_SpecData( DLL_node * head,Item_Type data );

DLL_STATUS DLL_Del_End( DLL_node * head);

DLL_STATUS DLL_Search_NodeSpecData( DLL_node  head, Item_Type data);



#endif // __DLL__
