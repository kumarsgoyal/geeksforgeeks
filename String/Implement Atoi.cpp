// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}// } Driver Code Ends
/*You are required to complete this method */
int atoi(string str)
{
    int res = 0;
    int sign = 1; // consider sign as +ve
    int index = 0; // index of string
    
    
    if(str[index] == '-') {
        sign = -1;
        index++;
    }
    
    for(; index < str.length(); index++) {
        if(str[index] >= '0' && str[index] <= '9') {
            res =res *10 + str[index] - '0';
        }
        else {
            return -1;
        }
    }
    
    return res*sign;
    
}
