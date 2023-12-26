#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool zagrade(string k){
    stack<char> s;

    for(int i=0;i<k.length();i++){
        cout<<k[i]<<endl;
        if(k[i]=='(' || k[i]=='[' || k[i]=='{'){
            s.push(k[i]);
        }else if(k[i]==')'){
            if(s.empty() || s.top() != '('){
                return false;
            }else{
                s.pop();
            }
        }else if(k[i]==']'){
            if(s.empty() || s.top() !='['){
                return false;
            }else{
                s.pop();
            }
        }else if(k[i]=='}'){
            if(s.empty() || s.top() !='{'){
                return false;
            }else{
                s.pop();
            }
        }
    }
    if(s.empty()){
        return true;
    }else{
        return false;
    }
}


int main() {
    string s="()(())(())";
    string s1="()()()(()())(";
    if(zagrade(s1)){
        cout<<"da";
    }else{
        cout<<"Ne";
    }
    return 0;
}
