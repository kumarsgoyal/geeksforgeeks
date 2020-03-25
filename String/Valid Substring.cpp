using namespace std;

int valid(string str) {
    stack<int> stk;
    stk.push(-1);
    int i = 0;
    int Max = 0;
    while(str[i] != '\0') {
        if(str[i] == '(') {
            stk.push(i);
        }
        else {
            stk.pop();
            if(!stk.empty()) {
                Max = max(i-stk.top(), Max);
            }
            else {
                stk.push(i);
            }
        }
        i++;
    }
    return Max;
}

int main() {
	int t = 0;
	cin>> t;
	while(t--) {
	    string str;
	    cin>>str;
	    
	    cout<<valid(str)<<"\n";
	}
	return 0;
}
