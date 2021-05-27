#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    stack<int>st;
    int  n,   x;
    cin>>n;
    for(int i=0; i<n; i++){
        int q;
        cin>>q;
        switch(q){
            case 1:
            cin>>x;
            if(st.empty())
            st.push(x);
            else
            st.push(max(x, st.top()));
            break;
            case 2:
            if(!st.empty())
            st.pop();
            break;
            case 3:
            cout<<st.top()<<endl;
            break;
            default:
            break;
        }
    }
    return 0;
}
