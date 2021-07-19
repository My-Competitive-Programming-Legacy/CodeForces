#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,k,i,arr[50],advancers=0;
    scanf("%d %d",&n,&k);


    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    if(arr[k-1]==0)
    {
        for(i=0;i<n;i++)
        {
            if(arr[i]>arr[k-1])
                advancers++;
        }
        printf("%d",advancers);
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]>=arr[k-1])
            advancers++;
    }
    printf("%d",advancers);
    return 0;
}






























/*--------------------------------------------------------------int main()
{
    int n,k,i;
    int advancers=0,ref=0;
    scanf("%d%d",&n,&k);

    int arr[50];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    ref=arr[k-1];

    if(ref==0||ref<0)
    {
        printf("%d",0);
        return 0;
    }

    i=0;
    while(arr[i]>=ref||i<n)
    {
        advancers++;
        i++;
    }

    printf("%d",advancers);



return 0;

}
-----------------------------------------------------------------------*/