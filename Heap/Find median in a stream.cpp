#include <bits/stdc++.h>
using namespace std; 

int main() {
    int size = 0;
    cin >> size;
    
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int size1 = 0, size2 = 0;
    
    int num;
    for(int i = 0; i < size; i++) {
        cin >> num;
        if(size1 == 0 || max.top() > num) {
            size1++;
            max.push(num);
        }
        else {
            size2++;
            min.push(num);
        }
        
        if(abs(size2 - size1) > 1) {
            if(size1 > size2) {
                min.push(max.top());
                max.pop();
                size1--;
                size2++;
            }
            else {
                max.push(min.top());
                min.pop();
                size2--;
                size1++;
            }
        }
        
        if(i%2) { // even element
            if(size2) {
                cout<<(min.top() + max.top())/2<<endl;
            }
            else {
                cout<<max.top()<<endl;
            }
        }
        else {
            if(size1 > size2) {
                cout<<max.top()<<endl;
            }
            else {
                cout<<min.top()<<endl;
            }
        }
        
        
    }
}
