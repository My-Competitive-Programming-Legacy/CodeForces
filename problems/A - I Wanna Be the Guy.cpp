#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
void function(char word[],int n);
int main()
{
    int arr[100]={0};
    int n,temp,p,q,flag = 1;
    scanf("%d",&n); ///THE NUMBER OF LEVELS IN THE GAME
    for(int i=0;i<2;i++)
    {
        scanf("%d",&p);
        for(int j=1;j<=p;j++)
        {
            scanf("%d",&temp);
            arr[temp]=1;
        }
        ///WHEN I = 1 P WILL BE Q
    }
    for(int i =1;i<=n;i++)
    {
        if(arr[i]==0)
        {flag=0;break;}
    }
    puts(flag==1? "I become the guy.":"Oh, my keyboard!");


   return 0;

}
/**
ALGORITHM


 for(int i =1;i<=(2*n-1);i++)
    {
        scanf("%d",&temp);
        arr[temp] = 1;
    }
    for(int i =1;i<=n;i++)
    {
        if(arr[i]==0)
        {flag=0;break;}
    }
    puts(flag==1? "I become the guy.":"Oh, my keyboard!");








*/







