struct tacka{
    int x,y;
};

struct povezane{
    int t1,t2,c;
};

int distancaTacki(int i,int j,vector<struct tacka>& tacka){
    return abs(tacka[i].x-tacka[j].x)+ abs(tacka[i].y-tacka[j].y);
}

int findRoot(int x,vector<int>&parent){
    if(parent[x]==x)
        return x;
    int root= findRoot(parent[x],parent);
    parent[x]=root;
    return root;
}


void unite(int x,int y,vector<int>& parent,vector<int>&ranks){
    int rx= findRoot(x,parent);
    int ry= findRoot(y,parent);

    if(ranks[rx]<ranks[ry])
        parent[ry]=rx;
    else if(ranks[rx]>ranks[ry])
        parent[rx]=ry;
    else{
        parent[ry]=rx;
        ranks[rx]++;
    }
}


struct compare_povezan{
    bool operator()(struct povezane& t1, struct povezane& t2){
        return t1.c>t2.c;
    }
};


int povezi_tacke(){
    int n;
    cin>>n;
    vector<struct tacka>tacke;
    vector<int>parent(n);
    vector<int>ranks(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        tacke.push_back({x,y});
        parent[i]=i;
        ranks[i]=0;

    }

    priority_queue<struct povezane,vector<struct povezane>,compare_povezan>pq;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({i,j, distancaTacki(i,j,tacke)});
        }
    }
    int s=0;
    while(!pq.empty()){
        auto t= pq.top();
        pq.pop();

        if(findRoot(t.t1,parent) != findRoot(t.t2,parent)){
            unite(t.t1,t.t2,parent,ranks);
            s+=t.c;
        }
    }
    return s;
}
