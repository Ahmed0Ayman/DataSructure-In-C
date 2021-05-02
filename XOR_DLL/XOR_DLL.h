
#ifndef __XORDLL__
#define __XORDLL__



#ifndef __DLINKEDLIST__
#define __DLINKEDLIST__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


#define RESLUT_OF_XOR(ADD1,ADD2)       ((XOR_DLL_node )(((uint64_t )(ADD1))^((uint64_t )(ADD2))))

typedef struct XOR_DLL_NODE *XOR_DLL_node ;  // incomplete data type defined to use by the application 

typedef enum   // enum used to indicate the status of operation performed on the list
{
    XOR_DLL_ERROR,
    XOR_DLL_OK

}XOR_DLL_STATUS ;


XOR_DLL_STATUS XOR_DLL_Insert_Begining( XOR_DLL_node * head,uint32_t data );

XOR_DLL_STATUS XOR_DLL_Insert_End( XOR_DLL_node * head,uint32_t data );

XOR_DLL_STATUS XOR_DLL_Insert_Spec_Loc( XOR_DLL_node * head,uint32_t data , uint32_t position  );

XOR_DLL_STATUS XOR_DLL_Del_Beginning( XOR_DLL_node * head );

XOR_DLL_STATUS XOR_DeleteNodePostion( XOR_DLL_node * head, uint32_t position  );

// traverse all nodes and print all nodes data
XOR_DLL_STATUS XOR_DLL_Print_All( XOR_DLL_node head);

XOR_DLL_STATUS XOR_DLL_Del_SpecData( XOR_DLL_node * head,uint32_t data );

XOR_DLL_STATUS XOR_DLL_Del_End( XOR_DLL_node * head);

XOR_DLL_STATUS XOR_DLL_Search_NodeSpecData( XOR_DLL_node head, int data);



#endif // __DLINKEDLIST__




















#endif // __XORDLL__
