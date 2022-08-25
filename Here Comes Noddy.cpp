#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a,b;
    cin>>a>>b;
    int arr[a][b];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>arr[i][j];
        }
    }

int k=0,l=0,m=a,n=b;    
while (k < m && l < n) 
    { 
        for (int i = l; i < n; ++i) 
        { 
            printf("%d ", arr[k][i]); 
        } 
        k++; 

        for (int i = k; i < m; ++i) 
        { 
            printf("%d ", arr[i][n-1]); 
        } 
        n--; 

        if ( k < m) 
        { 
            for (int i = n-1; i >= l; --i) 
            { 
                printf("%d ", arr[m-1][i]); 
            } 
            m--; 
        } 

        if (l < n) 
        { 
            for (int i = m-1; i >= k; --i) 
            { 
                printf("%d ", arr[i][l]); 
            } 
            l++;     
        }         
    } 
    return 0;

} 