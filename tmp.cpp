#include<bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << " = " << a << endl;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string s="";
        stack <char > a;
        int total=0, i, j, l;
        char ch;
        for(i=0;i<n;i++){
            if(a.empty()){
                a.push(num[i]);
            }
            else{
                ch = a.top();
                // cout<<ch<<" "<<num[i]<<endl;
                if(ch>num[i]){
                    a.pop();
                    total++;
                    if(k==total) break;
                    i--;
                }
                else{
                    a.push(num[i]);
                }
            }
        }
        cout<<total<<" "<<i<<endl;
        while(total!=k){
            a.pop();
            total++;
        }
        l=n-k-1;
        j=n-1;
        stack < char > b;
        while(i<=j){
            // s[l]=num[j];
            s=num[j]+s;
            b.push(num[j]);
            j--;
            l--;
        }
        
        // string t="";
        while(!a.empty()){
            // if(a.top() !='0' ){
            //     t=a.top()+t;
            // }
            b.push(a.top());
            a.pop();
        }
        string t="";
        bool tr=false;
        while(!b.empty()){
            if(tr || b.top()!='0'){
                tr=true;
                t=t+b.top();
            }
            b.pop();
        }
        if(t.size()==0) return "0";
        return t;
    }
};