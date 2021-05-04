this example is about problem solving if we need to determine if there is repeated element in a given array 
#include <stdio.h>
#include <stdint.h>

unsigned long long arr1[2]={0,0};
uint32_t arr[128]={0};




int main()
{
uint32_t i=0;
for(i=0;i<128;i++)
{
    arr[i]=i;
    if(i==100)
    arr[i]=10;
}
for(i=0;i<128;i++)
{
//    arr[i]=i;
printf("  %d \n",arr[i]);
    
}
for(i=0;i<128;i++)
{
    if(i<64)
    arr1[0] ^= (1<<arr[i]);
    else
    arr1[1] ^= (1<<(arr[i]-64));
}

printf(" %x \n",arr1[0]);
printf(" %x \n",arr1[1]);



    return 0;
}

