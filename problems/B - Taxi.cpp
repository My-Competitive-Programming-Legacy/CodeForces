/** ||  ||
    ||  ||
    ||  ||
    ||  ||
    ||||||
    ||  ||
    ||  ||
    ||  ||
    ||  ||HAMZA
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int arr[100000]={0},have[4]={0},taxi=0;
    int i,n,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {

        scanf("%d",&arr[i]); /// %1d because the value will never exceed 4
       if(arr[i]==4)
         taxi++;
        else
        {
            have[arr[i]]++;
        }
    }
    /// HACKER RANK TIME
    if(have[1]==n)
    {
        taxi+=ceil((double)have[1]/4);
        printf("%d",taxi);
        return 0;
    }
    /// REDUCE THE TWINS

    if(have[2]%2==0&&have[2]!=0)
    {
        taxi+=(have[2]/2);
        have[2]=0;
    }else if(have[2]%2==1)
    {
        taxi+=(have[2]/2);
        have[2]=1;
            ///INDIVIDUALS SACRIFICE FOR TWINS
            if(have[1]>=2)
            {
                have[2]=0;
                have[1]-=2;
                taxi++;
            }else if(have[1]==1)
            {
                have[2]=0;
                have[1]--;
                taxi++;
            }else
            {
                taxi+=have[2]+have[3];
                printf("%d",taxi);

                return 0; ///NO ONE SACRIFICES :XD "SAD"
            }




    }

    ///INDIVIDUALS SACRIFICE FOR TRIBLES

    if(have[1]>=have[3])
    {
        taxi+=have[3];
        have[3]==0;
        have[1]-=have[3];
    }else
    {
        taxi+=have[3]; ///as well
        have[1]=0;
    }
    taxi+=ceil(((double)have[1])/4);
    printf("%d",taxi);



    return 0;
}






/*

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   ///158B >> CODE FORCES
///EXCEEDS TIME LIMIT 3 SEC IN LARGE INPUTS

int main()
{
    int arr[10000]={0},need[5]={0},taxi=0,individuals=0;
    int i,n,s;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]); /// %1d because the value will never exceed 4

    }
    ///START PROCESSING
    for(i=1;i<=n;i++)
    {
        if(arr[i]==4)
        {
        taxi++;
        }
        else if(arr[i]==1)  ///AVOIDING BUGS
        {
            individuals++;
        }
        else if(need[arr[i]]!=0)
        {
        need[arr[i]]--;
        }
        else
        {
        need[4-arr[i]]++;
        taxi++;
        }



    }
    ///EDITING TAXI NUMBERS
    int space=need[1]+2*need[2]+3*need[3];
    if(space>=individuals)
    {
        space-=individuals; ///TAXI NUMBERS WILL NOT CHANGE
    }else
    {
        individuals-=space;
        double temp=individuals;
        taxi+=ceil(temp/4);
    }


    printf("%d",taxi);


    return 0;
}


*/