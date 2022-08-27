#include <bits/stdc++.h>
using namespace std;
int minSwaps(string s) {
        int extra =0;
        int maxElem =INT_MIN;
        
        
        for(auto x : s){
            if(x==')') {
                extra++;
            }
            else{
                extra--;
            }
            
            maxElem = max(maxElem , extra);
        }
        int re = (maxElem+1)/2;
        
        if(extra>0) return -1;
        else return re;
    }// Driver code
int main()
{
 
	string p;
	cin>>p;
 
	// Function to print required answer
	cout << minSwaps(p);
 
	return 0;
}