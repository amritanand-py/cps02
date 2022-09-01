#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int list[n],i;
    for(i=0;i<n;i++)    scanf("%d",&list[i]);
    int key = list[n-1];
    int j = n-2;
    while(j>=0 && list[j]>key)
    {
        list[j+1] = list[j];
        j--;
    }
    list[j+1] = key;
    for(i=0;i<n;i++)    printf("%d ",list[i]);
    return 0;
}
