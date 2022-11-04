#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s) {
    stack <char> paren;
    for (int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            paren.push(s[i]);
            // cout<<paren.top()<<endl;
        }
        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if (paren.empty()){
                string res = "NO";
                return res;
            }
            else if ( (paren.top() == '(' && s[i] == ')') || (paren.top() == '{' && s[i] == '}') || (paren.top() == '[' && s[i] == ']')){
                paren.pop();
            }
        }
    }
    if (paren.empty()){
        string res = "YES";
        return res;
    }
    else {
        string res = "NO";
        return res;
    }
}

int main(){
    int n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        cout<<isBalanced(s)<<endl;
    }
    
}
