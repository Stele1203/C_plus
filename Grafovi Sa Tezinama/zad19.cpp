#include <iostream>
#include "vector"
#include "queue"
using namespace std;

struct offer{
    int z1,z2,c;
};

struct compareOffers{
    bool operator()(struct offer& o1, struct offer& o2){
        return o1.c>o2.c;
    }
};


int boss(int x,vector<int>supervoizor){
    if(supervoizor[x]==x)
        return x;

    return boss(supervoizor[x],supervoizor);
}

int hijerarhija(){
    int n,m;
    cin>>n>>m;
    vector<int>supervizor(n);
    for(int i=0;i<n;i++){
        supervizor[i]=i;
    }

    priority_queue<struct offer,vector<struct offer>,compareOffers>pq;

    for(int i=0;i<m;i++){
        int x,y,c;
        cin>>x>>y>>c;
        pq.push({x,y,c});
    }

    int s=0;

    while(!pq.empty()){
        struct offer t=pq.top();
        pq.pop();

        if(boss(t.z1,supervizor) != t.z2 && boss(t.z2,supervizor)==t.z2){
            s+=t.c;
            supervizor[t.z2]=t.z1;
        }
    }
    int br=0;
    for(int i=0;i<n;i++){
        if(supervizor[i]==i)
            br++;
    }

    if(br != 1)
        return -1;

    return s;
}


int main() {
    cout<<hijerarhija();
    return 0;
}
