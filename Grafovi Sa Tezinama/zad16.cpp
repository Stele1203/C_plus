vector<vector<int>>floyd_warshall(vector<vector<int>>&graf){
    vector<vector<int>>distanca(graf.size(),vector<int>(graf.size()));

    for(int i=0;i<graf.size();i++){
        for(int j=0;j<graf.size();j++){
            if(i==j)
                distanca[i][j]=0;
            else if(graf[i][j] != -1000)
                distanca[i][j]=graf[i][j];
            else
                distanca[i][j]=INT_MAX;
        }
    }

    for(int k=0;k<graf.size();k++){
        for(int i=0;i<graf.size();i++){
            for(int j=0;j<graf.size();j++){
                if(distanca[i][k] != INT_MAX && distanca[k][j] != INT_MAX){
                    if(distanca[i][j]>distanca[i][k]+distanca[k][j]){
                        distanca[i][j]=distanca[i][k]+distanca[k][j];
                    }
                }
            }
        }
    }
    return distanca;
}


int gradoviSaDistancom(vector<vector<int>>graf,int d){
    vector<vector<int>>gradovi= floyd_warshall(graf);
    int min=INT_MAX;
    int minIndex=INT_MAX;
    for(int i=0;i<gradovi.size();i++){
        int trenMin=0;
        for(int j=0;j<gradovi[0].size();j++){
            if(gradovi[i][j]<=4){
                trenMin++;
            }
        }
        if(trenMin<min){
            minIndex=i;
            min=trenMin;
        }
    }

    return minIndex;
}
