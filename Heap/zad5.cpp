void restoran(vector<int>& ocene){
    priority_queue<int,vector<int>,less<int>>hip;
    int n= floor(ocene.size()/3);

    for(int i=0;i<ocene.size();i++){
        hip.push(ocene[i]);
    }

    for(int i=0;i<n;i++){
        cout<<hip.top()<<" ";
        hip.pop();
    }
}
