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




struct zgrada{
    int x,y;
};

struct povezaneZgrade{
    int t1,t2;
    float c;
};

float distanceBuild(int i,int j,vector<struct zgrada> tacke){
    return sqrt(pow(tacke[i].x-tacke[j].x,2)+pow(tacke[i].y-tacke[j].y,2));
}

struct buildingCompartora{
    bool operator()(struct povezaneZgrade& z1, struct povezaneZgrade& z2){
        return z1.c>z2.c;
    }
};


float zgrade(){
    int n,k;
    cin>>n>>k;
    vector<struct zgrada>zgrade;
    vector<int>ranks(n);
    vector<int>parents(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        zgrade.push_back({x,y});
        ranks[i]=0;
        parents[i]=i;
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        unite(x,y,parents,ranks);
    }

    priority_queue<struct povezaneZgrade,vector<struct povezaneZgrade>,buildingCompartora>pq;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pq.push({i,j, distanceBuild(i,j,zgrade)});
        }
    }

    float sum=0;

    while(!pq.empty()){
        auto tmp=pq.top();
        pq.pop();

        if(findRoot(tmp.t1,parents) != findRoot(tmp.t2,parents)){
            unite(tmp.t1,tmp.t2,parents,ranks);
            sum+=tmp.c;
        }
    }

    return round(k*sum*100)/100;

}
