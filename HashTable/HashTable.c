/*
 * HashTable.c
 *
 *  Created on: Jun 21, 2021
 *      Author: Ahmed_Ayman
 */



#include "HashTable.h"


/* hash table data structure */
struct HashTable_t
{
    struct _Entry ** HashTable_Entries ; /* pointer to pointer  to the entry */
    int Totalsize ;                      /* hold the total size of the Hash table */
    int CurrentSize ;                    /* hold the current  available spaces */

} ;


/* entry data structure */
struct _Entry
{
    uint32_t * Key ;	 		/* Hold the Key for the entry */
    char * Value ;  			/* hold the Value for the entry */
    struct _Entry * Next ;      /* hold the next entry address used if there is no available size in the Hash table  */

};



/* create a new Hash table and return handle to it */
HT_t * HashTable_Create(void)
{
    HT_t * Hash = malloc(sizeof(HT_t));  /* allocate memory for the Hash table data structure */
    if(Hash == NULL) /* check for available heap */
    return NULL ;

    /* initialize Hash data members */
    Hash->Totalsize = HashTableLen ;
    Hash->CurrentSize = 0 ;


    /* allocate space for all entries  length pointers */
    Hash->HashTable_Entries = calloc(HashTableLen,sizeof(Entry_t *));

    if(Hash->HashTable_Entries == NULL) /* check for available heap */
    return NULL ;


    return Hash ;  /* return Hash handler */
}




/* generate a specific Key to given value */
bool HashTable_GenKey(char * Value ,uint32_t  * Key )
{
    if((Value == NULL )||(strlen(Value) == 0 ))   /* check parameter validity */
    return false ;

    uint32_t Temp_Key = 0 ;

    for(int i =0 ; i< strlen(Value);i++)   /* generate random key */
    {
        Temp_Key = Temp_Key * 39 + Value[i] ;
    }

    Temp_Key %= HashTableLen ;
    *Key = Temp_Key ; /* return Key for the caller */

    return true ;
}




/* free the required entry */
bool HashTable_FreeEntry(HT_t * Table , Entry_t ** Item)
{

    if(((*Item) == NULL )||(Table == NULL))  /* check parameter validity */
    return false ;

    bool Entry_exist = false ;   /* variable for check exist of entry */


    /* loop on all exist entries */
    for(int i =0 ;i< HashTableLen;i++)
    {
    	if(Table->HashTable_Entries[i] == (*Item))     /* check if this is valid entry */
    	{
    	Entry_exist = true  ;
    	break ;
    	}
    }

    if(Entry_exist == true )    /* if exist then free memory */
    {
    /* first free item member */
    free((*Item)->Key);
    free((*Item)->Value);

    /* Now we can free item */
    free(*Item) ;

    *Item = NULL ;		/* assign null to item to avoid dangling pointers */
    Table->CurrentSize-- ;			/* decrement  currentsize var with each new insertion */
    return true ;
    }else{   			/* if not exist then return false to caller */
    	return false ;
    }
}




/* free all table entries  */
bool HashTable_Free(HT_t * Table)
{

    if(Table == NULL )		/* check parameter validity */
    return false ;

    for(uint32_t i =0 ; i < HashTableLen ;i++)
    {
        if(Table->HashTable_Entries[i] != NULL)
        HashTable_FreeEntry(Table , &(Table->HashTable_Entries[i]));

    }

    return true ;

}



/* search for specific entry by specific value */
Entry_t ** HashTable_ItemSearch(HT_t * Table , char * Value , uint32_t  * Key_Index )
{
    if((Table == NULL)||(Value == NULL)||(strlen(Value)==0))  		/* check parameter validity */
    return NULL ;

    uint32_t Temp_Key =0 ;
    HashTable_GenKey(Value,&Temp_Key);
    if(!(strcmp(Table->HashTable_Entries[Temp_Key]->Value ,Value)))
    {
    printf("the Value is located in the table with index %d \n ",Temp_Key);

    *Key_Index = Temp_Key ;		/* return key to caller */

    return &(Table->HashTable_Entries[Temp_Key]) ;
    }else{
    printf("this value %s is not exist \n",Value );
    return NULL ;
    }



}



/* insert a new item to hash table */
bool HashTable_InsertItem(HT_t * Table ,char * Value , uint32_t * Key)
{
    if((Table == NULL )||(Value == NULL)||(strlen(Value) == 0 )) 		/* check parameter validity */
    return false ;

    uint32_t Temp_Key =0 ;
    Entry_t * entry ;		/* Temp entry to facilitate handling the entry */

    HashTable_GenKey(Value , & Temp_Key );

    *Key = Temp_Key ; 		/* return Generated Key to caller */

    entry = Table->HashTable_Entries[Temp_Key];
    if(entry == NULL)
    {
    	entry = malloc(sizeof(Entry_t));
        entry->Key    =  malloc(sizeof(uint32_t));
        entry->Value  =  malloc(strlen(Value)+1);

        *(entry->Key) = Temp_Key ;
        strcpy(entry->Value,Value);
        entry->Next = NULL ;
        Table->HashTable_Entries[Temp_Key] = entry ;
        Table->CurrentSize++ ;			/* increment currentsize var with each new insertion */

        return true ;
    }else{
        printf("this Value = %s , already is exist \n",Value);		 /* indication that this value is stored before */
        return false ;
    }



}




/* print all items stored in hash table */
bool HashTable_Printall(HT_t * Table)
{
    if(Table == NULL )		/* check parameter validity */
    return false ;

    for(uint32_t i =0 ; i < HashTableLen ;i++)		/* loop on all hash table entries */
    {
        if(Table->HashTable_Entries[i] != NULL)
        {
        	printf( "Table->HashTable[%d]->Key = %d \n",i,*(Table->HashTable_Entries[i]->Key) );
        	printf( "Table->HashTable[%d]->Value = %s \n",i,Table->HashTable_Entries[i]->Value );
        }
    }

    return true ;

}


