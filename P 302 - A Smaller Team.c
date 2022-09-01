#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,i,j;
    scanf("%d",&n);
    int list[n];
    for(i=0;i<n;i++)    scanf("%d",&list[i]);
    int k;
    scanf("%d",&k);
    for(i=0;i<n-1;i++)
    {
        if(k-- == 0)    break;
        int minIndex = i;
        for(j=i+1;j<n;j++)
            if(list[minIndex] > list[j])
                minIndex = j;
        int temp = list[i];
        list[i] = list[minIndex];
        list[minIndex] = temp;
    }
    for(i=0;i<n;i++)    printf("%d ",list[i]);
    return 0;
}
