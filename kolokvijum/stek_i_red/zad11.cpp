#include <iostream>
#include <stack>
#include <string>
#include <list>
#include <cmath>
using namespace std;

void asteroidi(int* a,int n){
    stack<int>s;

    for(int i=0;i<n;i++){
        if(!s.empty() && ((s.top()<0 && a[i]>0) || (s.top()>0 && a[i]<0))){
            if(abs(s.top())<abs(a[i])){
                s.pop();
                s.push(a[i]);
            }else if(abs(a[i])== abs(s.top())){
                s.pop();
            }else if(abs(s.top())>abs(a[i])){
                continue;
            }
        }else if(s.empty()){
            s.push(a[i]);
        }
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main() {
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    asteroidi(a,n);
    return 0;
}
