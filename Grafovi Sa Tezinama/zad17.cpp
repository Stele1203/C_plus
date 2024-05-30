float zad7(int start,int kraj,vector<vector<double>>graf,vector<bool>& posjecen,vector<int>& prethodni){
    if(start==kraj){
        return 1;
    }
    float max_vjv=-1;
    posjecen[start]=true;
    prethodni[start]=-1;

    for(int i=0;i<graf.size();i++){
        if(graf[start][i]>0 && !posjecen[i]){
            float tren= zad7(i,kraj,graf,posjecen,prethodni);
            if(tren*graf[start][i]>max_vjv){
                max_vjv=tren*graf[start][i];
                prethodni[start]=i;
            }
        }
    }
    posjecen[start]=false;
    return max_vjv;
}


void zad12Poziv(vector<vector<double>>graf,int start,int kraj){
    vector<int>prethodni(graf.size(),-1);
    vector<bool>posjecen(graf.size(),false);
    cout<<zad7(start,kraj,graf,posjecen,prethodni)<<endl;
    int p=start;
    cout<<start<<" ";
    while (prethodni[p] != -1){
        cout<<prethodni[p]<<" ";
        p=prethodni[p];
    }
    cout<<endl;
}
