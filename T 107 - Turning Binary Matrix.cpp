#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[2];
void rotate(int i,int j, int n, int angle){
    if(angle==0){
        arr[0]=i;
        arr[1]=j;
    }
    else{
        arr[0]=n-j-1;
        arr[1]=i;
        rotate(arr[0],arr[1],n,angle-90);
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i,j;
    cin>>n;
    int mat[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int barr[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int ax,ay,bx,by,cx,cy;
            rotate(i,j,n,90);
            ax=arr[0];
            ay=arr[1];
            rotate(i,j,n,180);
            bx=arr[0];
            by=arr[1];
            rotate(i,j,n,270);
            cx=arr[0];
            cy=arr[1];
            //cout<<ax<<" "<<ay<<" "<<bx<<" "<<by<<" "<<cx<<" "<<cy<<endl;
            if(mat[i][j]==1||mat[ax][ay]==1||mat[bx][by]==1||mat[cx][cy]==1){
                barr[i][j]=1;
            }
            else{
                barr[i][j]=0;
            }
        }

    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<barr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}