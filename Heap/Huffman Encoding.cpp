#include <bits/stdc++.h>
using namespace std;

struct mystructure {
    char ch;  // character
    int freq;  // frequency
    
    struct mystructure *left;  //left child
    struct mystructure *right;  // right child
    
    mystructure(char c, int f, mystructure *l, mystructure *r) :
        ch(c), freq(f), left(l), right(r) {} 
   
};

struct minheap {
    mystructure *min; 
    
    minheap(char c, int f, mystructure *l, mystructure *r) {
        min = new mystructure(c, f, l, r);
    }
    
    
    bool operator<(const minheap &k) const
    { 
        return min->freq > k.min->freq; 
    }
};


void createminheap(string str, int *freq, priority_queue<minheap> &que) {
    for(int i = 0; i <str.length(); i++) {
        que.push(minheap{str[i], freq[i], NULL, NULL});
    }
}

void gethuffmancode(priority_queue<minheap> &que) {
    while(que.size() != 1) {
        minheap left = que.top();
        que.pop();
        minheap right = que.top();
        que.pop();
        
        int freq = left.min->freq + right.min->freq;
        que.push(minheap{'#', freq, left.min, right.min});
    }
    
}

void printArr(char *str, int size) {
    for(int i = 0; i < size; i++) {
        cout<<str[i];
    }
}

void printminheap(mystructure *root, char *res, int i) {
    
    if (root->left) { 
        // assign 0 to left edge and recur  
        res[i] = '0'; 
        printminheap(root->left, res, i + 1); 
    } 
  
    // Assign 1 to right edge and recur 
    if (root->right) { 
  
        res[i] = '1'; 
        printminheap(root->right, res, i + 1); 
    } 

    if (!root->left && !root->right) { 
  
        // printf("%c: ", root->ch); 
        printArr(res, i); 
        cout<<" ";
    } 
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    
	    string str; //msg
	    cin>>str;
	    
	    int *freq = new int[str.length()]; // array for frequency
	    for(int i = 0; i < str.length(); i++) {
	        cin>>freq[i];
	    }
	    
	    priority_queue<minheap> que; 
	    
	    // intially insert all node and frequency in min heap
	    createminheap(str, freq, que);
	    gethuffmancode(que);
	    mystructure *root = que.top().min;
	    char *res = new char[100];
    	printminheap(root, res, 0);
    	cout<<endl;
	    
	}
	return 0;
}
