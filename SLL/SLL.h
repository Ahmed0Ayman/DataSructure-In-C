
#ifndef  __SLL__
#define  __SLL__


#include <stdio.h>
#include <stdlib.h>


#define NULL ((void *)0)

typedef struct _node *SSL_PtrNode ;

void   SLL_Insert_Begining(SSL_PtrNode * head , int data );
void   SLL_Print_All( SSL_PtrNode  head );
void   SLL_Insert_Spec_Loc( SSL_PtrNode * head ,int data,int location);
SSL_PtrNode SLL_Search_NodeSpecData( SSL_PtrNode  head, int data);
void   SLL_Insert_End ( SSL_PtrNode * head ,int  data);
void   SLL_Del_Beginning( SSL_PtrNode *head );
void   SLL_Del_End(SSL_PtrNode * head);
void   SLL_Del_SpecData( SSL_PtrNode * head ,int data);




#endif /* __SLL__ */
