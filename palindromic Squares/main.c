
#include <stdio.h>
#include <stdint.h>

uint32_t GetSum(uint32_t Num);
uint32_t GetSeq(uint32_t Num);
uint32_t Compare(uint32_t Base);

uint32_t GetSum(uint32_t Num)
{
    uint32_t Sum =0;
    for(uint32_t i=0;i<Num;i++)
    Sum +=i;
    
    Sum = (Sum*2)+Num;
    return Sum;
}

uint32_t GetSeq(uint32_t Num)
{
    return Num*Num;
}

uint32_t Compare(uint32_t Base)
{
    uint32_t Sum=0,Seq=0,index =0,Flag =0;
    for(uint32_t Num=0;Num<=300;Num++)
    {
        uint32_t NumArr[300]={0};
    Sum = GetSum(Num);
    Seq = GetSeq(Num);
        index=0,Flag=0;
    if(Sum == Seq)
    {
        while(1)
        {
            
            NumArr[index]=Seq%Base;
            Seq = Seq/10;
            if(Seq==0)
            break;
            index++;
            
        }
        if(index%2 ==0)
        {
        for(uint32_t i=0;i<index;)
        {
            if(NumArr[i]==NumArr[index])
            Flag=1;
            else
            {
            Flag=0;
            break;
            }
            --index;
            ++i;
        }
        if(Flag==1)
        printf("%d   %d\n",Num,Sum);
        }
    }
    }
}

int main()
{

    Compare(3);

    return 0;
}

