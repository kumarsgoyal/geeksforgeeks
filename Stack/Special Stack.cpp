#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends
/*Complete the function(s) below*/
void push(int a)
{
     //add code here.
     if(s.empty()) {
         s.push(a);
        s.push(a);
     }
     else {
         int m = min(a, s.top());
         s.push(a);
         s.push(m);
     }
}

bool isFull(int n)
{
     if(s.size() == (2*n)) {
         return true;
     }
     return false;
}

bool isEmpty()
{
    if(s.size() == 0) {
        return true;
    }
    return false;
}

int pop()
{
    s.pop();
    int res = s.top();
    s.pop();
    return res;
}

int getMin()
{
   return s.top();
}
