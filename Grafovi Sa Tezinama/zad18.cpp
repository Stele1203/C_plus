vector<int> dijaksta(const vector<vector<int>>& graf, int start) {
    int n = graf.size();
    vector<int> distance(n, INT_MAX);
    vector<bool> posjecen(n, false);

    distance[start] = 0;

    while(true){
        int trenutni = -1;
        int minDist = 1<<30;
        for(int i=0; i<graf.size(); i++){
            if(posjecen[i]==false && distance[i]<minDist){
                trenutni = i;
                minDist = distance[i];
            }
        }

        if(trenutni==-1)
            break;

        posjecen[trenutni] = true;
        for(int i=0; i<graf.size(); i++){
            if(posjecen[i]==false && graf[trenutni][i]!=-1000){
                if(distance[i]>distance[trenutni]+graf[trenutni][i]){
                    distance[i] = distance[trenutni]+graf[trenutni][i];
                }
            }
        }
    }

    return distance;
}

struct ulica{
    int x,y,l;
};
int gradskaSaogracajnica(){
    int n,m,s,t,k;
    cin>>n>>m>>s>>t>>k;
    s--;
    t--;
    vector<vector<int>>graf(n,vector<int>(n,-1000));
    for(int i=0;i<m;i++){
        int x,y,l;
        cin>>x>>y>>l;
        graf[x-1][y-1]=l;
        graf[y-1][x-1]=l;
    }
    cout<<"aaaaaaaaaaaaaa";


    queue<struct ulica>red;

    for(int i=0;i<k;i++){
        int x,y,l;
        cin>>x>>y>>l;
        red.push({x-1,y-1,l});
    }

    int min=INT_MAX;
    while (!red.empty()){
        auto tmp=red.front();
        red.pop();
        int tmp1=graf[tmp.x][tmp.y];
        int tmp2=graf[tmp.y][tmp.x];
        graf[tmp.y][tmp.x]=-1000;
        graf[tmp.x][tmp.y]=tmp.l;
        vector<int>d= dijaksta(graf,s);
        cout<<d[t]<<" "<<endl;
        if(min>d[t]){
            min=d[t];
        }

        graf[tmp.x][tmp.y]=tmp1;
        graf[tmp.y][tmp.x]=tmp2;
    }

    return min;
}
