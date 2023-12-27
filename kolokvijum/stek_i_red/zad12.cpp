#include <iostream>
#include <stack>
#include <string>
#include <list>
#include <cmath>
#include <queue>
using namespace std;

void voz(int* a, int n){
    queue<int>prvi;
    for(int i=0;i<n;i++){
        prvi.push(a[i]);
    }
    stack<int>slijepi;
    int brojac=0;
    int broj=INT_MAX;
    while(true){
        if(broj<prvi.front()){
            cout<<"Greskaaa";
            exit (1);
        }else{
            broj=prvi.front();
        }
        slijepi.push(prvi.front());
        brojac++;
        if(prvi.front()==1){
            prvi.pop();
            break;
        }else{
            prvi.pop();
        }
    }

    cout<<"1 "<<brojac<<endl;
    brojac=0;
    int broj1=slijepi.top();
    slijepi.pop();
    brojac++;
    while(!slijepi.empty()){
        if(slijepi.top() != broj1+1){
            break;
        }
        broj1=slijepi.top();
        slijepi.pop();
        brojac++;
    }
    cout<<"2 "<<brojac<<endl;
    brojac=0;
    while(!prvi.empty()){
        broj1=prvi.front();
        prvi.pop();
        if(broj1<prvi.front()){
            cout<<"greska";
            exit (2);
        }
        slijepi.push(broj1);
        brojac++;

    }
    cout<<"1 "<<brojac<<endl;
    brojac=0;
    while(!slijepi.empty()){
        slijepi.pop();
        brojac++;
    }

    cout<<"2 "<<brojac<<endl;
}


int main() {
    int n;
    cin>>n;
    int* a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    voz(a,n);
    return 0;
}
