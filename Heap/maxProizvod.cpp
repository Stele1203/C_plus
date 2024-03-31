int maxProizovd(vector<int>niz,int k){

    priority_queue<int,vector<int>,greater<int>>hip;

    for(int i=0;i<niz.size();i++){
        hip.push(niz[i]);
    }
    int proizvod=1;

    for(int i=0;i<k;i++){
        int a=hip.top()+1;
        hip.pop();
        hip.push(a);
    }

    while(!hip.empty()){
        proizvod*=hip.top();
        hip.pop();
        //cout<<proizvod<<" ";
    }

    return proizvod;
}
