#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n; cin>>n;
    string s[n];
    unordered_map<string, int> m;
    for(int i=0; i<n; i++){
          cin>>s[i];
          m[s[i]]++;  
    }
    
    int j=2;
    int t=0;
    while(j--){
        int max=0;
        for(int i=0; i<n; i++){
            if(m[s[i]]>max){
                 max = m[s[i]];
                 t=i;
            }
        }
        m[s[t]]=0;
    }
    cout<<s[t];
    
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
}
