#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
void function(char word[],int n);
int main()
{
    int n =0;
    char word[100];
    scanf("%d",&n);
    function(word,n);
    return 0;

}

void function(char word[],int n)
{
    if(n==0)
        return;

    scanf("%s",word);

    if(strlen(word)>10)
    {
        printf("%c%d%c\n",word[0],strlen(word)-2,word[strlen(word)-1]);
    }else
    {
        printf("%s\n",word);
    }
    function( word, n-1);
}







