#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void insertsort(int ele, stack<int> *s) {
    if(s->empty()) {
        s->push(ele);
        return;
    }
    else if(ele >= s->top()) {
        s->push(ele);
        return;
    }
    else {
        int temp = s->top();    
        s->pop();
        insertsort(ele, s);
        s->push(temp);
        return;
    }
}

void sortstack(stack<int> *s) {
    if(!s->empty()) {
        int temp = s->top(); 
        s->pop(); 
        sortstack(s); 
        insertsort(temp, s);
        return;
    }
}


void SortedStack :: sort()
{
   sortstack(&s);
}
