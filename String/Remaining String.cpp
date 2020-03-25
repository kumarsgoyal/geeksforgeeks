#include <iostream>
using namespace std;

void func(string str, int index) {
    if(index == str.length()) {
        cout<<"Empty string";
        return;
    }
    
    for(int i = index; i < str.length(); i++) {
        cout<<str[i];
    }
    
    
}

int main() {
	int t = 0;
	cin >> t;
	
	while(t--) {
	    string str;
	    char ch; // char to find in string
	    int count; // no. of count to find
	    cin >> str;
	    cin >> ch;
	    cin >> count;
	    
	    int freq = 0;
	    int i = 0;
	    for(; i < str.length(); i++) {
	        if(freq == count)
	            break;
	        else if(str[i] == ch) 
	            freq++;
	    }
	    
	    func(str, i);
	    cout<<endl;
	    
	}
	return 0;
}
