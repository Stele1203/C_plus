#include <iostream>
#include <stack>
#include <string>
#include <list>
using namespace std;

void prvi_veci(list<int> l){
    stack<pair<int,int>>s;
    int* novi= new int[l.size()];
    int i=0;

    for(int x:l){
        while(!s.empty() && s.top().first<x){
            novi[s.top().second]=x;
            s.pop();
        }
        s.push({x,i});
        i++;
    }

    while(!s.empty()){
        novi[s.top().second]=0;
        s.pop();
    }

    for(int i=0;i<l.size();i++){
        cout<<novi[i]<<" ";
    }
    delete[] novi;
}

int main() {
    list<int>l;
    l.push_back(2);
    l.push_back(7);
    l.push_back(4);
    l.push_back(3);
    l.push_back(5);
    prvi_veci(l);
    return 0;
}
