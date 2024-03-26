void najbogatiji(vector<vector<double>>matrix,int n,int m,int k){

    priority_queue<pair<double,int>,vector<pair<double,int>>,less<pair<double,int>>>maxHeap;

    for(int j=0;j<m;j++){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=matrix[i][j];
            //cout<<"suma"<<matrix[i][j]<<" ";
        }
        //cout<<endl;
        maxHeap.push({sum,j});
    }
    for (int j = 0; j < k; j++) {
        if (maxHeap.empty()) {
            cout << "Nema dovoljno osoba u redu." << endl;
            break;
        }
        pair<int, double> osoba = maxHeap.top();
        maxHeap.pop();
        cout << osoba.second; // Ispisujemo indeks osobe
        if (j < k - 1) cout << " ";
    }
}
