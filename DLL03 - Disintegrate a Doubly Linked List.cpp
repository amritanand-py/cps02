#include<stdio.h>

int main()
{
    int n,i,k,arr[100],pos;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&k);
    for(i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            pos=i;
        }
    }
    for(i=pos-1;i>=0;i--)
        printf("%d\n",arr[i]);
    for(i=pos+1;i<n;i++)
        printf("%d\n",arr[i]);
return 0;
}