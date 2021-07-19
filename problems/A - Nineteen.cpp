#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include<string.h>
int NumberOFWords(char word[]);
void splitTheString(char word[]);

struct{
    int n;
    int t;
    int e;
    int i;
    int words;
}numberOf={0,0,0,0,0};


int main()
{
    char word[1000];
    scanf("%s",word);
    splitTheString(word);
    printf("%d",NumberOFWords(word));


   return 0;
}
void splitTheString(char word[])
{
    for(int i=0;i<strlen(word);i++)
    {
        if(word[i]=='n')
            numberOf.n++;
        else if(word[i]=='t')
            numberOf.t++;
        else if(word[i]=='e')
            numberOf.e++;
        else if(word[i]=='i')
            numberOf.i++;
    }

}
int NumberOFWords(char word[])
{
    while(numberOf.n>=3&&numberOf.e>=3&&numberOf.t>=1&&numberOf.i>=1)
    {
        numberOf.words++;
        numberOf.n-=2;
        numberOf.e-=3;
        numberOf.t-=1;
        numberOf.i-=1;
    }
    return numberOf.words;


















}