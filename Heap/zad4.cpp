struct genomComparator{
    bool operator()(pair<string,int>& a, pair<string,int>&b){
        return a.second>b.second;
    }
};


void genom(string s,int n,int k){
    unordered_map<string,int> mapa;

    priority_queue<pair<string,int>,vector<pair<string,int>>,genomComparator> g;

    for(int i=0;i<s.length()-n;i++){
        string podstring=s.substr(i,n);
        mapa[podstring]++;
    }

    for(auto& entry:mapa){
        g.push(entry);
        if(g.size()>k){
            g.pop();
        }
    }

    while(!g.empty()){
        cout<<g.top().first<<" "<<g.top().second<<": ";
        g.pop();
    }

}
