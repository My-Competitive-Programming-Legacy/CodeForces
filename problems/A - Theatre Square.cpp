#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include<string.h>

unsigned long long int howManyBoxesRequired(unsigned long long int a,unsigned long long int b);
int main()
{
    unsigned long long int a,b,c;
    scanf("%llu%llu%llu",&a,&b,&c);
    unsigned long long int x = howManyBoxesRequired(a,c);
    unsigned long long int y = howManyBoxesRequired(b,c);
    printf("%llu",x*y);



   return 0;
}

unsigned long long int howManyBoxesRequired(unsigned long long int a,unsigned long long int b)
{
   if(a<b)
    return 1;
    int j=0;
    while(a%b!=0&&j++<100)
    {
       a+=1;

    }
    if(j<=100)
        return a/b;
    else
    {
        j=1;
        unsigned long long temp=b;
        while(a>temp)
        {
            temp = (j++)*b;
        }
        return j-1;









    }
}