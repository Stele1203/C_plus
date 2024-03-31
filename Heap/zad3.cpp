struct vojniciKomparator{
    bool operator()(pair<int,int>&a, pair<int,int>&b){
        if (a.first != b.first) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    }
};


void vojnici(vector<vector<int>>matrix,int n,int m,int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>,vojniciKomparator>maxHeap;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1){
                sum++;
            }
        }
        cout<<"Suma: "<<sum<<", "<<i<<"; ";
        maxHeap.push({sum,i});
    }

    for(int i=0;i<k;i++){
        if(maxHeap.empty()){
            cout<<"Prazan heap";
            break;
        }
        cout<<maxHeap.top().second<<" ";
        maxHeap.pop();
    }
}
