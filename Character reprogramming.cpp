#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'getMaxDeletions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int getMaxDeletions(string s) {
	int x=0,y=0,count=0;
	for(char ch :s){
    	if(ch=='R')
    	{
        	x++;
        	count++;
    	}
    	else if(ch=='L'){
        	x--;
        	count ++;
    	}
    	else if(ch=='U'){
        	y++;
        	count++;
    	}
    	else if(ch=='D'){
        	y--;
        	count++;
    	}
	}
	return count-abs(x)-abs(y);
}
	
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = getMaxDeletions(s);

    fout << result << "\n";

    fout.close();

    return 0;
}