using namespace std;

struct key {
    int freq;
    char ch;
    bool operator<(const key &k) const
    { 
        return freq < k.freq; 
    }
};

int main() {
	int t = 0;
	cin>>t;
	while(t--) {
	    string str;
	    string res = "";
	    int charfreq[26] = {0};
	   
	    cin>>str;
	    for(int i = 0; i < str.length(); i++) {
	        charfreq[str[i] - 'a'] += 1;
	    }
	    
	    priority_queue<key> que;
	    
	    for(char c = 'a'; c <= 'z'; c++ ) {
	        if(charfreq[c - 'a']) {
	            que.push(key{charfreq[c - 'a'], c});
	        }
	    }
	    
	    key prev {-1, '#'};
	    
	    while(!que.empty()) {
	        key temp = que.top();
	        que.pop();
	        
	        res = res + temp.ch;
	        
	        if(prev.freq > 0) {
	            que.push(prev);
	        }
	        
	        temp.freq--;
	        prev = temp;
	    }
	    
	    if(res.length() == str.length()) {
	        cout<<1<<endl;
	    }
	    
	    else {
	        cout<<0<<endl;
	    }
	    
	}
	return 0;
}
